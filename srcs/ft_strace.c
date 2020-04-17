/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:08:56 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/17 20:26:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

t_ft_strace_syscall	g_syscall_table_64[] = {
	#include "syscall_table_64.h"
};

t_ft_strace_syscall	g_syscall_table_32[] = {
	#include "syscall_table_32.h"
};

t_ft_strace_opts	*g_ft_strace_opts;

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
** Set ptrace options & read user section to gather syscall numbers & parameters
**
** PTRACE_GETREGS, PTRACE_GETFPREGS:
** Copy the tracee's general-purpose or floating-point registers,
** respectively, to the address data in the tracer.
**
** waitpid macro int WSTOPSIG (int status):
** If WIFSTOPPED is true of status, this macro returns
** the signal number of the signal that caused the child process to stop.
*/

static int		allow_sigs(void)
{
	sigset_t	sigmask;

	if (sigemptyset(&sigmask) < 0)
	{
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}
	if (sigprocmask(SIG_SETMASK, &sigmask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int		block_sigs(void)
{
	sigset_t	sigmask;

	if (sigemptyset(&sigmask) < 0)
	{
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}
	if (sigaddset(&sigmask, SIGINT) < 0 || \
		sigaddset(&sigmask, SIGQUIT) < 0 || \
		sigaddset(&sigmask, SIGTERM) < 0 || \
		sigaddset(&sigmask, SIGHUP) < 0 || \
		sigaddset(&sigmask, SIGPIPE) < 0)
	{
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}
	if (sigprocmask(SIG_BLOCK, &sigmask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	cont_process(pid_t process, int *status, struct user_regs_struct *user_regs)
{
	pid_t	waited;

	while (1)
	{
		if (ptrace(PTRACE_SYSCALL, process, 0, 0) < 0)
		{
			perror("ptrace");
			exit(EXIT_FAILURE);
		}
		allow_sigs();
		if (waitpid(process, status, 0) < 0)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		block_sigs();
		if (handle_wait_status(process, *status) == 0)
			break ;
	}
	if (ptrace(PTRACE_GETREGS, process, 0, user_regs) < 0)
	{
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	return (0);
}

/*
** Update call & error count of last syscall
*/

static int		update_syscall_exec_infos(t_ft_strace_syscall *table, \
					t_ft_strace_syscall_exec_info *exec_infos, \
					struct user_regs_struct *post_user_regs)
{
	exec_infos[post_user_regs->orig_rax].calls++;
	if (table[post_user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)post_user_regs->rax && (int)post_user_regs->rax <= -1))
	{
		exec_infos[post_user_regs->orig_rax].errors++;
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
** PTRACE_SYSCALL, PTRACE_SINGLESTEP:
** Restart the stopped tracee as for PTRACE_CONT, but arrange for
** the tracee to be stopped at the next entry to or exit from a
** system call, or after execution of a single instruction,
** respectively.  (The tracee will also, as usual, be stopped
** upon receipt of a signal.)  From the tracer's perspective, the
** tracee will appear to have been stopped by receipt of a SIG‐
** TRAP.
**
** PTRACE_CONT:
** Restart the stopped tracee process.
*/

static int	init_ptrace(pid_t child, int *status)
{
	if (ptrace(PTRACE_SEIZE, child, NULL, 0) < 0)
	{
		dprintf(ERR_FD, "PTRACE_SEIZE");
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	allow_sigs();
	if (waitpid(child, status, 0) < 0)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	block_sigs();
	ptrace(PTRACE_SETOPTIONS, child, NULL, PTRACE_O_TRACESYSGOOD);
}

static int	handle_child(unsigned char bin_elf_class, t_ft_strace_opts *opts, pid_t child)
{
	struct user_regs_struct			pre_user_regs;
	struct user_regs_struct			post_user_regs;
	int 							status;
	t_ft_strace_syscall				*table;
	t_ft_strace_syscall_exec_info	*exec_infos;
	size_t							table_size;


	if (bin_elf_class == ELFCLASS32)
	{
		table = g_syscall_table_32;
		table_size = sizeof(g_syscall_table_32) / sizeof(g_syscall_table_32[0]);
	}
	else if (bin_elf_class == ELFCLASS64)
	{
		table = g_syscall_table_64;
		table_size = sizeof(g_syscall_table_64) / sizeof(g_syscall_table_64[0]);
	}
	else
		exit(EXIT_FAILURE);
	// printf("%d ELF Class: %x - 32: %x - 64: %x\n", child, bin_elf_class, ELFCLASS32, ELFCLASS64);
	init_ptrace(child, &status);
	if (opts->c)
	{
		exec_infos = ft_xmalloc(sizeof(t_ft_strace_syscall_exec_info) * table_size);
		ft_memset(exec_infos, 0, sizeof(t_ft_strace_syscall_exec_info) * table_size);
	}
	dprintf(OK_FD, OK_PREFIX "Child pid: %d\n", child);
	while (1 || opts->d != 0)
	{
		if (cont_process(child, &status, &pre_user_regs) || \
			print_syscall_info(child, PRE_SYSCALL_REGS, bin_elf_class, &pre_user_regs, table) || \
			cont_process(child, &status, &post_user_regs) || \
			print_syscall_info(child, POST_SYSCALL_REGS, bin_elf_class, &post_user_regs, table))
			break ;
		if (opts->c)
			update_syscall_exec_infos(table, exec_infos, &post_user_regs);
	}
	if (opts->c)
	{
		show_calls_summary(table, table_size, exec_infos);
		free(exec_infos);
	}
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
