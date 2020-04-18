/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:47:30 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 20:56:18 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRACE_H
# define FT_STRACE_H

# include <ft_printf.h>

# include <errno.h>
# include <sys/types.h>
# include <sys/ptrace.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/reg.h>
# include <sys/user.h>
# include <stdio.h> //printf
# include <sys/mman.h> // mmap prot
# include <string.h> //strsignal
# include <signal.h> // signal definitions
# include <elf.h>
# include <fcntl.h>


// Buffer len used for path resolution of executables passed as arguments
# define PATH_RES_BUFF_LEN	1024

# define ERR_PREFIX			"[\e[31m*\e[39m] ft_strace: "
# define OK_PREFIX			"[\e[32m*\e[39m] ft_strace: "
# define INFO_PREFIX		"[\e[34m*\e[39m] "

# define ERR_FD				STDERR_FILENO
# define OK_FD				STDERR_FILENO
# define INFO_FD			STDERR_FILENO

// Number of chars to print before "..." if the string is longer
# define PRINTED_STR_LEN	32

# define STR_BUFFER_LEN		1024

# define PRE_SYSCALL_REGS	true
# define POST_SYSCALL_REGS	false

typedef struct	s_ft_strace_opts {
	bool		c : 1;
	int			d;
}				t_ft_strace_opts;

typedef struct	s_ft_strace_syscall {
	char		*name;
	// char		*full_name;
	// char		*libpath;
	int			reg_types[6];
	int			reg_ret_type;
}				t_ft_strace_syscall;

typedef struct		 s_ft_strace_flag_list {
	long			*flags;
	char			**flags_fmt;
	unsigned int	size;
}					t_ft_strace_flag_list;

typedef struct s_ft_strace_syscall_exec_info {
	useconds_t		tot_usecs;
	unsigned int	calls;
	unsigned int	errors;
}					t_ft_strace_syscall_exec_info;

// Map prot flags values & format

# define MAP_PROT_LEN		4

# define MAP_PROT_VALUES	(long[]) { \
	PROT_NONE, PROT_READ, PROT_EXEC, PROT_WRITE \
}

# define MAP_PROT_FMT		(char*[]) { \
	"PROT_NONE", "PROT_READ", "PROT_EXEC", "PROT_WRITE" \
}

# define MAP_FLAGS_LEN		15

# define MAP_FLAGS_VALUES	(long[]) { \
	MAP_SHARED, MAP_PRIVATE, MAP_32BIT, MAP_FIXED, MAP_ANONYMOUS, \
	MAP_EXECUTABLE, MAP_FILE, MAP_DENYWRITE, MAP_GROWSDOWN, MAP_HUGETLB, \
	MAP_LOCKED, MAP_NONBLOCK, MAP_NORESERVE, MAP_POPULATE, MAP_STACK \
}

# define MAP_FLAGS_FMT		(char*[]) { \
	"MAP_SHARED", "MAP_PRIVATE", "MAP_32BIT", "MAP_FIXED", "MAP_ANONYMOUS", \
	"MAP_EXECUTABLE", "MAP_FILE", "MAP_DENYWRITE", "MAP_GROWSDOWN", "MAP_HUGETLB", \
	"MAP_LOCKED", "MAP_NONBLOCK", "MAP_NORESERVE", "MAP_POPULATE", "MAP_STACK" \
}

# define O_FLAGS_LEN			13

# define O_FLAGS_VALUES (long[]) { \
	O_RDONLY, O_WRONLY, O_RDWR, O_ACCMODE, O_NONBLOCK, \
	O_APPEND, O_ASYNC, O_FSYNC, O_NOFOLLOW, O_CREAT, \
	O_TRUNC, O_EXCL, O_CLOEXEC \
}

# define O_FLAGS_FMT (char*[]) { \
	"O_RDONLY", "O_WRONLY", "O_RDWR", "O_ACCMODE", "O_NONBLOCK", \
	"O_APPEND", "O_ASYNC", "O_FSYNC", "O_NOFOLLOW", "O_CREAT", \
	"O_TRUNC", "O_EXCL", "O_CLOEXEC" \
}


// Syscall parameters / returns types

enum e_systypes	{
	INT,
	STR,
	STR_TAB,
	SIZE_T,
	SSIZE_T,
	PTR,
	LONG,
	STRUCT,
	UINT,
	VOID,
	FLAGS,
	UNDEF,
	MAP_PROT,
	HEX,
	ULONG,
	MAP,
	SIGNO,
	O_FLAGS,
	BUFFER
};

/*
** Documentation
** https://nullprogram.com/blog/2018/06/23/
*/

/*
** Init tasks
*/

char			*resolve_path(char *cmd, char **environ);

char			**parse_opts(t_ft_strace_opts *opts, int ac, char **av);

unsigned char	get_binary_architecture(const char *abspath);

/*
** Main loop
*/

int			ft_strace(t_ft_strace_opts *opts, char *exec_path, char **exec_args, char **exec_environ);

int			handle_next_syscall(pid_t child, unsigned char bin_elf_class, \
				int *status, t_ft_strace_syscall *table, \
				struct user_regs_struct *pre_user_regs, struct user_regs_struct *post_user_regs);


int			print_syscall_info(pid_t process, bool regs_type, \
				unsigned char bin_elf_class, \
				struct user_regs_struct *user_regs, \
				t_ft_strace_syscall *table,
				unsigned int regs_offset, unsigned int regs_max_count);

char		*format_reg_value(pid_t child, int type, unsigned long reg_value);

char		*get_fmt_flags(pid_t child, unsigned char bin_elf_class, \
				unsigned long orig_rax, int type, \
				unsigned long reg_value);

int			handle_wait_status(pid_t child, int status);

int			show_calls_summary(t_ft_strace_syscall *table, size_t table_size, \
				t_ft_strace_syscall_exec_info *exec_infos);

/*
** Errno
*/

char		*ft_strerror(int errnum);

char		*tostring_errnum(int errnum);

/*
** Signals
*/

int			allow_sigs(void);

int			block_sigs(void);

char		*str_signo(int sig);

#endif
