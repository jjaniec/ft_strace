/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_calls_summary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 18:46:21 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/23 20:51:39 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

extern t_ft_strace_syscall				g_syscall_table_64[329];

static double		timeval_float(const struct timeval *tv)
{
	return (tv->tv_sec + tv->tv_usec / 1000000.0);
}

static void			timeval_div(struct timeval *r, const struct timeval *tv1, unsigned int n)
{
	r->tv_usec = (tv1->tv_sec % n * 1000000 + tv1->tv_usec + n / 2) / n;
	r->tv_sec = tv1->tv_sec / n + r->tv_usec / 1000000;
	r->tv_usec %= 1000000;
}

int					show_calls_summary(size_t table32_size, t_ft_strace_syscall *table32, \
						size_t table64_size, t_ft_strace_syscall *table64, \
						t_ft_strace_syscall_exec_info ***exec_infos)
{
	unsigned int	total_calls;
	unsigned int	total_errors;
	unsigned int	table_index;
	double			float_time;
	struct timeval	syscall_time_by_calls;

	table_index = 0;
	while (table_index <= 1 && exec_infos && *exec_infos && (*exec_infos)[table_index])
	{
		total_calls = 0;
		total_errors = 0;
		if (table_index == 1)
			dprintf(INFO_FD, "System call usage summary for 32 bit mode:\n");
		dprintf(INFO_FD, "%6s %11s %11s %9s %9s syscall\n", \
			"% time", "seconds", "usecs/call", "calls", "errors");
		dprintf(INFO_FD, "------ ----------- ----------- --------- --------- ----------------\n");
		// dprintf(INFO_FD, "Table32 size: %zu, table64 size: %zu\n", table32_size, table64_size);
		for (size_t i = 0; ((table_index == 0 && i < table64_size) || \
			(table_index == 1 && i < table32_size)); i++)
		{
			if ((*exec_infos)[table_index][i].calls != 0)
			{
				ft_memset(&syscall_time_by_calls, 0, sizeof(struct timeval));
				float_time = timeval_float(&(*exec_infos)[table_index][i].time);
				timeval_div(&syscall_time_by_calls, \
					&(*exec_infos)[table_index][i].time, (*exec_infos)[table_index][i].calls);
				dprintf(INFO_FD, "%6.2f %11.6f %11lu %9u %9.0u %s\n", \
					100 * float_time, \
					float_time, \
					(long)(1000000 * syscall_time_by_calls.tv_sec + syscall_time_by_calls.tv_usec), \
					(*exec_infos)[table_index][i].calls, \
					(*exec_infos)[table_index][i].errors, \
					(table_index == 0) ? (table64[i].name) : (table32[i].name));
				total_calls += (*exec_infos)[table_index][i].calls;
				total_errors += (*exec_infos)[table_index][i].errors;
			}
		}
		dprintf(INFO_FD, "------ ----------- ----------- --------- --------- ----------------\n");
		dprintf(INFO_FD, "100.00 %11.6d %11.0u %9u %9.0u total\n", \
			0, 0, total_calls, total_errors);
		free((*exec_infos)[table_index]);
		(*exec_infos)[table_index] = NULL;
		table_index++;
	}
	free(*exec_infos);
	*exec_infos = NULL;
	return (0);
}
