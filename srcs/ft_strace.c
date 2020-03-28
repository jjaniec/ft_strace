/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:08:56 by jjaniec           #+#    #+#             */
/*   Updated: 2020/03/28 17:09:40 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static int	handle_execve_err(void)
{
	if (errno == EACCES)
		write(STDERR_FILENO, ERR_PREFIX "Execution failed (EACCESS)\n", \
			ft_strlen(ERR_PREFIX) + 27);
	return (1);
}

static int	child_process_tasks(char *exec_path, char **exec_args, char **exec_environ)
{
	if (execve(exec_path, exec_args, exec_environ) == -1)
		return (handle_execve_err());
	return (1);
}

static int	handle_child(pid_t child)
{
	long	orig_rax;
	int		status;

	while (1)
	{
		waitpid(child, &status, 0);
		if (WIFEXITED(status))
		{
			ft_printf(INFO_PREFIX "Child exited with code: %d\n", status);
			return (0);
		}
		if ((orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX, NULL)) == -1)
			perror("ptrace");
		printf("Syscall id: %ld\n", orig_rax);
		ptrace(PTRACE_CONT, child, NULL, NULL);
	}
	return (1);
}

int			ft_strace(char *exec_path, char **exec_args, char **exec_environ)
{
	pid_t	child;

	ptrace(PTRACE_TRACEME, 0, NULL, NULL);
	if ((child = fork() == -1))
	{
		write(STDERR_FILENO, ERR_PREFIX "Fork failed!\n", ft_strlen(ERR_PREFIX) + 13);
		return (1);
	}
	else if (child == 0)
		return (child_process_tasks(exec_path, exec_args, exec_environ));
	ft_printf(INFO_PREFIX "Child pid: %d\n", child);
	return (handle_child(child));
}
