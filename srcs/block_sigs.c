/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sigs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 20:24:35 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 20:34:13 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

int			block_sigs(void)
{
	sigset_t	sigmask;

	if (sigemptyset(&sigmask) < 0)
	{
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}
	if (sigaddset(&sigmask, SIGINT) < 0 || \
		sigaddset(&sigmask, SIGQUIT) < 0 || \
		sigaddset(&sigmask, SIGTERM) < 0 || \
		sigaddset(&sigmask, SIGHUP) < 0 || \
		sigaddset(&sigmask, SIGPIPE) < 0)
	{
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}
	if (sigprocmask(SIG_BLOCK, &sigmask, NULL) < 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}
	return (0);
}
