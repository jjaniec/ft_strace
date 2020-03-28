/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:47:30 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/28 16:47:40 by jjaniec          ###   ########.fr       */
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

# define ERR_PREFIX			"\e[31mft_strace\e[39m: "
# define INFO_PREFIX		"\e[39mft_strace\e[39m: "

int			ft_strace(char *exec_path, char **exec_args, char **exec_environ);

char		*resolve_path(char *cmd, char **environ);

#endif
