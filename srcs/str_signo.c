/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_signo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:19:12 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 16:19:44 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char		*sys_signame[] = {
	#include "./sys_signame.h"
};

char		*str_signo(int sig)
{
	return (sys_signame[sig]);
}
