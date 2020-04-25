/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 19:47:02 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/25 18:40:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char 		*g_errno_table[][2] = {
	#include "ft_errnoent.h"
};

char		*ft_strerror(int errnum)
{
	return (\
		(errnum > 0 && errnum < \
			(int)(sizeof(g_errno_table) / sizeof(g_errno_table[0]))) ? \
		g_errno_table[errnum][1] : \
		NULL
	);
}

char		*tostring_errnum(int errnum)
{
	return (
		(errnum > 0 && errnum < \
			(int)(sizeof(g_errno_table) / sizeof(g_errno_table[0]))) ? \
		g_errno_table[errnum][0] : \
		NULL
	);
}
