/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:07:13 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/09 22:31:29 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static void		show_usage(void)
{
	dprintf(INFO_FD, INFO_PREFIX "Usage: ./ft_ptrace [-c] -- binary arg1 arg2 arg3 ...\n");
}

int		main(int ac, char **av, char **environ)
{
	char				*exec_path;
	char				**cmd_args;
	t_ft_strace_opts	opts;
	int					r;

	(void)ac;
	(void)av;
	opts.c = false;
	opts.d = -1;
	cmd_args = parse_opts(&opts, ac, av);
	if (!(ac > 1 && cmd_args && *cmd_args))
	{
		show_usage();
		return (1);
	}
	if (!(exec_path = resolve_path(*cmd_args, environ)))
	{
		write(STDERR_FILENO, ERR_PREFIX, ft_strlen(ERR_PREFIX));
		write(STDERR_FILENO, *cmd_args, ft_strlen(*cmd_args));
		write(STDERR_FILENO, ": not found\n", 12);
		return (1);
	}
	// dprintf(OK_FD, OK_PREFIX "Using binary: %s\n", exec_path);
	r = ft_strace(&opts, exec_path, cmd_args, environ);
	free(exec_path);
	return (r);
}
