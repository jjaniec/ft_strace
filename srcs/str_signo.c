/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_signo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:19:12 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 16:52:10 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char		*sys_signame[] = {
	#include "./sys_signame.h"
};

char		*str_signo(int sig)
{
	// printf("SIGRTMIN: %d - sig: %d\n", SIGRTMIN, sig);
	if (sig <= 31)
		return (sys_signame[sig]);
	if (sig - 32 + SIGRTMIN == SIGRTMAX)
		return ("RTMAX");
	if (sig - 32 + SIGRTMIN >= SIGRTMIN)
		return (sys_signame[sig - 32 + 34]);
	return ("UNKNOWN");
}
