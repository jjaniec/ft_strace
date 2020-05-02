/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:08:56 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/02 18:36:09 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

t_ft_strace_syscall				g_syscall_table_64[] = {
	#include "syscall_table_64.h"
};

t_ft_strace_syscall				g_syscall_table_32[] = {
	#include "syscall_table_32.h"
};

t_ft_strace_opts				*g_ft_strace_opts;

t_ft_strace_syscall_exec_info	***g_ft_strace_exec_infos;

/*
** Handle execve errors with errno codes
*/

static int	handle_execve_err(void)
{
	// perror("execve");
	dprintf(ERR_FD, ERR_PREFIX "%s\n", ft_strerror(errno));
	exit(EXIT_FAILURE);
}

/*
** Tell ptrace to trace the process and start the program passed as arguments
*/

static void	child_process_tasks(char *exec_path, char **exec_args, char **exec_environ)
{
	kill(getpid(), SIGSTOP);
	if (execve(exec_path, exec_args, exec_environ) == -1)
		handle_execve_err();
}

/*
** Update call & error count of last syscall
*/

static int		update_syscall_exec_infos(unsigned char bin_elf_class,
					t_ft_strace_syscall *table32, t_ft_strace_syscall *table64, \
					t_ft_strace_syscall_exec_info **exec_infos, \
					struct user_regs_struct *post_user_regs)
{
	t_ft_strace_syscall	*table;

	table = (bin_elf_class == ELFCLASS32) ? (table64) : (table32);
	exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].calls++;
	if (table[post_user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)post_user_regs->rax && (int)post_user_regs->rax <= -1))
	{
		exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].errors++;
	}
	return (0);
}


/*
** PTRACE_SEIZE:
** Since Linux 3.4, PTRACE_SEIZE can be used instead of PTRACE_ATTACH.
** PTRACE_SEIZE does not stop the attached process.  If you need to stop
** it after attach (or at any other time) without sending it any sig‐
** nals, use PTRACE_INTERRUPT command.
**
** PTRACE_O_TRACESYSGOOD:
** When delivering system call traps, set bit 7 in the
** signal number (i.e., deliver SIGTRAP|0x80).  This makes
** it easy for the tracer to distinguish normal traps from
** those caused by a system call.
**
** PTRACE_CONT:
** Restart the stopped tracee process.
*/

static int	init_ptrace(pid_t child)
{
	int		status;

	if (ptrace(PTRACE_SEIZE, child, NULL, 0) < 0)
	{
		dprintf(ERR_FD, "PTRACE_SEIZE");
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	allow_sigs();
	if (waitpid(child, &status, 0) < 0)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	block_sigs();
	ptrace(PTRACE_SETOPTIONS, child, NULL, PTRACE_O_TRACESYSGOOD);
	return (0);
}

static int	handle_child(unsigned char bin_elf_class, t_ft_strace_opts *opts, pid_t child)
{
	struct user_regs_struct			pre_user_regs;
	struct user_regs_struct			post_user_regs;
	t_ft_strace_syscall				*table;
	t_ft_strace_syscall_exec_info	**exec_infos;
	int								status;

	if (bin_elf_class == ELFCLASS32)
		table = g_syscall_table_32;
	else if (bin_elf_class == ELFCLASS64)
		table = g_syscall_table_64;
	else
		exit(EXIT_FAILURE);
	init_ptrace(child);
	if (opts->c)
	{
		exec_infos = ft_xmalloc(sizeof(t_ft_strace_syscall_exec_info *) * 2);
		exec_infos[0] = ft_xmalloc(sizeof(t_ft_strace_syscall_exec_info) * sizeof(g_syscall_table_64) / sizeof(g_syscall_table_64[0]));
		ft_memset(exec_infos[0], 0, sizeof(t_ft_strace_syscall_exec_info) * sizeof(g_syscall_table_64) / sizeof(g_syscall_table_64[0]));
		if (bin_elf_class == ELFCLASS32)
		{
			exec_infos[1] = ft_xmalloc(sizeof(t_ft_strace_syscall_exec_info) * sizeof(g_syscall_table_32) / sizeof(g_syscall_table_32[0]));
			ft_memset(exec_infos[1], 0, sizeof(t_ft_strace_syscall_exec_info) * sizeof(g_syscall_table_32) / sizeof(g_syscall_table_32[0]));
		}
		else
			exec_infos[1] = NULL;
		g_ft_strace_exec_infos = &exec_infos;
	}
	// dprintf(OK_FD, OK_PREFIX "Child pid: %d\n", child);
	if (!handle_next_syscall(child, ELFCLASS64, &status, g_syscall_table_64, &pre_user_regs, &post_user_regs))
	{
		if (bin_elf_class == ELFCLASS32)
			dprintf(INFO_FD, "ft_strace: [ Process PID=%d runs in 32 bit mode. ]\n", child);
		if (opts->c)
			update_syscall_exec_infos(ELFCLASS64, g_syscall_table_32, g_syscall_table_64, \
				exec_infos, &post_user_regs);
		while ("42 and beyond")
		{
			if (handle_next_syscall(child, bin_elf_class, &status, \
				table, &pre_user_regs, &post_user_regs))
				break ;
			if (opts->c)
				update_syscall_exec_infos(bin_elf_class, g_syscall_table_32, g_syscall_table_64, \
					exec_infos, &post_user_regs);
		}
	}
	if (opts->c && *g_ft_strace_exec_infos)
		show_calls_summary(sizeof(g_syscall_table_32) / sizeof(g_syscall_table_32[0]), g_syscall_table_32, \
			sizeof(g_syscall_table_64) / sizeof(g_syscall_table_64[0]), g_syscall_table_64, \
			&exec_infos);
	handle_wait_status(child, status);
	return (1);
}

/*
** Fork, start the program passed as arguments in the child process
** and monitor the child in the main process
*/

int			ft_strace(t_ft_strace_opts *opts, char *exec_path, char **exec_args, char **exec_environ)
{
	pid_t			child;
	unsigned char	bin_elf_class;

	bin_elf_class = get_binary_architecture(exec_path);
	g_ft_strace_opts = opts;
	if ((child = fork()) == -1)
	{
		write(STDERR_FILENO, ERR_PREFIX "Fork failed!\n", ft_strlen(ERR_PREFIX) + 13);
		return (1);
	}
	if (child)
	{
		return (handle_child(bin_elf_class, opts, child));
	}
	child_process_tasks(exec_path, exec_args, exec_environ);
	return (0);
}
