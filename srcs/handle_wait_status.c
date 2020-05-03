/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wait_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:09:50 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/03 19:27:57 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

extern	t_ft_strace_syscall				g_syscall_table_32[384];

extern	t_ft_strace_syscall				g_syscall_table_64[329];

extern	t_ft_strace_opts				*g_ft_strace_opts;

extern	t_ft_strace_syscall_exec_info	***g_ft_strace_exec_infos;

static int		handle_sig_exit(int exit_code)
{
	size_t		table32_size = 384;
	size_t		table64_size = 314;

	if (g_ft_strace_opts->c)
		show_calls_summary(table32_size, g_syscall_table_32, \
			table64_size, g_syscall_table_64, \
			g_ft_strace_exec_infos);
	if (exit_code == SIGSEGV)
		dprintf(ERR_FD, "Segmentation fault\n");
	exit(exit_code);
}

/*
** https://sites.uclouvain.be/SystInfo/usr/include/bits/siginfo.h.html
*/

static char 	*str_sicode(int si_signo, int si_code)
{
	char	*user_sigcodes[] = {
		#include "./user_sigcodes.fmt.h"
	};
	char	*sigbus_codes[] = {
		#include "./sigbus_codes_fmt.h"
	};
	char	*sigchld_codes[] = {
		#include "./sigchld_codes_fmt.h"
	};
	char	*sigfpe_codes[] = {
		#include "./sigfpe_codes_fmt.h"
	};
	char	*sigill_codes[] = {
		#include "./sigill_codes_fmt.h"
	};
	char	*sigpoll_codes[] = {
		#include "./sigpoll_codes_fmt.h"
	};
	char	*sigsegv_codes[] = {
		#include "./sigsegv_codes_fmt.h"
	};
	char	*sigtrap_codes[] = {
		#include "./sigtrap_codes_fmt.h"
	};

	if (si_code <= 0)
		return (user_sigcodes[-si_code]);
	if (si_signo == SIGBUS)
		return (sigbus_codes[si_code]);
	if (si_signo == SIGCHLD)
		return (sigchld_codes[si_code]);
	if (si_signo == SIGFPE)
		return (sigfpe_codes[si_code]);
	if (si_signo == SIGILL)
		return (sigill_codes[si_code]);
	if (si_signo == SIGPOLL)
		return (sigpoll_codes[si_code]);
	if (si_signo == SIGSEGV)
		return (sigsegv_codes[si_code]);
	if (si_signo == SIGTRAP)
		return (sigtrap_codes[si_code]);
	return ("UNKNOWN");
}


static void	cont_syscall_sig(pid_t child, int *status, void *ptrace_syscall_data)
{
	if ((ptrace(PTRACE_SYSCALL, child, NULL, ptrace_syscall_data)) < 0)
	{
		perror("ptrace");
		exit(EXIT_FAILURE);
	}
	allow_sigs();
	if ((waitpid(child, status, 0)) < 0)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	block_sigs();
}

static int	handle_syscall_sig(pid_t child, unsigned char bin_elf_class, \
				int *status, siginfo_t *status_siginfo)
{
	struct user_regs_struct	user_regs;
	t_ft_strace_syscall		*table;
	size_t					table_size;
	int						printed;

	table = (bin_elf_class == ELFCLASS64) ? \
		(g_syscall_table_64) : (g_syscall_table_32);
	table_size = (bin_elf_class == ELFCLASS64) ? \
		(sizeof(g_syscall_table_64) / sizeof(g_syscall_table_64[0])) : \
		(sizeof(g_syscall_table_32) / sizeof(g_syscall_table_32[0]));
	while (1)
	{
		cont_syscall_sig(child, status, (void *)status_siginfo->si_signo);
		ptrace(PTRACE_GETREGS, child, NULL, &user_regs);
		if (user_regs.orig_rax > table_size)
			break ;
		if (!g_ft_strace_opts->c && \
				!(printed = print_syscall_info(child, PRE_SYSCALL_REGS, \
				bin_elf_class, &user_regs, table, 0, 6)))
				return (1);
		cont_syscall_sig(child, status, (void *)status_siginfo->si_signo);
		ptrace(PTRACE_GETREGS, child, NULL, &user_regs);
		if (!g_ft_strace_opts->c && \
				!(printed += print_syscall_info(child, POST_SYSCALL_REGS, \
				bin_elf_class, &user_regs, table, 0, 6)))
				return (1);
	}
	return (0);
}

