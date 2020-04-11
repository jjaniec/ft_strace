/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wait_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:09:50 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/11 17:47:04 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char		*sys_signame[] = {
	/* POSIX signals */
	"HUP", /* 1 */
	"INT", /* 2 */
	"QUIT", /* 3 */
	"ILL", /* 4 */
#ifdef SIGTRAP
	"TRAP", /* 5 */
#endif
	"ABRT", /* 6 */
#ifdef SIGIOT
	"IOT", /* 6, same as SIGABRT */
#endif
#ifdef SIGEMT
	"EMT", /* 7 (mips,alpha,sparc*) */
#endif
#ifdef SIGBUS
	"BUS", /* 7 (arm,i386,m68k,ppc), 10 (mips,alpha,sparc*) */
#endif
	"FPE", /* 8 */
	"KILL", /* 9 */
	"USR1", /* 10 (arm,i386,m68k,ppc), 30 (alpha,sparc*), 16 (mips) */
	"SEGV", /* 11 */
	"USR2", /* 12 (arm,i386,m68k,ppc), 31 (alpha,sparc*), 17 (mips) */
	"PIPE", /* 13 */
	"ALRM", /* 14 */
	"TERM", /* 15 */
#ifdef SIGSTKFLT
	"STKFLT", /* 16 (arm,i386,m68k,ppc) */
#endif
	"CHLD", /* 17 (arm,i386,m68k,ppc), 20 (alpha,sparc*), 18 (mips) */
#ifdef SIGCLD
	"CLD", /* same as SIGCHLD (mips) */
#endif
	"CONT", /* 18 (arm,i386,m68k,ppc), 19 (alpha,sparc*), 25 (mips) */
	"STOP", /* 19 (arm,i386,m68k,ppc), 17 (alpha,sparc*), 23 (mips) */
	"TSTP", /* 20 (arm,i386,m68k,ppc), 18 (alpha,sparc*), 24 (mips) */
	"TTIN", /* 21 (arm,i386,m68k,ppc,alpha,sparc*), 26 (mips) */
	"TTOU", /* 22 (arm,i386,m68k,ppc,alpha,sparc*), 27 (mips) */
#ifdef SIGURG
	"URG", /* 23 (arm,i386,m68k,ppc), 16 (alpha,sparc*), 21 (mips) */
#endif
#ifdef SIGXCPU
	"XCPU", /* 24 (arm,i386,m68k,ppc,alpha,sparc*), 30 (mips) */
#endif
#ifdef SIGXFSZ
	"XFSZ", /* 25 (arm,i386,m68k,ppc,alpha,sparc*), 31 (mips) */
#endif
#ifdef SIGVTALRM
	"VTALRM", /* 26 (arm,i386,m68k,ppc,alpha,sparc*), 28 (mips) */
#endif
#ifdef SIGPROF
	"PROF", /* 27 (arm,i386,m68k,ppc,alpha,sparc*), 29 (mips) */
#endif
#ifdef SIGWINCH
	"WINCH", /* 28 (arm,i386,m68k,ppc,alpha,sparc*), 20 (mips) */
#endif
#ifdef SIGIO
	"IO",	 /* 29 (arm,i386,m68k,ppc), 23 (alpha,sparc*), 22 (mips) */
#endif
#ifdef SIGPOLL
	"POLL", /* same as SIGIO */
#endif
#ifdef SIGINFO
	"INFO", /* 29 (alpha) */
#endif
#ifdef SIGLOST
	"LOST", /* 29 (arm,i386,m68k,ppc,sparc*) */
#endif
#ifdef SIGPWR
	"PWR", /* 30 (arm,i386,m68k,ppc), 29 (alpha,sparc*), 19 (mips) */
#endif
#ifdef SIGUNUSED
	"UNUSED", /* 31 (arm,i386,m68k,ppc) */
#endif
#ifdef SIGSYS
	"SYS", /* 31 (mips,alpha,sparc*) */
#endif
};

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

static char		*str_signo(int sig)
{
	return (sys_signame[sig]);
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
	siginfo_t		status_siginfo;

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
	if (WIFSTOPPED(status) /* && status == SIGTRAP */)
	{
		// printf("++++ Stopped code: \n");
		ptrace(PTRACE_GETSIGINFO, child, NULL, &status_siginfo);
		if (status_siginfo.si_signo == SIGCHLD)
		{
			dprintf(STDOUT_FILENO, \
				"--- SIG%s {si_signo=SIG%s, si_code=%s, si_pid=%d, si_uid=%d, si_status=%d, si_utime=%ld, si_stime=%ld} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code), \
				status_siginfo.si_pid, status_siginfo.si_uid, status_siginfo.si_status, \
				status_siginfo.si_utime, status_siginfo.si_stime);
		}
		if (status_siginfo.si_signo == SIGSEGV)
		{
			dprintf(STDOUT_FILENO, \
				"--- SIG%s {si_signo=SIG%s, si_code=%s, si_addr=%p} ---\n", \
				str_signo(status_siginfo.si_signo), str_signo(status_siginfo.si_signo), \
				str_sicode(status_siginfo.si_signo, status_siginfo.si_code), status_siginfo.si_addr);
			r = 3;
		}
	}
	fflush(stdout);
	return (r);
}
