/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_calls_summary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 18:46:21 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/11 20:29:42 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

extern t_ft_strace_syscall	g_syscall_table_64[329];

int		show_calls_summary(t_ft_strace_syscall *table, size_t table_size, \
			t_ft_strace_syscall_exec_info *exec_infos)
{
	unsigned int	total_calls;
	unsigned int	total_errors;

	total_calls = 0;
	total_errors = 0;
	dprintf(STDOUT_FILENO, "%6s %11s %11s %9s %9s syscall\n", \
		"% time", "seconds", "usecs/call", "calls", "errors");
	dprintf(STDOUT_FILENO, "------ ----------- ----------- --------- --------- ----------------\n");
	for (size_t i = 0; i < table_size; i++)
	{
		if (exec_infos[i].calls != 0)
		{
			dprintf(STDOUT_FILENO, "%6u %11u %11u %9u %9u %s\n", \
				0, 0, 0, \
				exec_infos[i].calls, exec_infos[i].errors, table[i].name);
			total_calls += exec_infos[i].calls;
			total_errors += exec_infos[i].errors;
		}
	}
	dprintf(STDOUT_FILENO, "------ ----------- ----------- --------- --------- ----------------\n");
	dprintf(STDOUT_FILENO, "100.00 %11u %11u %9u %9u total\n", 0, 0, total_calls, total_errors);
	return (0);
}
