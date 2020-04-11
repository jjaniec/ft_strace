/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wait_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:09:50 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/11 19:14:00 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char		*sys_signame[] = {
	#include "./sys_signame.h"
};

static char		*str_signo(int sig)
{
	return (sys_signame[sig]);
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

/*
** siginfo_t struct refrence: https://docs.huihoo.com/doxygen/linux/kernel/3.7/structsiginfo.html
*/

static int	handle_stopped_status(pid_t child)
{
	siginfo_t		status_siginfo;

	// printf("++++ Stopped code: \n");
	ptrace(PTRACE_GETSIGINFO, child, NULL, &status_siginfo);
	if (status_siginfo.si_signo == SIGTRAP)
		return (0);
	if (status_siginfo.si_signo == SIGCHLD)
	{
		dprintf(STDOUT_FILENO, \
			"--- SIG%s {si_signo=SIG%s, si_code=%s, si_pid=%d, si_uid=%d, si_status=%d, si_utime=%ld, si_stime=%ld} ---\n", \
			str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
			str_sicode(status_siginfo.si_signo, status_siginfo.si_code), \
			status_siginfo.si_pid, status_siginfo.si_uid, status_siginfo.si_status, \
			status_siginfo.si_utime, status_siginfo.si_stime);
	}
	else if (status_siginfo.si_signo == SIGSEGV)
	{
		dprintf(STDOUT_FILENO, \
			"--- SIG%s {si_signo=SIG%s, si_code=%s, si_addr=%p} ---\n", \
			str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
			str_sicode(status_siginfo.si_signo, status_siginfo.si_code), status_siginfo.si_addr);
	}
	else if (status_siginfo.si_signo == SIGINT || \
		status_siginfo.si_signo == SIGTSTP || \
		status_siginfo.si_signo == SIGCONT)
	{
		dprintf(STDOUT_FILENO, "--- SIG%s {si_signo=SIG%s, si_code=%s} ---\n", \
			str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
			str_sicode(status_siginfo.si_signo, status_siginfo.si_code));
	}
	else
	{
		dprintf(STDOUT_FILENO, "--- SIG%s {si_signo=SIG%s, si_code=%s, si_pid=%d, si_uid=%d} ---\n", \
			str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
			str_sicode(status_siginfo.si_signo, status_siginfo.si_code), \
			status_siginfo.si_pid, status_siginfo.si_uid);
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
*/

int		handle_wait_status(pid_t child, int status)
{
	int				r;
	char			*sig_fmt;

	(void)child;
	r = 0;
	// printf("SIG status %d\n", status);
	if (WIFEXITED(status))
	{
		dprintf(STDOUT_FILENO, "+++ Exited with %d +++\n", WEXITSTATUS(status));
		r = 1;
	}
	else if (WIFSIGNALED(status))
	{
		sig_fmt = str_signo(status);
		dprintf(STDOUT_FILENO, "+++ Killed by SIG%s +++\n", sig_fmt);
		r = 2;
	}
	if (WIFSTOPPED(status))
		handle_stopped_status(child);
	// fflush(stdout);
	return (r);
}
