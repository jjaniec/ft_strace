/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:47:30 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/07 19:41:20 by jjaniec          ###   ########.fr       */
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
# include <stdio.h>
# include <sys/mman.h> // mmap prot


// Buffer len used for path resolution of executables passed as arguments
# define PATH_RES_BUFF_LEN	1024

# define ERR_PREFIX			"[\e[31m*\e[39m] ft_strace: "
# define OK_PREFIX			"[\e[32m*\e[39m] ft_strace: "
# define INFO_PREFIX		"[\e[34m*\e[39m] "

// Number of chars to print before "..." if the string is longer
# define PRINTED_STR_LEN	32

# define STR_BUFFER_LEN		1024

# define PRE_SYSCALL_REGS	true
# define POST_SYSCALL_REGS	false

typedef struct	s_ft_strace_opts {
	int			c;
}				t_ft_strace_opts;

typedef struct	s_ft_strace_syscall {
	char		*name;
	char		*full_name;
	char		*libpath;
	int			reg_types[6];
	int			reg_ret_type;
}				t_ft_strace_syscall;

typedef struct s_ft_strace_flag_list {
	long			*flags;
	char			**flags_fmt;
	unsigned int	size;
}				t_ft_strace_flag_list;

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
	MAP
};

/*
** Documentation
** https://nullprogram.com/blog/2018/06/23/
*/

int			ft_strace(t_ft_strace_opts *opts, char *exec_path, char **exec_args, char **exec_environ);

char		*resolve_path(char *cmd, char **environ);

char		**parse_opts(t_ft_strace_opts *opts, int ac, char **av);

int			print_syscall_info(pid_t process, bool regs_type, \
				struct user_regs_struct *user_regs);

// ft_strerror.c

char		*ft_strerror(int errnum);

char		*tostring_errnum(int errnum);

int			format_reg_value(pid_t child, int type, unsigned long reg_value);

int			format_syscall_flags(pid_t child, unsigned long orig_rax, \
				int type, unsigned long reg_value);

#endif
