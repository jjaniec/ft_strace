/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:47:30 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/04 21:05:43 by jjaniec          ###   ########.fr       */
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

// Buffer len used for path resolution of executables passed as arguments
# define PATH_RES_BUFF_LEN	1024

# define ERR_PREFIX			"[\e[31m*\e[39m] ft_strace: "
# define OK_PREFIX			"[\e[32m*\e[39m] ft_strace: "
# define INFO_PREFIX		"[\e[34m*\e[39m] "

// Number of chars to print before "..." if the string is longer
# define PRINTED_STR_LEN	32

// Maximum number of chars to read from strings in text section, doesn't need to be high
// if PRINTED_STR_LEN is low
# define STR_BUFFER_LEN		64

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

// Syscall parameters / returns types

enum e_systypes	{
	INT,
	STR,
	SIZE_T,
	SSIZE_T,
	PTR,
	LONG,
	STRUCT,
	UINT,
	VOID,
	FLAGS,
	UNDEF,
	PROT,
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

#endif
