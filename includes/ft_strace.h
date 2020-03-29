/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:47:30 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/29 21:47:16 by jjaniec          ###   ########.fr       */
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

// Buffer len used for path resolution of executables passed as arguments
# define PATH_RES_BUFF_LEN	1024

# define ERR_PREFIX			"[\e[31m*\e[39m] ft_strace: "
# define OK_PREFIX			"[\e[32m*\e[39m] ft_strace: "
# define INFO_PREFIX		"[\e[34m*\e[39m] "

typedef struct	s_ft_strace_opts {
	int			c;
}				t_ft_strace_opts;

/*
** Documentation
** https://nullprogram.com/blog/2018/06/23/
*/

int			ft_strace(t_ft_strace_opts *opts, char *exec_path, char **exec_args, char **exec_environ);

char		*resolve_path(char *cmd, char **environ);

char		**parse_opts(t_ft_strace_opts *opts, int ac, char **av);

#endif
