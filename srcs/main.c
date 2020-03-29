/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:07:13 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/29 21:48:46 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static void		show_usage(void)
{
	write(STDOUT_FILENO, INFO_PREFIX "Usage: ./ft_ptrace [-c syscall_count] -- binary arg1 arg2 arg3 ...\n", \
		ft_strlen(INFO_PREFIX) + 67);
}

int		main(int ac, char **av, char **environ)
{
	char				*exec_path;
	char				**cmd_args;
	t_ft_strace_opts	opts;

	(void)ac;
	(void)av;
	opts.c = -1;
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
	ft_printf(OK_PREFIX "Using binary: %s\n", exec_path);
	return (ft_strace(&opts, exec_path, cmd_args, environ));
}