/*
** siginfo_t struct refrence: https://docs.huihoo.com/doxygen/linux/kernel/3.7/structsiginfo.html
*/

static int	handle_stopped_status(pid_t child, unsigned char bin_elf_class, int *status)
{
	siginfo_t		status_siginfo;

	// printf("++++ Stopped code: \n");
	ptrace(PTRACE_GETSIGINFO, child, NULL, &status_siginfo);
	if (status_siginfo.si_signo == SIGTRAP)
		return (0);
	if (status_siginfo.si_signo == SIGCHLD)
	{
		if (!g_ft_strace_opts->c)
			dprintf(INFO_FD, \
				"--- SIG%s {si_signo=SIG%s, si_code=%s, si_pid=%d, si_uid=%d, si_status=%d, si_utime=%ld, si_stime=%ld} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code), \
				status_siginfo.si_pid, status_siginfo.si_uid, status_siginfo.si_status, \
				status_siginfo.si_utime, status_siginfo.si_stime);
	}
	else if (status_siginfo.si_signo == SIGSEGV)
	{
		if (!g_ft_strace_opts->c)
		{
			dprintf(INFO_FD, \
				"--- SIG%s {si_signo=SIG%s, si_code=%s, si_addr=%p} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code), status_siginfo.si_addr);
			dprintf(INFO_FD, "+++ killed by SIG%s +++\n", str_signo(status_siginfo.si_signo));
		}
		handle_sig_exit(status_siginfo.si_signo);
	}
	else if (status_siginfo.si_signo == SIGINT || \
		status_siginfo.si_signo == SIGTSTP || \
		status_siginfo.si_signo == SIGCONT)
	{
		if (!g_ft_strace_opts->c)
			dprintf(INFO_FD, "--- SIG%s {si_signo=SIG%s, si_code=%s} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code));
	}
	else
	{
		if (!g_ft_strace_opts->c)
			dprintf(INFO_FD, "--- SIG%s {si_signo=SIG%s, si_code=%s, si_pid=%d, si_uid=%d} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code), \
				status_siginfo.si_pid, status_siginfo.si_uid);
		if (status_siginfo.si_signo == SIGWINCH)
			handle_syscall_sig(child, bin_elf_class, status, &status_siginfo);
	}
	return (status_siginfo.si_signo);
}

/*
** WIFEXTED status: https://www.geeksforgeeks.org/exit-status-child-process-linux/
**
** PTRACE_GETSIGINFO:
** Signaux & ptrace()
** Un processus trac´e est stopp´e `a la r´eception de chaque signal.
** Pour le tra¸ceur, l’arrˆet semble ˆetre dˆu `a un SIGTRAP.
** L’option PTRACE_GETSIGINFO permet d’en connaˆıtre plus sur la
** raison de la notification
**
** waitpid macro int WSTOPSIG (int status):
** If WIFSTOPPED is true of status, this macro returns
** the signal number of the signal that caused the child process to stop.
**
** https://stackoverflow.com/questions/5294870/exit-status-code-4479
*/

int		handle_wait_status(pid_t child, unsigned char bin_elf_class, int status)
{
	char			*sig_fmt;

	(void)child;
	if (WIFEXITED(status))
	{
		if (!g_ft_strace_opts->c)
			dprintf(INFO_FD, "+++ exited with %d +++\n", WEXITSTATUS(status));
		handle_sig_exit(1);
	}
	if (WIFSIGNALED(status))
	{
		if (!g_ft_strace_opts->c)
		{
			sig_fmt = str_signo(status);
			dprintf(INFO_FD, "+++ killed by SIG%s +++\n", sig_fmt);
		}
		handle_sig_exit(2);
	}
	if (WIFSTOPPED(status))
	{
		if (WSTOPSIG(status) == (SIGTRAP | 0x80))
			return (0);
		handle_stopped_status(child, bin_elf_class, &status);
	}
	return (1);
}
