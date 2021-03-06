{ "read", {INT, BUFFER, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "write", {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "open", {STR, FLAGS, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "close", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "stat", {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fstat", {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "lstat", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "poll", {PTR, UINT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "lseek", {INT, LONG, INT, UNDEF, UNDEF, UNDEF}, LONG },
{ "mmap", {PTR, SIZE_T, MAP_PROT, FLAGS, INT, HEX}, PTR },
{ "mprotect", {PTR, SIZE_T, MAP_PROT, UNDEF, UNDEF, UNDEF}, INT },
{ "munmap", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "brk", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
{ "rt_sigaction", {SIGNO, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "rt_sigprocmask", {FLAGS, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT },
{ "rt_sigreturn", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ioctl", {INT, ULONG, STRUCT, UNDEF, UNDEF, UNDEF}, INT },
{ "pread64", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T },
{ "pwrite64", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T },
{ "readv", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "writev", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "access", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "pipe", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "select", {INT, PTR, PTR, PTR, PTR, UNDEF}, INT },
{ "sched_yield", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mremap", {PTR, SIZE_T, SIZE_T, INT, PTR, UNDEF}, PTR },
{ "msync", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "mincore", {PTR, SIZE_T, STR, UNDEF, UNDEF, UNDEF}, INT },
{ "madvise", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "shmget", {INT, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "shmat", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, PTR },
{ "shmctl", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "dup", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "dup2", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "pause", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "nanosleep", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getitimer", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "alarm", {UINT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, UINT },
{ "setitimer", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "getpid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sendfile", {INT, INT, UNDEF, LONG, UNDEF, UNDEF}, SSIZE_T },
{ "socket", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "connect", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "accept", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "sendto", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T },
{ "recvfrom", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T },
{ "sendmsg", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "recvmsg", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "shutdown", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "bind", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "listen", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getsockname", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "getpeername", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "socketpair", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
{ "setsockopt", {INT, INT, INT, PTR, INT, UNDEF}, INT },
{ "getsockopt", {INT, INT, INT, PTR, INT, UNDEF}, INT },
{ "clone", {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT },
{ "fork", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "vfork", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "execve", {STR, STR_TAB, VARS, UNDEF, UNDEF, UNDEF}, INT },
{ "exit", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "wait4", {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT },
{ "kill", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "uname", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "semget", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "semop", {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT },
{ "semctl", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "shmdt", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "msgget", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "msgsnd", {INT, PTR, SIZE_T, INT, UNDEF, UNDEF}, INT },
{ "msgrcv", {INT, PTR, SIZE_T, LONG, INT, UNDEF}, SSIZE_T },
{ "msgctl", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "fcntl", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "flock", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fsync", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fdatasync", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "truncate", {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ftruncate", {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getdents", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT },
{ "getcwd", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
{ "chdir", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fchdir", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "rename", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mkdir", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "rmdir", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "creat", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "link", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "unlink", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "symlink", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "readlink", {STR, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "chmod", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fchmod", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "chown", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "fchown", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "lchown", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "umask", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "gettimeofday", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getrlimit", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getrusage", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sysinfo", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "times", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ptrace", {LONG, INT, PTR, PTR, UNDEF, UNDEF}, LONG },
{ "getuid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "syslog", {INT, STR, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "getgid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setuid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "geteuid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getegid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setpgid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getppid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getpgrp", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setsid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setreuid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setregid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getgroups", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setgroups", {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setresuid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "getresuid", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "setresgid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "getresgid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "getpgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setfsuid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setfsgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getsid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "capget", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "capset", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "rt_sigpending", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "rt_sigtimedwait", {PTR, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT },
{ "rt_sigqueueinfo", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "rt_sigsuspend", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sigaltstack", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "utime", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mknod", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "uselib", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "personality", {ULONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ustat", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "statfs", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fstatfs", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sysfs", {INT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "getpriority", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setpriority", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_setparam", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_getparam", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_setscheduler", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_getscheduler", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_get_priority_max", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_get_priority_min", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_rr_get_interval", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mlock", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "munlock", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mlockall", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "munlockall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "vhangup", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "modify_ldt", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, INT },
{ "pivot_root", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "_sysctl", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "prctl", {INT, ULONG, ULONG, ULONG, ULONG, UNDEF}, INT },
{ "arch_prctl", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "adjtimex", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setrlimit", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "chroot", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sync", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "acct", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "settimeofday", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mount", {STR, STR, STR, ULONG, PTR, UNDEF}, INT },
{ "umount2", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "swapon", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "swapoff", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "reboot", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
{ "sethostname", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "setdomainname", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "iopl", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ioperm", {ULONG, ULONG, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "create_module", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR },
{ "init_module", {PTR, ULONG, STR, UNDEF, UNDEF, UNDEF}, INT },
{ "delete_module", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "get_kernel_syms", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "query_module", {STR, INT, PTR, SIZE_T, SIZE_T, UNDEF}, INT },
{ "quotactl", {INT, STR, INT, PTR, UNDEF, UNDEF}, INT },
{ "nfsservctl", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, LONG },
{ "getpmsg", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "putpmsg", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "afs_syscall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "tuxcall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "security", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "gettid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "readahead", {INT, LONG, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T },
{ "setxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "lsetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "fsetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "getxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "lgetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "fgetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "listxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "llistxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "flistxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "removexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "lremovexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "fremovexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "tkill", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "time", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
{ "futex", {PTR, INT, INT, PTR, PTR, INT}, INT },
{ "sched_setaffinity", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "sched_getaffinity", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "set_thread_area", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "io_setup", {UINT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "io_destroy", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "io_getevents", {INT, LONG, LONG, PTR, PTR, UNDEF}, INT },
{ "io_submit", {INT, LONG, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "io_cancel", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "get_thread_area", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "lookup_dcookie", {ULONG, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT },
{ "epoll_create", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "epoll_ctl_old", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "epoll_wait_old", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "remap_file_pages", {PTR, SIZE_T, MAP_PROT, SIZE_T, INT, UNDEF}, INT },
{ "getdents64", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT },
{ "set_tid_address", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
{ "restart_syscall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "semtimedop", {INT, PTR, SIZE_T, PTR, UNDEF, UNDEF}, INT },
{ "fadvise64", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
{ "timer_create", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "timer_settime", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
{ "timer_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "timer_getoverrun", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "timer_delete", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "clock_settime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "clock_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "clock_getres", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "clock_nanosleep", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
{ "exit_group", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "epoll_wait", {INT, PTR, INT, INT, UNDEF, UNDEF}, INT },
{ "epoll_ctl", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
{ "tgkill", {INT, INT, SIGNO, UNDEF, UNDEF, UNDEF}, INT },
{ "utimes", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "vserver", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "mbind", {PTR, ULONG, INT, PTR, ULONG, UINT}, LONG },
{ "set_mempolicy", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, LONG },
{ "get_mempolicy", {INT, PTR, ULONG, PTR, ULONG, UNDEF}, INT },
{ "mq_open", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mq_unlink", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mq_timedsend", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, INT },
{ "mq_timedreceive", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, SSIZE_T },
{ "mq_notify", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "mq_getsetattr", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "kexec_load", {ULONG, ULONG, PTR, ULONG, UNDEF, UNDEF}, LONG },
{ "waitid", {INT, INT, PTR, INT, UNDEF, UNDEF}, INT },
{ "add_key", {STR, STR, PTR, SIZE_T, LONG, UNDEF}, LONG },
{ "request_key", {STR, STR, STR, LONG, UNDEF, UNDEF}, LONG },
{ "keyctl", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "ioprio_set", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "ioprio_get", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "inotify_init", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "inotify_add_watch", {INT, STR, UINT, UNDEF, UNDEF, UNDEF}, INT },
{ "inotify_rm_watch", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "migrate_pages", {INT, ULONG, PTR, PTR, UNDEF, UNDEF}, LONG },
{ "openat", {INT, STR, O_FLAGS, UNDEF, UNDEF, UNDEF}, INT },
{ "mkdirat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "mknodat", {INT, STR, INT, INT, UNDEF, UNDEF}, INT },
{ "fchownat", {INT, STR, UINT, INT, INT, UNDEF}, INT },
{ "futimesat", {INT, STR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "newfstatat", {INT, STR, STRUCT, INT, UNDEF, UNDEF}, INT },
{ "unlinkat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "renameat", {INT, STR, INT, STR, UNDEF, UNDEF}, INT },
{ "linkat", {INT, STR, INT, STR, INT, UNDEF}, INT },
{ "symlinkat", {STR, INT, STR, UNDEF, UNDEF, UNDEF}, INT },
{ "readlinkat", {INT, STR, STR, SIZE_T, UNDEF, UNDEF}, SSIZE_T },
{ "fchmodat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "faccessat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "pselect6", {INT, PTR, PTR, PTR, PTR, PTR}, INT },
{ "ppoll", {PTR, UINT, PTR, PTR, UNDEF, UNDEF}, INT },
{ "unshare", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "set_robust_list", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, LONG },
{ "get_robust_list", {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, LONG },
{ "splice", {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T },
{ "tee", {INT, INT, SIZE_T, UINT, UNDEF, UNDEF}, SSIZE_T },
{ "sync_file_range", {INT, LONG, LONG, UINT, UNDEF, UNDEF}, INT },
{ "vmsplice", {INT, PTR, ULONG, UINT, UNDEF, UNDEF}, SSIZE_T },
{ "move_pages", {INT, ULONG, PTR, INT, INT, INT}, LONG },
{ "utimensat", {INT, STR, PTR, INT, UNDEF, UNDEF}, INT },
{ "epoll_pwait", {INT, PTR, INT, INT, PTR, UNDEF}, INT },
{ "signalfd", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "timerfd_create", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "eventfd", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fallocate", {INT, INT, INT, INT, UNDEF, UNDEF}, INT },
{ "timerfd_settime", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
{ "timerfd_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "accept4", {INT, PTR, PTR, INT, UNDEF, UNDEF}, INT },
{ "signalfd4", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "eventfd2", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "epoll_create1", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "dup3", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT },
{ "pipe2", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "inotify_init1", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "preadv", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T },
{ "pwritev", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T },
{ "rt_tgsigqueueinfo", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT },
{ "perf_event_open", {PTR, INT, INT, INT, ULONG, UNDEF}, INT },
{ "recvmmsg", {INT, PTR, UINT, UINT, PTR, UNDEF}, INT },
{ "fanotify_init", {UINT, UINT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "fanotify_mark", {INT, UINT, ULONG, INT, STR, UNDEF}, INT },
{ "prlimit64", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT },
{ "name_to_handle_at", {INT, STR, PTR, INT, INT, UNDEF}, INT },
{ "open_by_handle_at", {INT, STR, PTR, INT, INT, UNDEF}, INT },
{ "clock_adjtime", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID },
{ "syncfs", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "sendmmsg", {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT },
{ "setns", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT },
{ "getcpu", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT },
{ "process_vm_readv", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T },
{ "process_vm_writev", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T },
{ "kcmp", {INT, INT, INT, ULONG, ULONG, UNDEF}, INT },
{ "finit_module", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT }
