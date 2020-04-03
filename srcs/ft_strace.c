/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:08:56 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/03 20:25:53 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Handle execve errors with errno codes
*/

static int	handle_execve_err(void)
{
	if (errno == EACCES)
		write(STDERR_FILENO, ERR_PREFIX "Execution failed (EACCESS)\n", \
			ft_strlen(ERR_PREFIX) + 27);
	exit(1);
}

/*
** Tell ptrace to trace the process and start the program passed as arguments
*/

static int	child_process_tasks(char *exec_path, char **exec_args, char **exec_environ)
{
	raise(SIGSTOP);
	if (execve(exec_path, exec_args, exec_environ) == -1)
		return (handle_execve_err());
	return (1);
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

static int	cont_process(pid_t process, int *status, struct user_regs_struct *user_regs)
{
	ptrace(PTRACE_SYSCALL, process, 0, 0);
	waitpid(process, status, 0);
	if (WSTOPSIG(*status) & (SIGTRAP | 0x80))
	{
		ptrace(PTRACE_GETREGS, process, 0, user_regs);
		return (0);
	}
	if (WIFEXITED(*status))
		return (1);
	return (2);
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

static int	handle_child(t_ft_strace_opts *opts, pid_t child)
{
	struct user_regs_struct		pre_user_regs;
	struct user_regs_struct		post_user_regs;
	int 						status;

	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
	ptrace(PTRACE_INTERRUPT, child, 0, 0);
	if (!opts->c)
	{
		ptrace(PTRACE_SYSCALL, child, 0, 0);
		waitpid(child, &status, 0);
	}
	while (opts->c != 0)
	{
		if (cont_process(child, &status, &pre_user_regs) || \
			cont_process(child, &status, &post_user_regs))
			break ;
		print_syscall_info(child, &pre_user_regs, &post_user_regs);
		opts->c--;
	}
	if (!opts->c)
	{
		ptrace(PTRACE_CONT, child, 0, 0);
		waitpid(child, &status, 0);
	}
	if (WIFEXITED(status))
		ft_printf(INFO_PREFIX "[%d] exited with %d\n", child, status);
	return (1);
}

/*
** Apply sigmask to block
*/

static int			init_sigs(void)
{
	sigset_t	sigmask;

	sigemptyset(&sigmask);
	sigprocmask(SIG_SETMASK, &sigmask, NULL);
	sigaddset(&sigmask, SIGINT);
	sigaddset(&sigmask, SIGQUIT);
	sigaddset(&sigmask, SIGTERM);
	sigaddset(&sigmask, SIGHUP);
	sigaddset(&sigmask, SIGPIPE);
	sigprocmask(SIG_BLOCK, &sigmask, NULL);
	return (0);
}

/*
** Fork, start the program passed as arguments in the child process
** and monitor the child in the main process
*/

int			ft_strace(t_ft_strace_opts *opts, char *exec_path, char **exec_args, char **exec_environ)
{
	pid_t	child;

	init_sigs();
	if ((child = fork()) == -1)
	{
		write(STDERR_FILENO, ERR_PREFIX "Fork failed!\n", ft_strlen(ERR_PREFIX) + 13);
		return (1);
	}
	if (child)
	{
		ft_printf(OK_PREFIX "Child pid: %d\n", child);
		return (handle_child(opts, child));
	}
	return (child_process_tasks(exec_path, exec_args, exec_environ));

}
