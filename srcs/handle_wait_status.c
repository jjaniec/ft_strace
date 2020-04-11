/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wait_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:09:50 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/11 15:52:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

const char	*sys_signame[] = {
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

// extern const char 	*const sys_signame[];

static char		*str_signo(int sig)
{
	char		*s;

	s = ft_strdup(sys_signame[sig]);
	ft_str_capitalize(s);
	return (s);
}

/*
** WIFEXTED status: https://www.geeksforgeeks.org/exit-status-child-process-linux/
*/

int		handle_wait_status(pid_t child, int status)
{
	int		r;
	char	*sig;

	(void)child;
	r = 0;
	if (WIFEXITED(status))
	{
		dprintf(STDOUT_FILENO, "+++ Exited with %d +++\n", WEXITSTATUS(status));
		r = 1;
	}
	else if (WIFSIGNALED(status))
	{
		sig = str_signo(status);
		dprintf(STDOUT_FILENO, "+++ Killed by SIG%s +++\n", sig);
		free(sig);
		r = 2;
	}
	// else if ()
	// {

	// 	r = 3;
	// }
	return (r);
}
