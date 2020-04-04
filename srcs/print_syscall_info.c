/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syscall_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:34:28 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/04 19:02:54 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

t_ft_strace_syscall	g_syscall_table_64[329] = {
	// # include "syscall64.h"
	{ "read", "sys_read", "fs/read_write.c", {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "write", "sys_write", "fs/read_write.c", {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "open", "sys_open", "fs/open.c", {STR, FLAGS, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "close", "sys_close", "fs/open.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "stat", "sys_newstat", "fs/stat.c", {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fstat", "sys_newfstat", "fs/stat.c", {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "lstat", "sys_newlstat", "fs/stat.c", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "poll", "sys_poll", "fs/select.c", {PTR, UINT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "lseek", "sys_lseek", "fs/read_write.c", {INT, LONG, INT, UNDEF, UNDEF, UNDEF}, LONG },
	{ "mmap", "sys_mmap", "arch/x86/kernel/sys_x86_64.c", {PTR, SIZE_T, PROT, MAP, INT, HEX}, PTR },
	{ "mprotect", "sys_mprotect", "mm/mprotect.c", {PTR, SIZE_T, PROT, UNDEF, UNDEF, UNDEF}, INT },
	{ "munmap", "sys_munmap", "mm/mmap.c", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "brk", "sys_brk", "mm/mmap.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
	{ "rt_sigaction", "sys_rt_sigaction", "kernel/signal.c", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "rt_sigprocmask", "sys_rt_sigprocmask", "kernel/signal.c", {INT, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT },
	{ "rt_sigreturn", "stub_rt_sigreturn", "arch/x86/kernel/signal.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ioctl", "sys_ioctl", "fs/ioctl.c", {INT, ULONG, STRUCT, UNDEF, UNDEF, UNDEF}, INT },
	{ "pread64", "sys_pread64", "fs/read_write.c", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T },
	{ "pwrite64", "sys_pwrite64", "fs/read_write.c", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T },
	{ "readv", "sys_readv", "fs/read_write.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "writev", "sys_writev", "fs/read_write.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "access", "sys_access", "fs/open.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "pipe", "sys_pipe", "fs/pipe.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "select", "sys_select", "fs/select.c", {INT, PTR, PTR, PTR, PTR, UNDEF}, INT },
	{ "sched_yield", "sys_sched_yield", "kernel/sched/core.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mremap", "sys_mremap", "mm/mmap.c", {PTR, SIZE_T, SIZE_T, INT, PTR, UNDEF}, PTR },
	{ "msync", "sys_msync", "mm/msync.c", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "mincore", "sys_mincore", "mm/mincore.c", {PTR, SIZE_T, STR, UNDEF, UNDEF, UNDEF}, INT },
	{ "madvise", "sys_madvise", "mm/madvise.c", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "shmget", "sys_shmget", "ipc/shm.c", {INT, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "shmat", "sys_shmat", "ipc/shm.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, PTR },
	{ "shmctl", "sys_shmctl", "ipc/shm.c", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "dup", "sys_dup", "fs/file.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "dup2", "sys_dup2", "fs/file.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "pause", "sys_pause", "kernel/signal.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "nanosleep", "sys_nanosleep", "kernel/hrtimer.c", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getitimer", "sys_getitimer", "kernel/itimer.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "alarm", "sys_alarm", "kernel/timer.c", {UINT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, UINT },
	{ "setitimer", "sys_setitimer", "kernel/itimer.c", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "getpid", "sys_getpid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sendfile", "sys_sendfile64", "fs/read_write.c", {INT, INT, UNDEF, LONG, UNDEF, UNDEF}, SSIZE_T },
	{ "socket", "sys_socket", "net/socket.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "connect", "sys_connect", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "accept", "sys_accept", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "sendto", "sys_sendto", "net/socket.c", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T },
	{ "recvfrom", "sys_recvfrom", "net/socket.c", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T },
	{ "sendmsg", "sys_sendmsg", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "recvmsg", "sys_recvmsg", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "shutdown", "sys_shutdown", "net/socket.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "bind", "sys_bind", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "listen", "sys_listen", "net/socket.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getsockname", "sys_getsockname", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "getpeername", "sys_getpeername", "net/socket.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "socketpair", "sys_socketpair", "net/socket.c", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
	{ "setsockopt", "sys_setsockopt", "net/socket.c", {INT, INT, INT, PTR, INT, UNDEF}, INT },
	{ "getsockopt", "sys_getsockopt", "net/socket.c", {INT, INT, INT, PTR, INT, UNDEF}, INT },
	{ "clone", "stub_clone", "kernel/fork.c", {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT },
	{ "fork", "stub_fork", "kernel/fork.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "vfork", "stub_vfork", "kernel/fork.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "execve", "stub_execve", "fs/exec.c", {STR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "exit", "sys_exit", "kernel/exit.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "wait4", "sys_wait4", "kernel/exit.c", {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT },
	{ "kill", "sys_kill", "kernel/signal.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "uname", "sys_newuname", "kernel/sys.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "semget", "sys_semget", "ipc/sem.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "semop", "sys_semop", "ipc/sem.c", {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT },
	{ "semctl", "sys_semctl", "ipc/sem.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "shmdt", "sys_shmdt", "ipc/shm.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "msgget", "sys_msgget", "ipc/msg.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "msgsnd", "sys_msgsnd", "ipc/msg.c", {INT, PTR, SIZE_T, INT, UNDEF, UNDEF}, INT },
	{ "msgrcv", "sys_msgrcv", "ipc/msg.c", {INT, PTR, SIZE_T, LONG, INT, UNDEF}, SSIZE_T },
	{ "msgctl", "sys_msgctl", "ipc/msg.c", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "fcntl", "sys_fcntl", "fs/fcntl.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "flock", "sys_flock", "fs/locks.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fsync", "sys_fsync", "fs/sync.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fdatasync", "sys_fdatasync", "fs/sync.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "truncate", "sys_truncate", "fs/open.c", {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ftruncate", "sys_ftruncate", "fs/open.c", {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getdents", "sys_getdents", "fs/readdir.c", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT },
	{ "getcwd", "sys_getcwd", "fs/dcache.c", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
	{ "chdir", "sys_chdir", "fs/open.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fchdir", "sys_fchdir", "fs/open.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "rename", "sys_rename", "fs/namei.c", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mkdir", "sys_mkdir", "fs/namei.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "rmdir", "sys_rmdir", "fs/namei.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "creat", "sys_creat", "fs/open.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "link", "sys_link", "fs/namei.c", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "unlink", "sys_unlink", "fs/namei.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "symlink", "sys_symlink", "fs/namei.c", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "readlink", "sys_readlink", "fs/stat.c", {STR, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "chmod", "sys_chmod", "fs/open.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fchmod", "sys_fchmod", "fs/open.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "chown", "sys_chown", "fs/open.c", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "fchown", "sys_fchown", "fs/open.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "lchown", "sys_lchown", "fs/open.c", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "umask", "sys_umask", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "gettimeofday", "sys_gettimeofday", "kernel/time.c", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getrlimit", "sys_getrlimit", "kernel/sys.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getrusage", "sys_getrusage", "kernel/sys.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sysinfo", "sys_sysinfo", "kernel/sys.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "times", "sys_times", "kernel/sys.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ptrace", "sys_ptrace", "kernel/ptrace.c", {LONG, INT, PTR, PTR, UNDEF, UNDEF}, LONG },
	{ "getuid", "sys_getuid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "syslog", "sys_syslog", "kernel/printk/printk.c", {INT, STR, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "getgid", "sys_getgid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setuid", "sys_setuid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setgid", "sys_setgid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "geteuid", "sys_geteuid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getegid", "sys_getegid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setpgid", "sys_setpgid", "kernel/sys.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getppid", "sys_getppid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getpgrp", "sys_getpgrp", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setsid", "sys_setsid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setreuid", "sys_setreuid", "kernel/sys.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setregid", "sys_setregid", "kernel/sys.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getgroups", "sys_getgroups", "kernel/groups.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setgroups", "sys_setgroups", "kernel/groups.c", {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setresuid", "sys_setresuid", "kernel/sys.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "getresuid", "sys_getresuid", "kernel/sys.c", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "setresgid", "sys_setresgid", "kernel/sys.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "getresgid", "sys_getresgid", "kernel/sys.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "getpgid", "sys_getpgid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setfsuid", "sys_setfsuid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setfsgid", "sys_setfsgid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getsid", "sys_getsid", "kernel/sys.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "capget", "sys_capget", "kernel/capability.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "capset", "sys_capset", "kernel/capability.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "rt_sigpending", "sys_rt_sigpending", "kernel/signal.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "rt_sigtimedwait", "sys_rt_sigtimedwait", "kernel/signal.c", {PTR, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT },
	{ "rt_sigqueueinfo", "sys_rt_sigqueueinfo", "kernel/signal.c", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "rt_sigsuspend", "sys_rt_sigsuspend", "kernel/signal.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sigaltstack", "sys_sigaltstack", "kernel/signal.c", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "utime", "sys_utime", "fs/utimes.c", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mknod", "sys_mknod", "fs/namei.c", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "uselib", "", "fs/exec.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "personality", "sys_personality", "kernel/exec_domain.c", {ULONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ustat", "sys_ustat", "fs/statfs.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "statfs", "sys_statfs", "fs/statfs.c", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fstatfs", "sys_fstatfs", "fs/statfs.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sysfs", "sys_sysfs", "fs/filesystems.c", {INT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "getpriority", "sys_getpriority", "kernel/sys.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setpriority", "sys_setpriority", "kernel/sys.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_setparam", "sys_sched_setparam", "kernel/sched/core.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_getparam", "sys_sched_getparam", "kernel/sched/core.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_setscheduler", "sys_sched_setscheduler", "kernel/sched/core.c", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_getscheduler", "sys_sched_getscheduler", "kernel/sched/core.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_get_priority_max", "sys_sched_get_priority_max", "kernel/sched/core.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_get_priority_min", "sys_sched_get_priority_min", "kernel/sched/core.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_rr_get_interval", "sys_sched_rr_get_interval", "kernel/sched/core.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mlock", "sys_mlock", "mm/mlock.c", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "munlock", "sys_munlock", "mm/mlock.c", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mlockall", "sys_mlockall", "mm/mlock.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "munlockall", "sys_munlockall", "mm/mlock.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "vhangup", "sys_vhangup", "fs/open.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "modify_ldt", "sys_modify_ldt", "arch/x86/um/ldt.c", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, INT },
	{ "pivot_root", "sys_pivot_root", "fs/namespace.c", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "_sysctl", "sys_sysctl", "kernel/sysctl_binary.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "prctl", "sys_prctl", "kernel/sys.c", {INT, ULONG, ULONG, ULONG, ULONG, UNDEF}, INT },
	{ "arch_prctl", "sys_arch_prctl", "arch/x86/um/syscalls_64.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "adjtimex", "sys_adjtimex", "kernel/time.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setrlimit", "sys_setrlimit", "kernel/sys.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "chroot", "sys_chroot", "fs/open.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sync", "sys_sync", "fs/sync.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "acct", "sys_acct", "kernel/acct.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "settimeofday", "sys_settimeofday", "kernel/time.c", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mount", "sys_mount", "fs/namespace.c", {STR, STR, STR, ULONG, PTR, UNDEF}, INT },
	{ "umount2", "sys_umount", "fs/namespace.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "swapon", "sys_swapon", "mm/swapfile.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "swapoff", "sys_swapoff", "mm/swapfile.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "reboot", "sys_reboot", "kernel/reboot.c", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
	{ "sethostname", "sys_sethostname", "kernel/sys.c", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "setdomainname", "sys_setdomainname", "kernel/sys.c", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "iopl", "stub_iopl", "arch/x86/kernel/ioport.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ioperm", "sys_ioperm", "arch/x86/kernel/ioport.c", {ULONG, ULONG, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "create_module", "", "NOT IMPLEMENTED", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
	{ "init_module", "sys_init_module", "kernel/module.c", {PTR, ULONG, STR, UNDEF, UNDEF, UNDEF}, INT },
	{ "delete_module", "sys_delete_module", "kernel/module.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "get_kernel_syms", "", "NOT IMPLEMENTED", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "query_module", "", "NOT IMPLEMENTED", {STR, INT, PTR, SIZE_T, SIZE_T, UNDEF}, INT },
	{ "quotactl", "sys_quotactl", "fs/quota/quota.c", {INT, STR, INT, PTR, UNDEF, UNDEF}, INT },
	{ "nfsservctl", "", "NOT IMPLEMENTED", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, LONG },
	{ "getpmsg", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "putpmsg", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "afs_syscall", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "tuxcall", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "security", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "gettid", "sys_gettid", "kernel/sys.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "readahead", "sys_readahead", "mm/readahead.c", {INT, LONG, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
	{ "setxattr", "sys_setxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "lsetxattr", "sys_lsetxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "fsetxattr", "sys_fsetxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "getxattr", "sys_getxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "lgetxattr", "sys_lgetxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "fgetxattr", "sys_fgetxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "listxattr", "sys_listxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "llistxattr", "sys_llistxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "flistxattr", "sys_flistxattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "removexattr", "sys_removexattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "lremovexattr", "sys_lremovexattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "fremovexattr", "sys_fremovexattr", "fs/xattr.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "tkill", "sys_tkill", "kernel/signal.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "time", "sys_time", "kernel/time.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
	{ "futex", "sys_futex", "kernel/futex.c", {PTR, INT, INT, PTR, PTR, INT}, INT },
	{ "sched_setaffinity", "sys_sched_setaffinity", "kernel/sched/core.c", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "sched_getaffinity", "sys_sched_getaffinity", "kernel/sched/core.c", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "set_thread_area", "", "arch/x86/kernel/tls.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "io_setup", "sys_io_setup", "fs/aio.c", {UINT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "io_destroy", "sys_io_destroy", "fs/aio.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "io_getevents", "sys_io_getevents", "fs/aio.c", {INT, LONG, LONG, PTR, PTR, UNDEF}, INT },
	{ "io_submit", "sys_io_submit", "fs/aio.c", {INT, LONG, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "io_cancel", "sys_io_cancel", "fs/aio.c", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "get_thread_area", "", "arch/x86/kernel/tls.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "lookup_dcookie", "sys_lookup_dcookie", "fs/dcookies.c", {ULONG, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT },
	{ "epoll_create", "sys_epoll_create", "fs/eventpoll.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "epoll_ctl_old", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "epoll_wait_old", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "remap_file_pages", "sys_remap_file_pages", "mm/fremap.c", {PTR, SIZE_T, PROT, SIZE_T, INT, UNDEF}, INT },
	{ "getdents64", "sys_getdents64", "fs/readdir.c", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT },
	{ "set_tid_address", "sys_set_tid_address", "kernel/fork.c", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
	{ "restart_syscall", "sys_restart_syscall", "kernel/signal.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "semtimedop", "sys_semtimedop", "ipc/sem.c", {INT, PTR, SIZE_T, PTR, UNDEF, UNDEF}, INT },
	{ "fadvise64", "sys_fadvise64", "mm/fadvise.c", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
	{ "timer_create", "sys_timer_create", "kernel/posix-timers.c", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "timer_settime", "sys_timer_settime", "kernel/posix-timers.c", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
	{ "timer_gettime", "sys_timer_gettime", "kernel/posix-timers.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "timer_getoverrun", "sys_timer_getoverrun", "kernel/posix-timers.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "timer_delete", "sys_timer_delete", "kernel/posix-timers.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "clock_settime", "sys_clock_settime", "kernel/posix-timers.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "clock_gettime", "sys_clock_gettime", "kernel/posix-timers.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "clock_getres", "sys_clock_getres", "kernel/posix-timers.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "clock_nanosleep", "sys_clock_nanosleep", "kernel/posix-timers.c", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
	{ "exit_group", "sys_exit_group", "kernel/exit.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "epoll_wait", "sys_epoll_wait", "fs/eventpoll.c", {INT, PTR, INT, INT, UNDEF, UNDEF}, INT },
	{ "epoll_ctl", "sys_epoll_ctl", "fs/eventpoll.c", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
	{ "tgkill", "sys_tgkill", "kernel/signal.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "utimes", "sys_utimes", "fs/utimes.c", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "vserver", "", "NOT IMPLEMENTED", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "mbind", "sys_mbind", "mm/mempolicy.c", {PTR, ULONG, INT, PTR, ULONG, UINT}, LONG },
	{ "set_mempolicy", "sys_set_mempolicy", "mm/mempolicy.c", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, LONG },
	{ "get_mempolicy", "sys_get_mempolicy", "mm/mempolicy.c", {INT, PTR, ULONG, PTR, ULONG, UNDEF}, INT },
	{ "mq_open", "sys_mq_open", "ipc/mqueue.c", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mq_unlink", "sys_mq_unlink", "ipc/mqueue.c", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mq_timedsend", "sys_mq_timedsend", "ipc/mqueue.c", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, INT },
	{ "mq_timedreceive", "sys_mq_timedreceive", "ipc/mqueue.c", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, SSIZE_T },
	{ "mq_notify", "sys_mq_notify", "ipc/mqueue.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "mq_getsetattr", "sys_mq_getsetattr", "ipc/mqueue.c", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "kexec_load", "sys_kexec_load", "kernel/kexec.c", {ULONG, ULONG, PTR, ULONG, UNDEF, UNDEF}, LONG },
	{ "waitid", "sys_waitid", "kernel/exit.c", {INT, INT, PTR, INT, UNDEF, UNDEF}, INT },
	{ "add_key", "sys_add_key", "security/keys/keyctl.c", {STR, STR, PTR, SIZE_T, LONG, UNDEF}, LONG },
	{ "request_key", "sys_request_key", "security/keys/keyctl.c", {STR, STR, STR, LONG, UNDEF, UNDEF}, LONG },
	{ "keyctl", "sys_keyctl", "security/keys/keyctl.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "ioprio_set", "sys_ioprio_set", "fs/ioprio.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "ioprio_get", "sys_ioprio_get", "fs/ioprio.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "inotify_init", "sys_inotify_init", "fs/notify/inotify/inotify_user.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "inotify_add_watch", "sys_inotify_add_watch", "fs/notify/inotify/inotify_user.c", {INT, STR, UINT, UNDEF, UNDEF, UNDEF}, INT },
	{ "inotify_rm_watch", "sys_inotify_rm_watch", "fs/notify/inotify/inotify_user.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "migrate_pages", "sys_migrate_pages", "mm/mempolicy.c", {INT, ULONG, PTR, PTR, UNDEF, UNDEF}, LONG },
	{ "openat", "sys_openat", "fs/open.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "mkdirat", "sys_mkdirat", "fs/namei.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "mknodat", "sys_mknodat", "fs/namei.c", {INT, STR, INT, INT, UNDEF, UNDEF}, INT },
	{ "fchownat", "sys_fchownat", "fs/open.c", {INT, STR, UINT, INT, INT, UNDEF}, INT },
	{ "futimesat", "sys_futimesat", "fs/utimes.c", {INT, STR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "newfstatat", "sys_newfstatat", "fs/stat.c", {INT, STR, STRUCT, INT, UNDEF, UNDEF}, INT },
	{ "unlinkat", "sys_unlinkat", "fs/namei.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "renameat", "sys_renameat", "fs/namei.c", {INT, STR, INT, STR, UNDEF, UNDEF}, INT },
	{ "linkat", "sys_linkat", "fs/namei.c", {INT, STR, INT, STR, INT, UNDEF}, INT },
	{ "symlinkat", "sys_symlinkat", "fs/namei.c", {STR, INT, STR, UNDEF, UNDEF, UNDEF}, INT },
	{ "readlinkat", "sys_readlinkat", "fs/stat.c", {INT, STR, STR, SIZE_T, UNDEF, UNDEF}, SSIZE_T },
	{ "fchmodat", "sys_fchmodat", "fs/open.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "faccessat", "sys_faccessat", "fs/open.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "pselect6", "sys_pselect6", "fs/select.c", {INT, PTR, PTR, PTR, PTR, PTR}, INT },
	{ "ppoll", "sys_ppoll", "fs/select.c", {PTR, UINT, PTR, PTR, UNDEF, UNDEF}, INT },
	{ "unshare", "sys_unshare", "kernel/fork.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "set_robust_list", "sys_set_robust_list", "kernel/futex.c", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
	{ "get_robust_list", "sys_get_robust_list", "kernel/futex.c", {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, LONG },
	{ "splice", "sys_splice", "fs/splice.c", {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T },
	{ "tee", "sys_tee", "fs/splice.c", {INT, INT, SIZE_T, UINT, UNDEF, UNDEF}, SSIZE_T },
	{ "sync_file_range", "sys_sync_file_range", "fs/sync.c", {INT, LONG, LONG, UINT, UNDEF, UNDEF}, INT },
	{ "vmsplice", "sys_vmsplice", "fs/splice.c", {INT, PTR, ULONG, UINT, UNDEF, UNDEF}, SSIZE_T },
	{ "move_pages", "sys_move_pages", "mm/migrate.c", {INT, ULONG, PTR, INT, INT, INT}, LONG },
	{ "utimensat", "sys_utimensat", "fs/utimes.c", {INT, STR, PTR, INT, UNDEF, UNDEF}, INT },
	{ "epoll_pwait", "sys_epoll_pwait", "fs/eventpoll.c", {INT, PTR, INT, INT, PTR, UNDEF}, INT },
	{ "signalfd", "sys_signalfd", "fs/signalfd.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "timerfd_create", "sys_timerfd_create", "fs/timerfd.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "eventfd", "sys_eventfd", "fs/eventfd.c", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fallocate", "sys_fallocate", "fs/open.c", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
	{ "timerfd_settime", "sys_timerfd_settime", "fs/timerfd.c", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
	{ "timerfd_gettime", "sys_timerfd_gettime", "fs/timerfd.c", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "accept4", "sys_accept4", "net/socket.c", {INT, PTR, PTR, INT, UNDEF, UNDEF}, INT },
	{ "signalfd4", "sys_signalfd4", "fs/signalfd.c", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "eventfd2", "sys_eventfd2", "fs/eventfd.c", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "epoll_create1", "sys_epoll_create1", "fs/eventpoll.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "dup3", "sys_dup3", "fs/file.c", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
	{ "pipe2", "sys_pipe2", "fs/pipe.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "inotify_init1", "sys_inotify_init1", "fs/notify/inotify/inotify_user.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "preadv", "sys_preadv", "fs/read_write.c", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T },
	{ "pwritev", "sys_pwritev", "fs/read_write.c", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T },
	{ "rt_tgsigqueueinfo", "sys_rt_tgsigqueueinfo", "kernel/signal.c", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
	{ "perf_event_open", "sys_perf_event_open", "kernel/events/core.c", {PTR, INT, INT, INT, ULONG, UNDEF}, INT },
	{ "recvmmsg", "sys_recvmmsg", "net/socket.c", {INT, PTR, UINT, UINT, PTR, UNDEF}, INT },
	{ "fanotify_init", "sys_fanotify_init", "fs/notify/fanotify/fanotify_user.c", {UINT, UINT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "fanotify_mark", "sys_fanotify_mark", "fs/notify/fanotify/fanotify_user.c", {INT, UINT, ULONG, INT, STR, UNDEF}, INT },
	{ "prlimit64", "sys_prlimit64", "kernel/sys.c", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
	{ "name_to_handle_at", "sys_name_to_handle_at", "fs/fhandle.c", {INT, STR, PTR, INT, INT, UNDEF}, INT },
	{ "open_by_handle_at", "sys_open_by_handle_at", "fs/fhandle.c", {INT, STR, PTR, INT, INT, UNDEF}, INT },
	{ "clock_adjtime", "sys_clock_adjtime", "kernel/posix-timers.c", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
	{ "syncfs", "sys_syncfs", "fs/sync.c", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "sendmmsg", "sys_sendmmsg", "net/socket.c", {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT },
	{ "setns", "sys_setns", "kernel/nsproxy.c", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
	{ "getcpu", "sys_getcpu", "kernel/sys.c", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
	{ "process_vm_readv", "sys_process_vm_readv", "mm/process_vm_access.c", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T },
	{ "process_vm_writev", "sys_process_vm_writev", "mm/process_vm_access.c", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T },
	{ "kcmp", "sys_kcmp", "kernel/kcmp.c", {INT, INT, INT, ULONG, ULONG, UNDEF}, INT },
	{ "finit_module", "sys_finit_module", "kernel/module.c", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT }
};

/*
** Format & print info on user registers
** https://docs.huihoo.com/doxygen/linux/kernel/3.7/structuser__regs__struct.html
*/

static int		handle_invalid_syscall_id(pid_t process, struct user_regs_struct *pre_user_regs)
{
	ft_printf(ERR_PREFIX "[%d] => Invalid syscall id: %ld", \
		process, pre_user_regs->orig_rax);
	return (0);
}

/*
** https://linuxgazette.net/issue81/sandeep.html
*/

static int		print_string(pid_t child, unsigned long reg_value)
{
	unsigned long	tmp;
	unsigned int	read;
	char			buf[STR_BUFFER_LEN];

	read = 0;
	while (1)
	{
		errno = 0;
		tmp = ptrace(PTRACE_PEEKDATA, child, reg_value + read);
		if (errno)
		{
			printf("ptrace returned %x, %d\n", tmp, errno);
			printf("%s", ft_strerror(errno));
			return (1);
		}
		ft_memcpy(buf + read, &tmp, sizeof(tmp));
		if (ft_memchr(&tmp, 0, sizeof(tmp)))
			break ;
		read += (unsigned int)sizeof(tmp);
	}
	if (read == (sizeof(buf)))
		ft_printf("\"%*s...\"", STR_BUFFER_LEN, buf);
	else
		ft_printf("\"%s\"", buf);
	return (0);
}

static int		format_reg_value(pid_t child, int type, \
					unsigned long reg_value, unsigned int reg_index)
{
	int			printf_fmt_types[] = {
		INT, SIZE_T, SSIZE_T, LONG, UINT, HEX, ULONG
	};
	char		*printf_fmt_types_str[] = {
		"%d", "%zu", "%zd", "%ld", "%u", "%x", "%lu"
	};
	int			fmt_index;

	if (type == UNDEF)
		return (0);
	if (reg_index != 0)
		write(STDOUT_FILENO, ", ", 2);
	if ((fmt_index = ft_int_index(printf_fmt_types, (sizeof(printf_fmt_types) / sizeof(int)), type)) != -1)
		ft_printf(printf_fmt_types_str[fmt_index], reg_value);
	else if (type == PTR)
		reg_value ? \
			ft_printf("%p", reg_value) : \
			ft_printf("NULL");
	else if (type == STR)
		print_string(child, reg_value);
	else
		ft_printf("%s", "TODO");
	return (1);
}

static int		cycle_syscall_params(pid_t child, int syscall_reg_types[6], unsigned long pre_user_regs[6])
{
	write(STDOUT_FILENO, "(", 1);
	for (unsigned int i = 0; i < 6; i++)
	{
		if (format_reg_value(child, syscall_reg_types[i], pre_user_regs[i], i) == 0)
			break ;
	}
	write(STDOUT_FILENO, ")", 1);
	return (0);
}

/*
** https://stackoverflow.com/questions/29047592/accessing-errno-h-in-assembly-language
*/

static int		print_valid_pre_syscall(pid_t process, struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table)
{
	fflush(stdout);
	ft_printf(INFO_PREFIX "[%d] => (%3ld) %s", \
		process, user_regs->orig_rax, table[user_regs->orig_rax].name);
	cycle_syscall_params(process, table[user_regs->orig_rax].reg_types, \
		(unsigned long[6]) {
			user_regs->rdi, user_regs->rsi, user_regs->rdx, \
			user_regs->r10, user_regs->r8, user_regs->r9
		});
	return (0);
}

static int		print_valid_post_syscall(pid_t process, struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table)
{
	fflush(stdout);
	write(STDOUT_FILENO, " = ", 3);
	if (table[user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)user_regs->rax && (int)user_regs->rax <= -1))
		ft_printf("-1 %s (%s)", tostring_errnum(-user_regs->rax), ft_strerror(-user_regs->rax));
	else
		format_reg_value(process, table[user_regs->orig_rax].reg_ret_type, user_regs->rax, 0);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

int				print_syscall_info(pid_t process, bool regs_type, \
					struct user_regs_struct *user_regs)
{
	t_ft_strace_syscall	*table;

	table = g_syscall_table_64;
	if (regs_type == PRE_SYSCALL_REGS)
	{
		if (user_regs->orig_rax < ( sizeof(g_syscall_table_64) / sizeof(t_ft_strace_syscall) ))
			print_valid_pre_syscall(process, user_regs, table);
		else
			handle_invalid_syscall_id(process, user_regs);
	}
	else if (regs_type == POST_SYSCALL_REGS)
		return (print_valid_post_syscall(process, user_regs, table));
	return (0);
}
