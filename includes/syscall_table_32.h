[0] = {"restart_syscall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[1] = {"exit", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[2] = {"fork", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[3] = {"read", {INT, BUFFER, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[4] = {"write", {INT, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[5] = {"open", {STR, FLAGS, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[6] = {"close", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[7] = {"waitpid", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[8] = {"creat", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[9] = {"link", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[10] = {"unlink", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[11] = {"execve", {STR, STR, STR, UNDEF, UNDEF, UNDEF}, INT},
[12] = {"chdir", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[13] = {"time", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG},
[14] = {"mknod", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[15] = {"chmod", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[16] = {"lchown", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[19] = {"lseek", {INT, LONG, INT, UNDEF, UNDEF, UNDEF}, LONG},
[20] = {"getpid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[21] = {"mount", {STR, STR, STR, ULONG, PTR, UNDEF}, INT},
[23] = {"setuid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[24] = {"getuid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[26] = {"ptrace", {LONG, INT, PTR, PTR, UNDEF, UNDEF}, LONG},
[27] = {"alarm", {UINT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, UINT},
[29] = {"pause", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[30] = {"utime", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[33] = {"access", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[36] = {"sync", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[37] = {"kill", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[38] = {"rename", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[39] = {"mkdir", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[40] = {"rmdir", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[41] = {"dup", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[42] = {"pipe", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[43] = {"times", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[44] = {"prof", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[45] = {"brk", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR},
[46] = {"setgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[47] = {"getgid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[48] = {"signal", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[49] = {"geteuid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[50] = {"getegid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[51] = {"acct", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[52] = {"umount2", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[53] = {"lock", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[54] = {"ioctl", {INT, ULONG, STRUCT, UNDEF, UNDEF, UNDEF}, INT},
[55] = {"fcntl", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[56] = {"mpx", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[57] = {"setpgid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[58] = {"ulimit", {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, LONG},
[59] = {"oldolduname", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[60] = {"umask", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[61] = {"chroot", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[62] = {"ustat", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[63] = {"dup2", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[64] = {"getppid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[65] = {"getpgrp", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[66] = {"setsid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[67] = {"sigaction", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[68] = {"sgetmask", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG},
[69] = {"ssetmask", {LONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[70] = {"setreuid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[71] = {"setregid", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[72] = {"sigsuspend", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[73] = {"sigpending", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[74] = {"sethostname", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[75] = {"setrlimit", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[76] = {"getrlimit", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[77] = {"getrusage", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[78] = {"gettimeofday", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[79] = {"settimeofday", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[80] = {"getgroups", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[81] = {"setgroups", {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[82] = {"select", {INT, PTR, PTR, PTR, PTR, UNDEF}, INT},
[83] = {"symlink", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[84] = {"oldlstat", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[85] = {"readlink", {STR, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[86] = {"uselib", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[87] = {"swapon", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[88] = {"reboot", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT},
[89] = {"readdir", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, PTR},
[90] = {"mmap", {PTR, SIZE_T, MAP_PROT, FLAGS, INT, HEX} , PTR},
[91] = {"munmap", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[92] = {"truncate", {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[93] = {"ftruncate", {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[94] = {"fchmod", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[95] = {"fchown", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[96] = {"getpriority", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[97] = {"setpriority", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[99] = {"statfs", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[100] = {"fstatfs", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[101] = {"ioperm", {ULONG, ULONG, INT, UNDEF, UNDEF, UNDEF}, INT},
[102] = {"socketcall", {INT, ULONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[103] = {"syslog", {INT, STR, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[104] = {"setitimer", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[105] = {"getitimer", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[106] = {"stat", {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[107] = {"lstat", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[108] = {"fstat", {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[109] = {"olduname", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[110] = {"iopl", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[111] = {"vhangup", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[112] = {"idle", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[113] = {"vm86old", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[114] = {"wait4", {INT, PTR, INT, PTR, UNDEF, UNDEF} , INT},
[115] = {"swapoff", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[116] = {"sysinfo", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[117] = {"ipc", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[118] = {"fsync", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[119] = {"sigreturn", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[120] = {"clone", {INT, PTR, INT, PTR, UNDEF, UNDEF}, INT},
[121] = {"setdomainname", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[122] = {"uname", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[123] = {"modify_ldt", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, INT},
[124] = {"adjtimex", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[125] = {"mprotect", {PTR, SIZE_T, MAP_PROT, UNDEF, UNDEF, UNDEF}, INT},
[127] = {"create_module", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR},
[128] = {"init_module", {PTR, ULONG, STR, UNDEF, UNDEF, UNDEF}, INT},
[129] = {"delete_module", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[130] = {"get_kernel_syms", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[131] = {"quotactl", {INT, STR, INT, PTR, UNDEF, UNDEF}, INT},
[132] = {"getpgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[133] = {"fchdir", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[134] = {"bdflush", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[135] = {"sysfs", {INT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT},
[136] = {"personality", {ULONG, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[137] = {"afs_syscall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[138] = {"setfsuid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[139] = {"setfsgid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[140] = {"llseek", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[141] = {"getdents", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF} , INT},
[142] = {"newselect", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[143] = {"flock", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[144] = {"msync", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT},
[145] = {"readv", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[146] = {"writev", {INT, PTR, INT, UNDEF, UNDEF, UNDEF} , SSIZE_T},
[147] = {"getsid", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[148] = {"fdatasync", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[149] = {"_sysctl", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[150] = {"mlock", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[151] = {"munlock", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[152] = {"mlockall", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[153] = {"munlockall", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[154] = {"sched_setparam", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[155] = {"sched_getparam", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[156] = {"sched_setscheduler", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT},
[157] = {"sched_getscheduler", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[158] = {"sched_yield", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[159] = {"sched_get_priority_max", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[160] = {"sched_get_priority_min", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[161] = {"sched_rr_get_interval", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[162] = {"nanosleep", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[163] = {"mremap", {PTR, SIZE_T, SIZE_T, INT, PTR, UNDEF}, PTR},
[164] = {"setresuid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[165] = {"getresuid", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[166] = {"vm86", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[167] = {"query_module", {STR, INT, PTR, SIZE_T, SIZE_T, UNDEF}, INT},
[168] = {"poll", {PTR, UINT, INT, UNDEF, UNDEF, UNDEF}, INT},
[169] = {"nfsservctl", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, LONG},
[170] = {"setresgid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[171] = {"getresgid", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[172] = {"prctl", {INT, ULONG, ULONG, ULONG, ULONG, UNDEF}, INT},
[173] = {"rt_sigreturn", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[174] = {"rt_sigaction", {SIGNO, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[175] = {"rt_sigprocmask", {FLAGS, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT},
[176] = {"rt_sigpending", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[177] = {"rt_sigtimedwait", {PTR, PTR, PTR, SIZE_T, UNDEF, UNDEF}, INT},
[178] = {"rt_sigqueueinfo", {INT, INT, PTR, UNDEF, UNDEF, UNDEF}, INT},
[179] = {"rt_sigsuspend", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[180] = {"pread64", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T},
[181] = {"pwrite64", {INT, STR, SIZE_T, LONG, UNDEF, UNDEF}, SSIZE_T},
[182] = {"chown", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[183] = {"getcwd", {STR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, PTR},
[184] = {"capget", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[185] = {"capset", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[186] = {"sigaltstack", {PTR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[187] = {"sendfile", {INT, INT, UNDEF, LONG, UNDEF, UNDEF}, SSIZE_T},
[188] = {"getpmsg", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[189] = {"putpmsg", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[190] = {"vfork", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[191] = {"ugetrlimit", {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[192] = {"mmap2", {PTR, SIZE_T, MAP_PROT, FLAGS, INT, HEX} , PTR},
[193] = {"truncate64", {STR, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[194] = {"ftruncate64", {INT, LONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[195] = {"stat64", {STR, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[196] = {"lstat64", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[197] = {"fstat64", {INT, STRUCT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[198] = {"lchown32", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[199] = {"getuid32", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[200] = {"getgid32", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[201] = {"geteuid32", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[202] = {"getegid32", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[203] = {"setresuid32", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[204] = {"getresuid32", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[205] = {"getgroups32", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[206] = {"setgroups32", {SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[207] = {"fchown32", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[208] = {"setresuid32", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[209] = {"getresuid32", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[210] = {"setresgid32", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[211] = {"getresgid32", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[212] = {"chown32", {STR, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[213] = {"setuid32", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[214] = {"getuid32", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[215] = {"setfsuid32", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[216] = {"setfsgid32", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[217] = {"pivot_root", {STR, STR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[218] = {"mincore", {PTR, SIZE_T, STR, UNDEF, UNDEF, UNDEF}, INT},
[219] = {"madvise", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT},
[220] = {"getdents64", {UINT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT},
[221] = {"fcntl64", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[222] = {NULL, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[223] = {NULL, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[224] = {"gettid", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[225] = {"readahead", {INT, LONG, SIZE_T, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[226] = {"setxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[227] = {"lsetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[228] = {"fsetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[229] = {"getxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[230] = {"lgetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[231] = {"fgetxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[232] = {"listxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[233] = {"llistxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[234] = {"flistxattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[235] = {"removexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[236] = {"lremovexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[237] = {"fremovexattr", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[238] = {"tkill", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[239] = {"sendfile64", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[240] = {"futex", {PTR, INT, INT, PTR, PTR, INT}, INT},
[241] = {"sched_setaffinity", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT},
[242] = {"sched_getaffinity", {INT, SIZE_T, PTR, UNDEF, UNDEF, UNDEF}, INT},
[243] = {"set_thread_area", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[244] = {"get_thread_area", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[245] = {"io_setup", {UINT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[246] = {"io_destroy", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[247] = {"io_getevents", {INT, LONG, LONG, PTR, PTR, UNDEF}, INT},
[248] = {"io_submit", {INT, LONG, PTR, UNDEF, UNDEF, UNDEF}, INT},
[249] = {"io_cancel", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[250] = {"fadvise64", {INT, INT, INT, INT, UNDEF, UNDEF}, INT},
[251] = {NULL, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[252] = {"exit_group", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[253] = {"lookup_dcookie", {ULONG, STR, SIZE_T, UNDEF, UNDEF, UNDEF}, INT},
[254] = {"epoll_create", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[255] = {"epoll_ctl", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT},
[256] = {"epoll_wait", {INT, PTR, INT, INT, UNDEF, UNDEF}, INT},
[257] = {"remap_file_pages", {PTR, SIZE_T, MAP_PROT, SIZE_T, INT, UNDEF}, INT},
[258] = {"set_tid_address", {PTR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, LONG},
[259] = {"timer_create", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[260] = {"timer_settime", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT},
[261] = {"timer_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[262] = {"timer_getoverrun", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[263] = {"timer_delete", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[264] = {"clock_settime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF} , INT},
[265] = {"clock_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[266] = {"clock_getres", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[267] = {"clock_nanosleep", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT},
[268] = {"statfs64", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[269] = {"fstatfs64", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[270] = {"tgkill", {INT, INT, SIGNO, UNDEF, UNDEF, UNDEF}, INT},
[271] = {"utimes", {STR, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[273] = {"vserver", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[274] = {"mbind", {PTR, ULONG, INT, PTR, ULONG, UINT}, LONG},
[275] = {"get_mempolicy", {INT, PTR, ULONG, PTR, ULONG, UNDEF}, INT},
[276] = {"set_mempolicy", {INT, PTR, ULONG, UNDEF, UNDEF, UNDEF}, LONG},
[277] = {"mq_open", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[278] = {"mq_unlink", {STR, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[279] = {"mq_timedsend", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, INT},
[280] = {"mq_timedreceive", {INT, STR, SIZE_T, UINT, PTR, UNDEF}, SSIZE_T},
[281] = {"mq_notify", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[282] = {"mq_getsetattr", {INT, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[283] = {"kexec_load", {ULONG, ULONG, PTR, ULONG, UNDEF, UNDEF}, LONG},
[284] = {"waitid", {INT, INT, PTR, INT, UNDEF, UNDEF}, INT},
[285] = {NULL, {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[286] = {"add_key", {STR, STR, PTR, SIZE_T, LONG, UNDEF}, LONG},
[287] = {"request_key", {STR, STR, STR, LONG, UNDEF, UNDEF}, LONG},
[288] = {"keyctl", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[289] = {"ioprio_set", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[290] = {"ioprio_get", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[291] = {"inotify_init", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[292] = {"inotify_add_watch", {INT, STR, UINT, UNDEF, UNDEF, UNDEF}, INT},
[293] = {"inotify_rm_watch", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[294] = {"migrate_pages", {INT, ULONG, PTR, PTR, UNDEF, UNDEF}, LONG},
[295] = {"openat", {INT, STR, O_FLAGS, UNDEF, UNDEF, UNDEF}, INT},
[296] = {"mkdirat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT},
[297] = {"mknodat", {INT, STR, INT, INT, UNDEF, UNDEF}, INT},
[298] = {"fchownat", {INT, STR, UINT, INT, INT, UNDEF}, INT},
[299] = {"futimesat", {INT, STR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[300] = {"fstatat64", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[301] = {"unlinkat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT},
[302] = {"renameat", {INT, STR, INT, STR, UNDEF, UNDEF}, INT},
[303] = {"linkat", {INT, STR, INT, STR, INT, UNDEF}, INT},
[304] = {"symlinkat", {STR, INT, STR, UNDEF, UNDEF, UNDEF}, INT},
[305] = {"readlinkat", {INT, STR, STR, SIZE_T, UNDEF, UNDEF}, SSIZE_T},
[306] = {"fchmodat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT},
[307] = {"faccessat", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT},
[308] = {"pselect6", {INT, PTR, PTR, PTR, PTR, PTR} , INT},
[309] = {"ppoll", {PTR, UINT, PTR, PTR, UNDEF, UNDEF}, INT},
[310] = {"unshare", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[311] = {"set_robust_list", {PTR, SIZE_T, UNDEF, UNDEF, UNDEF, UNDEF}, LONG},
[312] = {"get_robust_list", {INT, PTR, SIZE_T, UNDEF, UNDEF, UNDEF}, LONG},
[313] = {"splice", {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T},
[314] = {"sync_file_range", {INT, LONG, LONG, UINT, UNDEF, UNDEF}, INT},
[315] = {"tee", {INT, INT, SIZE_T, UINT, UNDEF, UNDEF}, SSIZE_T},
[316] = {"vmsplice", {INT, PTR, ULONG, UINT, UNDEF, UNDEF}, SSIZE_T},
[317] = {"move_pages", {INT, ULONG, PTR, INT, INT, INT}, LONG},
[318] = {"getcpu", {PTR, PTR, PTR, UNDEF, UNDEF, UNDEF}, INT},
[319] = {"epoll_pwait", {INT, PTR, INT, INT, PTR, UNDEF}, INT},
[320] = {"utimensat", {INT, STR, PTR, INT, UNDEF, UNDEF}, INT},
[321] = {"signalfd", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[322] = {"timerfd_create", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[323] = {"eventfd", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[324] = {"fallocate", {INT, INT, INT, INT, UNDEF, UNDEF}, INT},
[325] = {"timerfd_settime", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT},
[326] = {"timerfd_gettime", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[327] = {"signalfd4", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[328] = {"eventfd2", {UINT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[329] = {"epoll_create1", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[330] = {"dup3", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[331] = {"pipe2", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[332] = {"inotify_init1", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[333] = {"preadv", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T},
[334] = {"pwritev", {INT, PTR, INT, LONG, UNDEF, UNDEF}, SSIZE_T},
[335] = {"rt_tgsigqueueinfo", {INT, INT, INT, PTR, UNDEF, UNDEF}, INT},
[336] = {"perf_event_open", {PTR, INT, INT, INT, ULONG, UNDEF}, INT},
[337] = {"recvmmsg", {INT, PTR, UINT, UINT, PTR, UNDEF}, INT},
[338] = {"fanotify_init", {UINT, UINT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[339] = {"fanotify_mark", {INT, UINT, ULONG, INT, STR, UNDEF}, INT},
[340] = {"prlimit64", {INT, INT, PTR, PTR, UNDEF, UNDEF}, INT},
[341] = {"name_to_handle_at", {INT, STR, PTR, INT, INT, UNDEF}, INT},
[342] = {"open_by_handle_at", {INT, STR, PTR, INT, INT, UNDEF}, INT},
[343] = {"clock_adjtime", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[344] = {"syncfs", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[345] = {"sendmmsg", {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT},
[346] = {"setns", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[347] = {"process_vm_readv", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T},
[348] = {"process_vm_writev", {INT, PTR, ULONG, PTR, ULONG, ULONG}, SSIZE_T},
[349] = {"kcmp", {INT, INT, INT, ULONG, ULONG, UNDEF} , INT},
[350] = {"finit_module", {INT, STR, INT, UNDEF, UNDEF, UNDEF}, INT},
[351] = {"sched_setattr", {INT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT},
[352] = {"sched_getattr", {INT, PTR, UINT, UINT, UNDEF, UNDEF}, INT},
[353] = {"renameat2", {INT, STR, INT, STR, UINT, UNDEF}, INT},
[354] = {"seccomp", {UINT, UINT, PTR, UNDEF, UNDEF, UNDEF}, INT},
[355] = {"getrandom", {STR, SIZE_T, UINT, UNDEF, UNDEF, UNDEF}, INT},
[356] = {"memfd_create", {STR, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[357] = {"bpf", {INT, PTR, UINT, UNDEF, UNDEF, UNDEF}, INT},
[358] = {"execveat", {INT, STR, STR, STR, INT, UNDEF}, INT},
[359] = {"socket", {INT, INT, INT, UNDEF, UNDEF, UNDEF}, INT},
[360] = {"socketpair", {INT, INT, INT, INT, UNDEF, UNDEF}, INT},
[361] = {"bind", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[362] = {"connect", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[363] = {"listen", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[364] = {"accept4", {INT, PTR, PTR, INT, UNDEF, UNDEF}, INT},
[365] = {"getsockopt", {INT, INT, INT, PTR, INT, UNDEF}, INT},
[366] = {"setsockopt", {INT, INT, INT, PTR, INT, UNDEF}, INT},
[367] = {"getsockname", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[368] = {"getpeername", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, INT},
[369] = {"sendto", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T},
[370] = {"sendmsg", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[371] = {"recvfrom", {INT, STR, SIZE_T, INT, PTR, INT}, SSIZE_T},
[372] = {"recvmsg", {INT, PTR, INT, UNDEF, UNDEF, UNDEF}, SSIZE_T},
[373] = {"shutdown", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[374] = {"userfaultfd", {UNDEF, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, VOID},
[375] = {"membarrier", {INT, INT, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[376] = {"mlock2", {PTR, SIZE_T, INT, UNDEF, UNDEF, UNDEF}, INT},
[377] = {"copy_file_range", {INT, LONG, INT, LONG, SIZE_T, UINT}, SSIZE_T},
[378] = {"preadv2", {INT, PTR, INT, LONG, INT, UNDEF}, SSIZE_T},
[379] = {"pwritev2", {INT, PTR, INT, LONG, INT, UNDEF}, SSIZE_T},
[380] = {"pkey_mprotect", {PTR, SIZE_T, INT, INT, UNDEF, UNDEF}, INT},
[381] = {"pkey_alloc", {ULONG, ULONG, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[382] = {"pkey_free", {INT, UNDEF, UNDEF, UNDEF, UNDEF, UNDEF}, INT},
[383] = {"statx", {INT, STR, INT, UINT, STRUCT, UNDEF}, INT},
[384] = {"arch_prctl", {INT, PTR, UNDEF, UNDEF, UNDEF, UNDEF}, INT},