/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syscall_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:34:28 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/11 19:14:21 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

t_ft_strace_syscall	g_syscall_table_64[329] = {
	#include "syscall_table_64.h"
};

/*
** Format & print info on user registers
** https://docs.huihoo.com/doxygen/linux/kernel/3.7/structuser__regs__struct.html
*/

static int		handle_invalid_syscall_id(pid_t process, struct user_regs_struct *pre_user_regs)
{
	ft_printf(ERR_PREFIX "[%d] => Invalid syscall id: %ld", \
		process, pre_user_regs->orig_rax);
	return (0);
}

/*
** Cycle through syscall parameters and print it with format_reg_value()
*/

static int		cycle_syscall_params(pid_t child, unsigned long orig_rax, \
					int syscall_reg_types[6], unsigned long pre_user_regs[6])
{
	write(STDOUT_FILENO, "(", 1);
	for (unsigned int i = 0; i < 6 && syscall_reg_types[i] != UNDEF; i++)
	{
		if (i)
			write(STDOUT_FILENO, ", ", 2);
		if (ft_int_index((int []) {
				FLAGS, MAP_PROT
			}, 2, syscall_reg_types[i]) != -1)
			format_syscall_flags(child, orig_rax, syscall_reg_types[i], pre_user_regs[i]);
		else if (format_reg_value(child, syscall_reg_types[i], pre_user_regs[i]) == 0)
			break ;
	}
	return (0);
}

/*
** Print values contained in the registers before calling the syscall
*/

static int		print_valid_pre_syscall(pid_t process, struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table)
{
	fflush(stdout);
	ft_printf(INFO_PREFIX "[%d] => (%3ld) %s", \
		process, user_regs->orig_rax, table[user_regs->orig_rax].name);
	cycle_syscall_params(process, user_regs->orig_rax, \
		table[user_regs->orig_rax].reg_types, \
		(unsigned long[6]) {
			user_regs->rdi, user_regs->rsi, user_regs->rdx, \
			user_regs->r10, user_regs->r8, user_regs->r9
		});
	return (0);
}

/*
** Print values contained in the registers after calling the syscall
**
** https://stackoverflow.com/questions/29047592/accessing-errno-h-in-assembly-language
*/

static int		print_valid_post_syscall(pid_t process, struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table)
{
	fflush(stdout);
	write(STDOUT_FILENO, ") = ", 4);
	if (table[user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)user_regs->rax && (int)user_regs->rax <= -1))
		ft_printf("-1 %s (%s)", tostring_errnum(-user_regs->rax), ft_strerror(-user_regs->rax));
	else
		format_reg_value(process, table[user_regs->orig_rax].reg_ret_type, user_regs->rax);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}



int				print_syscall_info(pid_t process, bool regs_type, \
					struct user_regs_struct *user_regs)
{
	t_ft_strace_syscall				*table;
	// t_ft_strace_syscall_exec_info	*exec_infos;

	table = g_syscall_table_64;
	// exec_infos = malloc(sizeof(t_ft_strace_syscall_exec_info) * (sizeof(table) / sizeof(table[0]));
	if (regs_type == PRE_SYSCALL_REGS)
	{
		if (user_regs->orig_rax < ( sizeof(g_syscall_table_64) / sizeof(t_ft_strace_syscall) ))
			print_valid_pre_syscall(process, user_regs, table);
		else
			handle_invalid_syscall_id(process, user_regs);
	}
	else if (regs_type == POST_SYSCALL_REGS)
		return (print_valid_post_syscall(process, user_regs, table));
	return (0);
}
