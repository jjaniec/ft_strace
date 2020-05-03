/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 19:36:17 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/03 19:36:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

void		timeval_sub(struct timeval *r, \
				struct timeval *tv1, struct timeval *tv2)
{
	r->tv_sec = tv1->tv_sec - tv2->tv_sec;
	r->tv_usec = tv1->tv_usec - tv2->tv_usec;
	if (((long) r->tv_usec) < 0)
	{
		r->tv_sec--;
		r->tv_usec += 1000000;
	}
}
