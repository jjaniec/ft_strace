/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syscall_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 16:34:28 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 20:20:39 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

extern t_ft_strace_syscall	g_syscall_table_64[314];

extern t_ft_strace_syscall	g_syscall_table_32[385];

extern t_ft_strace_opts		*g_ft_strace_opts;

/*
** Format & print info on user registers
** https://docs.huihoo.com/doxygen/linux/kernel/3.7/structuser__regs__struct.html
*/

static int		handle_invalid_syscall_id(pid_t process, struct user_regs_struct *pre_user_regs)
{
	dprintf(ERR_FD, ERR_PREFIX "[%d] => Invalid syscall id: %lld", \
		process, pre_user_regs->orig_rax);
	return (0);
}

/*
** Cycle through syscall parameters and print it with format_reg_value()
*/

static char		*cycle_syscall_params(pid_t child, unsigned char bin_elf_class, \
					unsigned long orig_rax, int syscall_reg_types[6], \
					unsigned long pre_user_regs[6], unsigned int regs_max_count)
{
	char	*ret;
	char	*s;
	char	*tmp;

	ret = NULL;
	// write(INFO_FD, "(", 1);
	for (unsigned int i = 0; i < regs_max_count && syscall_reg_types[i] != UNDEF; i++)
	{
		s = NULL;
		// if (i)
			// write(INFO_FD, ", ", 2);
		if (ft_int_index((int []) { \
				FLAGS, MAP_PROT, O_FLAGS \
			}, 3, syscall_reg_types[i]) != -1)
			s = get_fmt_flags(child, bin_elf_class, orig_rax, syscall_reg_types[i], pre_user_regs[i]);
		else if (!(s = format_reg_value(child, syscall_reg_types[i], pre_user_regs[i])))
			break ;
		if (i)
		{
			tmp = ret;
			asprintf(&ret, "%s, %s", ret, s);
			free(s);
			free(tmp);
		}
		else
		{
			asprintf(&ret, "%s", s);
			free(s);
		}
	}
	return (ret);
}

/*
** Print values contained in the registers before calling the syscall
*/

static int		print_valid_pre_syscall(pid_t process, unsigned char bin_elf_class, \
					struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table, \
					unsigned int regs_offset, unsigned int regs_max_count)
{
	int		printed;
	char	*ret;

		// dprintf(INFO_FD, INFO_PREFIX "[%d] => (%3lld) %s", \
		// 	process, user_regs->orig_rax, table[user_regs->orig_rax].name);
	printed = 0;
	if (bin_elf_class == ELFCLASS32)
		ret = cycle_syscall_params(process, bin_elf_class, user_regs->orig_rax, \
			table[user_regs->orig_rax].reg_types + regs_offset, \
			(unsigned long[6]) {
				user_regs->rbx, user_regs->rcx, user_regs->rdx, \
				user_regs->rsi, user_regs->rdi, user_regs->rbp
			} + regs_offset, regs_max_count);
	else if (bin_elf_class == ELFCLASS64)
		ret = cycle_syscall_params(process, bin_elf_class, user_regs->orig_rax, \
			table[user_regs->orig_rax].reg_types + regs_offset, \
			(unsigned long[6]) {
				user_regs->rdi, user_regs->rsi, user_regs->rdx, \
				user_regs->r10, user_regs->r8, user_regs->r9
			} + regs_offset, regs_max_count);
	if (!regs_offset)
		printed += dprintf(INFO_FD, "%s(", table[user_regs->orig_rax].name);
	printed += dprintf(INFO_FD, (!regs_offset) ? ("%s") : (", %s"), ret);
	if (regs_offset + regs_max_count == 6)
		printed += dprintf(INFO_FD, ")");
	free(ret);
	return (printed);
}

/*
** Print values contained in the registers after calling the syscall
**
** https://stackoverflow.com/questions/29047592/accessing-errno-h-in-assembly-language
*/

static int		print_valid_post_syscall(pid_t process, struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table, int total_printed)
{
	int			printed;
	char		*s;

	// printf("|Total printed %d\n", total_printed);
	if (table[user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)user_regs->rax && (int)user_regs->rax <= -1))
		asprintf(&s, "-1 %s (%s)", tostring_errnum(-user_regs->rax), ft_strerror(-user_regs->rax));
	else
		s = format_reg_value(process, table[user_regs->orig_rax].reg_ret_type, user_regs->rax);
	printed = dprintf(INFO_FD, "%*s= %s\n", \
		(total_printed > 40) ? (0) : (40 - total_printed), "", s);
	free(s);
	return (printed);
}



int				print_syscall_info(pid_t process, bool regs_type, \
					unsigned char bin_elf_class, \
					struct user_regs_struct *user_regs, \
					t_ft_strace_syscall *table,
					unsigned int regs_offset, unsigned int regs_max_count)
{
	static int	total_printed;
	int			printed;

	if (!regs_offset && regs_type == PRE_SYSCALL_REGS)
		total_printed = 0;
	printed = 0;
	if (regs_type == PRE_SYSCALL_REGS)
	{
		// printf("Print %u params w/ offset %u\n", regs_max_count, regs_offset);
		if (user_regs->orig_rax < ( sizeof(g_syscall_table_64) / sizeof(t_ft_strace_syscall) ))
			printed = print_valid_pre_syscall(process, bin_elf_class, user_regs, \
				table, regs_offset, regs_max_count);
		else
			handle_invalid_syscall_id(process, user_regs);
	}
	else if (regs_type == POST_SYSCALL_REGS)
		printed = print_valid_post_syscall(process, user_regs, table, total_printed);
	total_printed += printed;
	return (printed);
}
