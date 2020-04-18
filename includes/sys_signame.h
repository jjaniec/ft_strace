/*
** https://github.com/stefwalter/util-linux/blob/master/misc-utils/kill.c
*/

/* POSIX signals */
[ 1] = "HUP", /* 1 */
[ 2] = "INT", /* 2 */
[ 3] = "QUIT", /* 3 */
[ 4] = "ILL", /* 4 */
#ifdef SIGTRAP
[ 5] = "TRAP", /* 5 */
#endif
[ 6] = "ABRT", /* 6 */
#ifdef SIGIOT
[ 6] = "IOT", /* 6, same as SIGABRT */
#endif
#ifdef SIGEMT
[ 7] = "EMT", /* 7 (mips,alpha,sparc*) */
#endif
#ifdef SIGBUS
[ 7] = "BUS", /* 7 (arm,i386,m68k,ppc), 10 (mips,alpha,sparc*) */
#endif
[ 8] = "FPE", /* 8 */
[ 9] = "KILL", /* 9 */
[10] = "USR1", /* 10 (arm,i386,m68k,ppc), 30 (alpha,sparc*), 16 (mips) */
[11] = "SEGV", /* 11 */
[12] = "USR2", /* 12 (arm,i386,m68k,ppc), 31 (alpha,sparc*), 17 (mips) */
[13] = "PIPE", /* 13 */
[14] = "ALRM", /* 14 */
[15] = "TERM", /* 15 */
#ifdef SIGSTKFLT
[16] = "STKFLT", /* 16 (arm,i386,m68k,ppc) */
#endif
[17] = "CHLD", /* 17 (arm,i386,m68k,ppc), 20 (alpha,sparc*), 18 (mips) */
#ifdef SIGCLD
[18] = "CLD", /* same as SIGCHLD (mips) */
#endif
[18] = "CONT", /* 18 (arm,i386,m68k,ppc), 19 (alpha,sparc*), 25 (mips) */
[19] = "STOP", /* 19 (arm,i386,m68k,ppc), 17 (alpha,sparc*), 23 (mips) */
[20] = "TSTP", /* 20 (arm,i386,m68k,ppc), 18 (alpha,sparc*), 24 (mips) */
[21] = "TTIN", /* 21 (arm,i386,m68k,ppc,alpha,sparc*), 26 (mips) */
[22] = "TTOU", /* 22 (arm,i386,m68k,ppc,alpha,sparc*), 27 (mips) */
#ifdef SIGURG
[23] = "URG", /* 23 (arm,i386,m68k,ppc), 16 (alpha,sparc*), 21 (mips) */
#endif
#ifdef SIGXCPU
[24] = "XCPU", /* 24 (arm,i386,m68k,ppc,alpha,sparc*), 30 (mips) */
#endif
#ifdef SIGXFSZ
[25] = "XFSZ", /* 25 (arm,i386,m68k,ppc,alpha,sparc*), 31 (mips) */
#endif
#ifdef SIGVTALRM
[26] = "VTALRM", /* 26 (arm,i386,m68k,ppc,alpha,sparc*), 28 (mips) */
#endif
#ifdef SIGPROF
[27] = "PROF", /* 27 (arm,i386,m68k,ppc,alpha,sparc*), 29 (mips) */
#endif
#ifdef SIGWINCH
[28] = "WINCH", /* 28 (arm,i386,m68k,ppc,alpha,sparc*), 20 (mips) */
#endif
#ifdef SIGIO
[29] = "IO",	 /* 29 (arm,i386,m68k,ppc), 23 (alpha,sparc*), 22 (mips) */
#endif
#ifdef SIGPOLL
[30] = "POLL", /* same as SIGIO */
#endif
#ifdef SIGINFO
[29] = "INFO", /* 29 (alpha) */
#endif
#ifdef SIGLOST
[29] = "LOST", /* 29 (arm,i386,m68k,ppc,sparc*) */
#endif
#ifdef SIGPWR
[30] = "PWR", /* 30 (arm,i386,m68k,ppc), 29 (alpha,sparc*), 19 (mips) */
#endif
#ifdef SIGUNUSED
[31] = "UNUSED", /* 31 (arm,i386,m68k,ppc) */
#endif
#ifdef SIGSYS
[31] = "SYS", /* 31 (mips,alpha,sparc*) */
#endif

/*
** SIGRTMIN to STGRTMAX
** http://man7.org/linux/man-pages/man7/signal.7.html
** If SIGRTMIN & SIGRTMAX macros has been changed add SIGRT strings here
*/

[34] = "RTMIN",
[35] = "RT_1"
// ...
