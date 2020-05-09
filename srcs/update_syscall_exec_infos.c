/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_syscall_exec_infos.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:14:21 by jjaniec           #+#    #+#             */
/*   Updated: 2020/05/09 22:23:02 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Update call & error count of last syscall
*/

int			update_syscall_exec_infos(unsigned char bin_elf_class, \
				t_ft_strace_syscall_exec_info **exec_infos, \
				struct user_regs_struct *post_user_regs)
{
	exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].calls++;
	if ((bin_elf_class == ELFCLASS64 && post_user_regs->orig_rax == 15) || \
		(bin_elf_class == ELFCLASS32 && post_user_regs->orig_rax == 119))
		return (0);
	if ((long long int)post_user_regs->rax < 0 && \
		(long long int)post_user_regs->rax >= -4095)
	{
		exec_infos[bin_elf_class == ELFCLASS32][post_user_regs->orig_rax].errors++;
	}
	return (0);
}
