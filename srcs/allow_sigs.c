/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allow_sigs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 20:24:14 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 20:34:02 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

int			allow_sigs(void)
{
	sigset_t	sigmask;

	if (sigemptyset(&sigmask) < 0)
	{
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}
	if (sigprocmask(SIG_SETMASK, &sigmask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	return (0);
}
