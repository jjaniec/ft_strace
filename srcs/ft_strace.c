/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:08:56 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/29 21:31:17 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

void	*g_syscall_table[329][3] = {
	{ "read", "sys_read", "fs/read_write.c" },
	{ "write", "sys_write", "fs/read_write.c" },
	{ "open", "sys_open", "fs/open.c" },
	{ "close", "sys_close", "fs/open.c" },
	{ "stat", "sys_newstat", "fs/stat.c" },
	{ "fstat", "sys_newfstat", "fs/stat.c" },
	{ "lstat", "sys_newlstat", "fs/stat.c" },
	{ "poll", "sys_poll", "fs/select.c" },
	{ "lseek", "sys_lseek", "fs/read_write.c" },
	{ "mmap", "sys_mmap", "arch/x86/kernel/sys_x86_64.c" },
	{ "mprotect", "sys_mprotect", "mm/mprotect.c" },
	{ "munmap", "sys_munmap", "mm/mmap.c" },
	{ "brk", "sys_brk", "mm/mmap.c" },
	{ "rt_sigaction", "sys_rt_sigaction", "kernel/signal.c" },
	{ "rt_sigprocmask", "sys_rt_sigprocmask", "kernel/signal.c" },
	{ "rt_sigreturn", "stub_rt_sigreturn", "arch/x86/kernel/signal.c" },
	{ "ioctl", "sys_ioctl", "fs/ioctl.c" },
	{ "pread64", "sys_pread64", "fs/read_write.c" },
	{ "pwrite64", "sys_pwrite64", "fs/read_write.c" },
	{ "readv", "sys_readv", "fs/read_write.c" },
	{ "writev", "sys_writev", "fs/read_write.c" },
	{ "access", "sys_access", "fs/open.c" },
	{ "pipe", "sys_pipe", "fs/pipe.c" },
	{ "select", "sys_select", "fs/select.c" },
	{ "sched_yield", "sys_sched_yield", "kernel/sched/core.c" },
	{ "mremap", "sys_mremap", "mm/mmap.c" },
	{ "msync", "sys_msync", "mm/msync.c" },
	{ "mincore", "sys_mincore", "mm/mincore.c" },
	{ "madvise", "sys_madvise", "mm/madvise.c" },
	{ "shmget", "sys_shmget", "ipc/shm.c" },
	{ "shmat", "sys_shmat", "ipc/shm.c" },
	{ "shmctl", "sys_shmctl", "ipc/shm.c" },
	{ "dup", "sys_dup", "fs/file.c" },
	{ "dup2", "sys_dup2", "fs/file.c" },
	{ "pause", "sys_pause", "kernel/signal.c" },
	{ "nanosleep", "sys_nanosleep", "kernel/hrtimer.c" },
	{ "getitimer", "sys_getitimer", "kernel/itimer.c" },
	{ "alarm", "sys_alarm", "kernel/timer.c" },
	{ "setitimer", "sys_setitimer", "kernel/itimer.c" },
	{ "getpid", "sys_getpid", "kernel/sys.c" },
	{ "sendfile", "sys_sendfile64", "fs/read_write.c" },
	{ "socket", "sys_socket", "net/socket.c" },
	{ "connect", "sys_connect", "net/socket.c" },
	{ "accept", "sys_accept", "net/socket.c" },
	{ "sendto", "sys_sendto", "net/socket.c" },
	{ "recvfrom", "sys_recvfrom", "net/socket.c" },
	{ "sendmsg", "sys_sendmsg", "net/socket.c" },
	{ "recvmsg", "sys_recvmsg", "net/socket.c" },
	{ "shutdown", "sys_shutdown", "net/socket.c" },
	{ "bind", "sys_bind", "net/socket.c" },
	{ "listen", "sys_listen", "net/socket.c" },
	{ "getsockname", "sys_getsockname", "net/socket.c" },
	{ "getpeername", "sys_getpeername", "net/socket.c" },
	{ "socketpair", "sys_socketpair", "net/socket.c" },
	{ "setsockopt", "sys_setsockopt", "net/socket.c" },
	{ "getsockopt", "sys_getsockopt", "net/socket.c" },
	{ "clone", "stub_clone", "kernel/fork.c" },
	{ "fork", "stub_fork", "kernel/fork.c" },
	{ "vfork", "stub_vfork", "kernel/fork.c" },
	{ "execve", "stub_execve", "fs/exec.c" },
	{ "exit", "sys_exit", "kernel/exit.c" },
	{ "wait4", "sys_wait4", "kernel/exit.c" },
	{ "kill", "sys_kill", "kernel/signal.c" },
	{ "uname", "sys_newuname", "kernel/sys.c" },
	{ "semget", "sys_semget", "ipc/sem.c" },
	{ "semop", "sys_semop", "ipc/sem.c" },
	{ "semctl", "sys_semctl", "ipc/sem.c" },
	{ "shmdt", "sys_shmdt", "ipc/shm.c" },
	{ "msgget", "sys_msgget", "ipc/msg.c" },
	{ "msgsnd", "sys_msgsnd", "ipc/msg.c" },
	{ "msgrcv", "sys_msgrcv", "ipc/msg.c" },
	{ "msgctl", "sys_msgctl", "ipc/msg.c" },
	{ "fcntl", "sys_fcntl", "fs/fcntl.c" },
	{ "flock", "sys_flock", "fs/locks.c" },
	{ "fsync", "sys_fsync", "fs/sync.c" },
	{ "fdatasync", "sys_fdatasync", "fs/sync.c" },
	{ "truncate", "sys_truncate", "fs/open.c" },
	{ "ftruncate", "sys_ftruncate", "fs/open.c" },
	{ "getdents", "sys_getdents", "fs/readdir.c" },
	{ "getcwd", "sys_getcwd", "fs/dcache.c" },
	{ "chdir", "sys_chdir", "fs/open.c" },
	{ "fchdir", "sys_fchdir", "fs/open.c" },
	{ "rename", "sys_rename", "fs/namei.c" },
	{ "mkdir", "sys_mkdir", "fs/namei.c" },
	{ "rmdir", "sys_rmdir", "fs/namei.c" },
	{ "creat", "sys_creat", "fs/open.c" },
	{ "link", "sys_link", "fs/namei.c" },
	{ "unlink", "sys_unlink", "fs/namei.c" },
	{ "symlink", "sys_symlink", "fs/namei.c" },
	{ "readlink", "sys_readlink", "fs/stat.c" },
	{ "chmod", "sys_chmod", "fs/open.c" },
	{ "fchmod", "sys_fchmod", "fs/open.c" },
	{ "chown", "sys_chown", "fs/open.c" },
	{ "fchown", "sys_fchown", "fs/open.c" },
	{ "lchown", "sys_lchown", "fs/open.c" },
	{ "umask", "sys_umask", "kernel/sys.c" },
	{ "gettimeofday", "sys_gettimeofday", "kernel/time.c" },
	{ "getrlimit", "sys_getrlimit", "kernel/sys.c" },
	{ "getrusage", "sys_getrusage", "kernel/sys.c" },
	{ "sysinfo", "sys_sysinfo", "kernel/sys.c" },
	{ "times", "sys_times", "kernel/sys.c" },
	{ "ptrace", "sys_ptrace", "kernel/ptrace.c" },
	{ "getuid", "sys_getuid", "kernel/sys.c" },
	{ "syslog", "sys_syslog", "kernel/printk/printk.c" },
	{ "getgid", "sys_getgid", "kernel/sys.c" },
	{ "setuid", "sys_setuid", "kernel/sys.c" },
	{ "setgid", "sys_setgid", "kernel/sys.c" },
	{ "geteuid", "sys_geteuid", "kernel/sys.c" },
	{ "getegid", "sys_getegid", "kernel/sys.c" },
	{ "setpgid", "sys_setpgid", "kernel/sys.c" },
	{ "getppid", "sys_getppid", "kernel/sys.c" },
	{ "getpgrp", "sys_getpgrp", "kernel/sys.c" },
	{ "setsid", "sys_setsid", "kernel/sys.c" },
	{ "setreuid", "sys_setreuid", "kernel/sys.c" },
	{ "setregid", "sys_setregid", "kernel/sys.c" },
	{ "getgroups", "sys_getgroups", "kernel/groups.c" },
	{ "setgroups", "sys_setgroups", "kernel/groups.c" },
	{ "setresuid", "sys_setresuid", "kernel/sys.c" },
	{ "getresuid", "sys_getresuid", "kernel/sys.c" },
	{ "setresgid", "sys_setresgid", "kernel/sys.c" },
	{ "getresgid", "sys_getresgid", "kernel/sys.c" },
	{ "getpgid", "sys_getpgid", "kernel/sys.c" },
	{ "setfsuid", "sys_setfsuid", "kernel/sys.c" },
	{ "setfsgid", "sys_setfsgid", "kernel/sys.c" },
	{ "getsid", "sys_getsid", "kernel/sys.c" },
	{ "capget", "sys_capget", "kernel/capability.c" },
	{ "capset", "sys_capset", "kernel/capability.c" },
	{ "rt_sigpending", "sys_rt_sigpending", "kernel/signal.c" },
	{ "rt_sigtimedwait", "sys_rt_sigtimedwait", "kernel/signal.c" },
	{ "rt_sigqueueinfo", "sys_rt_sigqueueinfo", "kernel/signal.c" },
	{ "rt_sigsuspend", "sys_rt_sigsuspend", "kernel/signal.c" },
	{ "sigaltstack", "sys_sigaltstack", "kernel/signal.c" },
	{ "utime", "sys_utime", "fs/utimes.c" },
	{ "mknod", "sys_mknod", "fs/namei.c" },
	{ "uselib", "fs/exec.c" },
	{ "personality", "sys_personality", "kernel/exec_domain.c" },
	{ "ustat", "sys_ustat", "fs/statfs.c" },
	{ "statfs", "sys_statfs", "fs/statfs.c" },
	{ "fstatfs", "sys_fstatfs", "fs/statfs.c" },
	{ "sysfs", "sys_sysfs", "fs/filesystems.c" },
	{ "getpriority", "sys_getpriority", "kernel/sys.c" },
	{ "setpriority", "sys_setpriority", "kernel/sys.c" },
	{ "sched_setparam", "sys_sched_setparam", "kernel/sched/core.c" },
	{ "sched_getparam", "sys_sched_getparam", "kernel/sched/core.c" },
	{ "sched_setscheduler", "sys_sched_setscheduler", "kernel/sched/core.c" },
	{ "sched_getscheduler", "sys_sched_getscheduler", "kernel/sched/core.c" },
	{ "sched_get_priority_max", "sys_sched_get_priority_max", "kernel/sched/core.c" },
	{ "sched_get_priority_min", "sys_sched_get_priority_min", "kernel/sched/core.c" },
	{ "sched_rr_get_interval", "sys_sched_rr_get_interval", "kernel/sched/core.c" },
	{ "mlock", "sys_mlock", "mm/mlock.c" },
	{ "munlock", "sys_munlock", "mm/mlock.c" },
	{ "mlockall", "sys_mlockall", "mm/mlock.c" },
	{ "munlockall", "sys_munlockall", "mm/mlock.c" },
	{ "vhangup", "sys_vhangup", "fs/open.c" },
	{ "modify_ldt", "sys_modify_ldt", "arch/x86/um/ldt.c" },
	{ "pivot_root", "sys_pivot_root", "fs/namespace.c" },
	{ "_sysctl", "sys_sysctl", "kernel/sysctl_binary.c" },
	{ "prctl", "sys_prctl", "kernel/sys.c" },
	{ "arch_prctl", "sys_arch_prctl", "arch/x86/um/syscalls_64.c" },
	{ "adjtimex", "sys_adjtimex", "kernel/time.c" },
	{ "setrlimit", "sys_setrlimit", "kernel/sys.c" },
	{ "chroot", "sys_chroot", "fs/open.c" },
	{ "sync", "sys_sync", "fs/sync.c" },
	{ "acct", "sys_acct", "kernel/acct.c" },
	{ "settimeofday", "sys_settimeofday", "kernel/time.c" },
	{ "mount", "sys_mount", "fs/namespace.c" },
	{ "umount2", "sys_umount", "fs/namespace.c" },
	{ "swapon", "sys_swapon", "mm/swapfile.c" },
	{ "swapoff", "sys_swapoff", "mm/swapfile.c" },
	{ "reboot", "sys_reboot", "kernel/reboot.c" },
	{ "sethostname", "sys_sethostname", "kernel/sys.c" },
	{ "setdomainname", "sys_setdomainname", "kernel/sys.c" },
	{ "iopl", "stub_iopl", "arch/x86/kernel/ioport.c" },
	{ "ioperm", "sys_ioperm", "arch/x86/kernel/ioport.c" },
	{ "create_module", "", "NOT IMPLEMENTED" },
	{ "init_module", "sys_init_module", "kernel/module.c" },
	{ "delete_module", "sys_delete_module", "kernel/module.c" },
	{ "get_kernel_syms", "", "NOT IMPLEMENTED" },
	{ "query_module", "", "NOT IMPLEMENTED" },
	{ "quotactl", "sys_quotactl", "fs/quota/quota.c" },
	{ "nfsservctl", "", "NOT IMPLEMENTED" },
	{ "getpmsg", "", "NOT IMPLEMENTED" },
	{ "putpmsg", "", "NOT IMPLEMENTED" },
	{ "afs_syscall", "", "NOT IMPLEMENTED" },
	{ "tuxcall", "", "NOT IMPLEMENTED" },
	{ "security", "", "NOT IMPLEMENTED" },
	{ "gettid", "sys_gettid", "kernel/sys.c" },
	{ "readahead", "sys_readahead", "mm/readahead.c" },
	{ "setxattr", "sys_setxattr", "fs/xattr.c" },
	{ "lsetxattr", "sys_lsetxattr", "fs/xattr.c" },
	{ "fsetxattr", "sys_fsetxattr", "fs/xattr.c" },
	{ "getxattr", "sys_getxattr", "fs/xattr.c" },
	{ "lgetxattr", "sys_lgetxattr", "fs/xattr.c" },
	{ "fgetxattr", "sys_fgetxattr", "fs/xattr.c" },
	{ "listxattr", "sys_listxattr", "fs/xattr.c" },
	{ "llistxattr", "sys_llistxattr", "fs/xattr.c" },
	{ "flistxattr", "sys_flistxattr", "fs/xattr.c" },
	{ "removexattr", "sys_removexattr", "fs/xattr.c" },
	{ "lremovexattr", "sys_lremovexattr", "fs/xattr.c" },
	{ "fremovexattr", "sys_fremovexattr", "fs/xattr.c" },
	{ "tkill", "sys_tkill", "kernel/signal.c" },
	{ "time", "sys_time", "kernel/time.c" },
	{ "futex", "sys_futex", "kernel/futex.c" },
	{ "sched_setaffinity", "sys_sched_setaffinity", "kernel/sched/core.c" },
	{ "sched_getaffinity", "sys_sched_getaffinity", "kernel/sched/core.c" },
	{ "set_thread_area", "arch/x86/kernel/tls.c" },
	{ "io_setup", "sys_io_setup", "fs/aio.c" },
	{ "io_destroy", "sys_io_destroy", "fs/aio.c" },
	{ "io_getevents", "sys_io_getevents", "fs/aio.c" },
	{ "io_submit", "sys_io_submit", "fs/aio.c" },
	{ "io_cancel", "sys_io_cancel", "fs/aio.c" },
	{ "get_thread_area", "arch/x86/kernel/tls.c" },
	{ "lookup_dcookie", "sys_lookup_dcookie", "fs/dcookies.c" },
	{ "epoll_create", "sys_epoll_create", "fs/eventpoll.c" },
	{ "epoll_ctl_old", "", "NOT IMPLEMENTED" },
	{ "epoll_wait_old", "", "NOT IMPLEMENTED" },
	{ "remap_file_pages", "sys_remap_file_pages", "mm/fremap.c" },
	{ "getdents64", "sys_getdents64", "fs/readdir.c" },
	{ "set_tid_address", "sys_set_tid_address", "kernel/fork.c" },
	{ "restart_syscall", "sys_restart_syscall", "kernel/signal.c" },
	{ "semtimedop", "sys_semtimedop", "ipc/sem.c" },
	{ "fadvise64", "sys_fadvise64", "mm/fadvise.c" },
	{ "timer_create", "sys_timer_create", "kernel/posix-timers.c" },
	{ "timer_settime", "sys_timer_settime", "kernel/posix-timers.c" },
	{ "timer_gettime", "sys_timer_gettime", "kernel/posix-timers.c" },
	{ "timer_getoverrun", "sys_timer_getoverrun", "kernel/posix-timers.c" },
	{ "timer_delete", "sys_timer_delete", "kernel/posix-timers.c" },
	{ "clock_settime", "sys_clock_settime", "kernel/posix-timers.c" },
	{ "clock_gettime", "sys_clock_gettime", "kernel/posix-timers.c" },
	{ "clock_getres", "sys_clock_getres", "kernel/posix-timers.c" },
	{ "clock_nanosleep", "sys_clock_nanosleep", "kernel/posix-timers.c" },
	{ "exit_group", "sys_exit_group", "kernel/exit.c" },
	{ "epoll_wait", "sys_epoll_wait", "fs/eventpoll.c" },
	{ "epoll_ctl", "sys_epoll_ctl", "fs/eventpoll.c" },
	{ "tgkill", "sys_tgkill", "kernel/signal.c" },
	{ "utimes", "sys_utimes", "fs/utimes.c" },
	{ "vserver", "", "NOT IMPLEMENTED" },
	{ "mbind", "sys_mbind", "mm/mempolicy.c" },
	{ "set_mempolicy", "sys_set_mempolicy", "mm/mempolicy.c" },
	{ "get_mempolicy", "sys_get_mempolicy", "mm/mempolicy.c" },
	{ "mq_open", "sys_mq_open", "ipc/mqueue.c" },
	{ "mq_unlink", "sys_mq_unlink", "ipc/mqueue.c" },
	{ "mq_timedsend", "sys_mq_timedsend", "ipc/mqueue.c" },
	{ "mq_timedreceive", "sys_mq_timedreceive", "ipc/mqueue.c" },
	{ "mq_notify", "sys_mq_notify", "ipc/mqueue.c" },
	{ "mq_getsetattr", "sys_mq_getsetattr", "ipc/mqueue.c" },
	{ "kexec_load", "sys_kexec_load", "kernel/kexec.c" },
	{ "waitid", "sys_waitid", "kernel/exit.c" },
	{ "add_key", "sys_add_key", "security/keys/keyctl.c" },
	{ "request_key", "sys_request_key", "security/keys/keyctl.c" },
	{ "keyctl", "sys_keyctl", "security/keys/keyctl.c" },
	{ "ioprio_set", "sys_ioprio_set", "fs/ioprio.c" },
	{ "ioprio_get", "sys_ioprio_get", "fs/ioprio.c" },
	{ "inotify_init", "sys_inotify_init", "fs/notify/inotify/inotify_user.c" },
	{ "inotify_add_watch", "sys_inotify_add_watch", "fs/notify/inotify/inotify_user.c" },
	{ "inotify_rm_watch", "sys_inotify_rm_watch", "fs/notify/inotify/inotify_user.c" },
	{ "migrate_pages", "sys_migrate_pages", "mm/mempolicy.c" },
	{ "openat", "sys_openat", "fs/open.c" },
	{ "mkdirat", "sys_mkdirat", "fs/namei.c" },
	{ "mknodat", "sys_mknodat", "fs/namei.c" },
	{ "fchownat", "sys_fchownat", "fs/open.c" },
	{ "futimesat", "sys_futimesat", "fs/utimes.c" },
	{ "newfstatat", "sys_newfstatat", "fs/stat.c" },
	{ "unlinkat", "sys_unlinkat", "fs/namei.c" },
	{ "renameat", "sys_renameat", "fs/namei.c" },
	{ "linkat", "sys_linkat", "fs/namei.c" },
	{ "symlinkat", "sys_symlinkat", "fs/namei.c" },
	{ "readlinkat", "sys_readlinkat", "fs/stat.c" },
	{ "fchmodat", "sys_fchmodat", "fs/open.c" },
	{ "faccessat", "sys_faccessat", "fs/open.c" },
	{ "pselect6", "sys_pselect6", "fs/select.c" },
	{ "ppoll", "sys_ppoll", "fs/select.c" },
	{ "unshare", "sys_unshare", "kernel/fork.c" },
	{ "set_robust_list", "sys_set_robust_list", "kernel/futex.c" },
	{ "get_robust_list", "sys_get_robust_list", "kernel/futex.c" },
	{ "splice", "sys_splice", "fs/splice.c" },
	{ "tee", "sys_tee", "fs/splice.c" },
	{ "sync_file_range", "sys_sync_file_range", "fs/sync.c" },
	{ "vmsplice", "sys_vmsplice", "fs/splice.c" },
	{ "move_pages", "sys_move_pages", "mm/migrate.c" },
	{ "utimensat", "sys_utimensat", "fs/utimes.c" },
	{ "epoll_pwait", "sys_epoll_pwait", "fs/eventpoll.c" },
	{ "signalfd", "sys_signalfd", "fs/signalfd.c" },
	{ "timerfd_create", "sys_timerfd_create", "fs/timerfd.c" },
	{ "eventfd", "sys_eventfd", "fs/eventfd.c" },
	{ "fallocate", "sys_fallocate", "fs/open.c" },
	{ "timerfd_settime", "sys_timerfd_settime", "fs/timerfd.c" },
	{ "timerfd_gettime", "sys_timerfd_gettime", "fs/timerfd.c" },
	{ "accept4", "sys_accept4", "net/socket.c" },
	{ "signalfd4", "sys_signalfd4", "fs/signalfd.c" },
	{ "eventfd2", "sys_eventfd2", "fs/eventfd.c" },
	{ "epoll_create1", "sys_epoll_create1", "fs/eventpoll.c" },
	{ "dup3", "sys_dup3", "fs/file.c" },
	{ "pipe2", "sys_pipe2", "fs/pipe.c" },
	{ "inotify_init1", "sys_inotify_init1", "fs/notify/inotify/inotify_user.c" },
	{ "preadv", "sys_preadv", "fs/read_write.c" },
	{ "pwritev", "sys_pwritev", "fs/read_write.c" },
	{ "rt_tgsigqueueinfo", "sys_rt_tgsigqueueinfo", "kernel/signal.c" },
	{ "perf_event_open", "sys_perf_event_open", "kernel/events/core.c" },
	{ "recvmmsg", "sys_recvmmsg", "net/socket.c" },
	{ "fanotify_init", "sys_fanotify_init", "fs/notify/fanotify/fanotify_user.c" },
	{ "fanotify_mark", "sys_fanotify_mark", "fs/notify/fanotify/fanotify_user.c" },
	{ "prlimit64", "sys_prlimit64", "kernel/sys.c" },
	{ "name_to_handle_at", "sys_name_to_handle_at", "fs/fhandle.c" },
	{ "open_by_handle_at", "sys_open_by_handle_at", "fs/fhandle.c" },
	{ "clock_adjtime", "sys_clock_adjtime", "kernel/posix-timers.c" },
	{ "syncfs", "sys_syncfs", "fs/sync.c" },
	{ "sendmmsg", "sys_sendmmsg", "net/socket.c" },
	{ "setns", "sys_setns", "kernel/nsproxy.c" },
	{ "getcpu", "sys_getcpu", "kernel/sys.c" },
	{ "process_vm_readv", "sys_process_vm_readv", "mm/process_vm_access.c" },
	{ "process_vm_writev", "sys_process_vm_writev", "mm/process_vm_access.c" },
	{ "kcmp", "sys_kcmp", "kernel/kcmp.c" },
	{ "finit_module", "sys_finit_module", "kernel/module.c" }
};

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
	if (execve(exec_path, exec_args, exec_environ) == -1)
		return (handle_execve_err());
	return (1);
}

