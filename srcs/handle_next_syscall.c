/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_next_syscall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 20:22:46 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/23 16:17:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

extern t_ft_strace_opts		*g_ft_strace_opts;

/*
** Read user section to gather syscall numbers & parameters
**
** PTRACE_GETREGS, PTRACE_GETFPREGS:
** Copy the tracee's general-purpose or floating-point registers,
** respectively, to the address data in the tracer.
**
** PTRACE_SYSCALL, PTRACE_SINGLESTEP:
** Restart the stopped tracee as for PTRACE_CONT, but arrange for
** the tracee to be stopped at the next entry to or exit from a
** system call, or after execution of a single instruction,
** respectively.  (The tracee will also, as usual, be stopped
** upon receipt of a signal.)  From the tracer's perspective, the
** tracee will appear to have been stopped by receipt of a SIG‐
** TRAP.
*/

static int	cont_process(pid_t process, int *status, struct user_regs_struct *user_regs)
{
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
		if (WIFEXITED(*status) || WIFSIGNALED(*status))
			return (1);
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

int			handle_next_syscall(pid_t child, unsigned char bin_elf_class, \
				int *status, t_ft_strace_syscall *table, \
				struct user_regs_struct *pre_user_regs, struct user_regs_struct *post_user_regs)
{
	int		buffer_param_index;
	int		printed;

	if (cont_process(child, status, pre_user_regs))
		return (1);
	buffer_param_index = ft_int_index(table[pre_user_regs->orig_rax].reg_types, 6, BUFFER);
	if (!g_ft_strace_opts->c && \
		!(printed = print_syscall_info(child, PRE_SYSCALL_REGS, \
		bin_elf_class, pre_user_regs, table, 0, \
		(buffer_param_index == -1) ? (6) : (buffer_param_index))))
		return (1);
	if (cont_process(child, status, post_user_regs))
	{
		if (!g_ft_strace_opts->c)
			dprintf(INFO_FD, ")%*s= ?\n", \
				(printed > 40) ? (0) : (40 - printed), " ");
		return (1);
	}
	if (buffer_param_index != -1)
	{
		if (!g_ft_strace_opts->c && \
			!print_syscall_info(child, PRE_SYSCALL_REGS, bin_elf_class, pre_user_regs, table, \
			buffer_param_index, (6 - (buffer_param_index))))
			return (1);
	}
	if (!g_ft_strace_opts->c && \
		!print_syscall_info(child, POST_SYSCALL_REGS, bin_elf_class, post_user_regs, table, \
		0, 6))
		return (1);
	return (0);
}
