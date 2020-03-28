/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:07:13 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/29 00:01:54 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static int		show_usage(void)
{
	write(STDOUT_FILENO, OK_PREFIX "Usage: ./ft_ptrace [-hc] binary\n", \
		ft_strlen(OK_PREFIX) + 32);
}

int		main(int ac, char **av, char **environ)
{
	char	*exec_path;

	(void)ac;
	(void)av;
	if (!(ac > 1))
	{
		show_usage();
		return (1);
	}
	if (!(exec_path = resolve_path(av[1], environ)))
	{
		write(STDERR_FILENO, ERR_PREFIX, ft_strlen(ERR_PREFIX));
		write(STDERR_FILENO, av[1], ft_strlen(av[1]));
		write(STDERR_FILENO, ": not found\n", 11);
	}
	ft_printf(OK_PREFIX "Using binary: %s\n", exec_path);
	return (ft_strace(exec_path, (char *[2]){exec_path, NULL}, environ));
}
