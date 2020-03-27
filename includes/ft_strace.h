/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:11:27 by joffreyjani       #+#    #+#             */
/*   Updated: 2020/03/27 19:58:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PTRACE_H
# define FT_PTRACE_H

# include <ft_printf.h>

# include <sys/types.h>
# include <sys/ptrace.h>
# include <sys/stat.h>

// Buffer len used for path resolution of executables passed as arguments
# define PATH_RES_BUFF_LEN	1024

char		*resolve_path(char *cmd, char **environ);

#endif