/*
** Format & print info on user registers
** https://docs.huihoo.com/doxygen/linux/kernel/3.7/structuser__regs__struct.html
*/

static int	print_syscall_info(pid_t process, struct user_regs_struct *pre_user_regs, \
				struct user_regs_struct *post_user_regs)
{
	ft_printf(INFO_PREFIX "[%d] => %s (%ld/%s <%s>)", \
		process, g_syscall_table[pre_user_regs->orig_rax][0], \
		pre_user_regs->orig_rax, g_syscall_table[pre_user_regs->orig_rax][1], \
		g_syscall_table[pre_user_regs->orig_rax][2]);
	ft_printf(" (%ld %ld %ld %ld %ld %ld) ", \
		pre_user_regs->rdi, pre_user_regs->rsi, pre_user_regs->rdx, \
		pre_user_regs->r10, pre_user_regs->r8, pre_user_regs->r9);
	ft_printf("= %ld;", post_user_regs->rax);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

/*
** Set ptrace options & read user section to gather syscall numbers & parameters
*/

static int	cont_process(pid_t process, int *status, struct user_regs_struct *user_regs)
{

	ptrace(PTRACE_SYSCALL, process, 0, 0);
	// ptrace(PTRACE_SETOPTIONS, process, 0, PTRACE_O_EXITKILL);
	waitpid(process, status, 0);
	if (WIFEXITED(*status))
	{
		ft_printf(INFO_PREFIX "[%d] exited with code: %d\n", process, *status);
		return (1);
	}
	ptrace(PTRACE_GETREGS, process, 0, user_regs);
	return (0);
}

static int	handle_child(pid_t child)
{
	struct user_regs_struct		pre_user_regs;
	struct user_regs_struct		post_user_regs;
	int 						status;

	ptrace(PTRACE_SEIZE, child, 0, 0);
	ptrace(PTRACE_INTERRUPT, child, 0, 0);
	while (1)
	{
		if (cont_process(child, &status, &pre_user_regs) || \
			cont_process(child, &status, &post_user_regs))
			break ;
		print_syscall_info(child, &pre_user_regs, &post_user_regs);
	}
	return (1);
}

/*
** Fork, start the program passed as arguments in the child process
** And monitor the child in the main process
*/

int			ft_strace(char *exec_path, char **exec_args, char **exec_environ)
{
	pid_t	child;

	if ((child = fork()) == -1)
	{
		write(STDERR_FILENO, ERR_PREFIX "Fork failed!\n", ft_strlen(ERR_PREFIX) + 13);
		return (1);
	}
	else if (child == 0)
		return (child_process_tasks(exec_path, exec_args, exec_environ));
	ft_printf(OK_PREFIX "Child pid: %d\n", child);
	return (handle_child(child));
}
