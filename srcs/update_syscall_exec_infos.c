/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_syscall_exec_infos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:14:21 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/03 20:40:32 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Update call & error count of last syscall
*/

int			update_syscall_exec_infos(unsigned char bin_elf_class,
				t_ft_strace_syscall *table32, t_ft_strace_syscall *table64, \
				t_ft_strace_syscall_exec_info **exec_infos, \
				struct user_regs_struct *post_user_regs)
{
	t_ft_strace_syscall	*table;

	table = (bin_elf_class == ELFCLASS32) ? (table64) : (table32);
	exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].calls++;
	if ((bin_elf_class == ELFCLASS64 && post_user_regs->orig_rax == 15) || \
		(bin_elf_class == ELFCLASS32 && post_user_regs->orig_rax == 119))
		return (0);
	if (table[post_user_regs->orig_rax].reg_ret_type == INT && \
		(-4095 <= (int)post_user_regs->rax && (int)post_user_regs->rax <= -1))
	{
		exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].errors++;
	}
	return (0);
}
