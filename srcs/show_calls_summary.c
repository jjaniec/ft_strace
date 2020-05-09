/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_calls_summary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 18:46:21 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/09 19:37:01 by jjaniec          ###   ########.fr       */
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

static void			ft_swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int			*get_sorted_index(t_ft_strace_syscall *table, \
						size_t table_size, \
						t_ft_strace_syscall_exec_info *exec_infos)
{
	int		*sorted_index;
	int		i;
	int		cmpi;

	i = 1;
	sorted_index = ft_range(0, (int)table_size);
	while (table && i < table_size)
	{
		cmpi = i;
		while (cmpi > 0) {
			if (timercmp(\
						&(exec_infos[sorted_index[cmpi - 1]]).time, \
						&(exec_infos[sorted_index[cmpi]]).time, \
						< \
					) && cmpi > 0)
			{
				ft_swap_int(sorted_index + (cmpi - 1), sorted_index + cmpi);
				cmpi--;
			}
			else break ;
		}
		i++;
	}
	// printf("[");
	// for (int k = 0; k < table_size; k++)
	// 	printf("%d (%zu), ", sorted_index[k], exec_infos[sorted_index[k]].time.tv_usec);
	// printf("]\n");
	return sorted_index;
}

static void				print_syscall_line(t_ft_strace_syscall *syscall, \
							t_ft_strace_syscall_exec_info *syscall_infos, \
							struct timeval *total_time, unsigned int *total_calls, unsigned int *total_errors)
{
	struct timeval	syscall_time_by_calls;
	double			syscall_float_time;

	if (!syscall)
		return ;
	ft_memset(&syscall_time_by_calls, 0, sizeof(struct timeval));
	syscall_float_time = timeval_float(&(syscall_infos->time));
	timeval_div(&syscall_time_by_calls, &(syscall_infos->time), (syscall_infos->calls));
	dprintf(INFO_FD, "%6.2f %11.6f %11lu %9u %9.0u %s\n", \
		((100.0 * syscall_float_time) != 0.0) ? ((100.0 * syscall_float_time) / timeval_float(total_time)) : (100.0 * syscall_float_time), \
		syscall_float_time, \
		(long)(1000000 * syscall_time_by_calls.tv_sec + syscall_time_by_calls.tv_usec), \
		syscall_infos->calls, \
		syscall_infos->errors, \
		syscall->name);
	*total_calls += syscall_infos->calls;
	*total_errors += syscall_infos->errors;
}

int						show_calls_summary(size_t table32_size, t_ft_strace_syscall *table32, \
							size_t table64_size, t_ft_strace_syscall *table64, \
							t_ft_strace_syscall_exec_info ***exec_infos)
{
	unsigned int	total_calls;
	unsigned int	total_errors;
	struct timeval	total_time;
	unsigned int	table_index;
	int				*sorted_index;
	int				i;

	table_index = 0;
	while (table_index <= 1 && exec_infos && *exec_infos && (*exec_infos)[table_index])
	{
		total_calls = 0;
		total_errors = 0;
		ft_memset(&total_time, 0, sizeof(total_time));
		for (size_t i = 0; ((table_index == 0 && i < (int)table64_size) || \
			(table_index == 1 && i < (int)table32_size)); i++)
			timeval_add(&total_time, &total_time, &((*exec_infos)[table_index][i].time));
		if (table_index == 1)
		{
			dprintf(INFO_FD, "System call usage summary for 32 bit mode:\n");
			sorted_index = get_sorted_index(table32, table32_size, (*exec_infos)[1]);
		}
		else
			sorted_index = get_sorted_index(table64, table64_size, (*exec_infos)[0]);
		dprintf(INFO_FD, "%6s %11s %11s %9s %9s syscall\n", \
			"% time", "seconds", "usecs/call", "calls", "errors");
		dprintf(INFO_FD, "------ ----------- ----------- --------- --------- ----------------\n");
		i = 0;
		while ((*exec_infos)[table_index][sorted_index[i]].calls != 0 && \
			((table_index == 0 && i < table64_size) || \
			(table_index == 1 && i < table32_size)))
		{
			print_syscall_line((table_index == 0) ? \
					(&table64[sorted_index[i]]) : (&table32[sorted_index[i]]), \
				&(*exec_infos)[table_index][sorted_index[i]], \
				&total_time, &total_calls, &total_errors);
			i++;
		}
		dprintf(INFO_FD, "------ ----------- ----------- --------- --------- ----------------\n");
		dprintf(INFO_FD, "100.00%12.6f %11.0u %9u %9.0u total\n", \
			timeval_float(&total_time), 0, total_calls, total_errors);
		free((*exec_infos)[table_index]);
		(*exec_infos)[table_index] = NULL;
		table_index++;
		free(sorted_index);
	}
	free(*exec_infos);
	*exec_infos = NULL;
	return (0);
}
