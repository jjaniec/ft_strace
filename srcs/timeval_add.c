/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:16:26 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/25 16:16:33 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

void		timeval_add(struct timeval *r, struct timeval *tv1, struct timeval *tv2)
{
	r->tv_sec = \
		tv1->tv_sec + \
		tv2->tv_sec;
	r->tv_usec = tv1->tv_usec + tv2->tv_usec;
	if (r->tv_usec >= 1000000)
	{
		r->tv_sec++;
		r->tv_usec -= 1000000;
	}
}
