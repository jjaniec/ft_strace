/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_syscall_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:24:55 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/13 18:41:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
**
*/

static int	print_fmt_flags(pid_t child, unsigned long reg_value, \
						t_ft_strace_flag_list *flag_list)
{
	bool	print_pipe;

	(void)child;
	print_pipe = false;
	for (unsigned int i = 0; i < flag_list->size; i++)
	{
		if (reg_value & flag_list->flags[i])
		{
			if (print_pipe)
				write(STDOUT_FILENO, "|", 1);
			write(STDOUT_FILENO, flag_list->flags_fmt[i], ft_strlen(flag_list->flags_fmt[i]));
			print_pipe = true;
		}
	}
	return (0);
}


/*
** Handle map related prot flags
*/

int			format_syscall_flags(pid_t child, unsigned char bin_elf_class, \
				unsigned long orig_rax, int type, \
				unsigned long reg_value)
{
	t_ft_strace_flag_list	MAP_PROT_FLAGS = {
		MAP_PROT_VALUES, MAP_PROT_FMT, MAP_PROT_LEN
	};
	t_ft_strace_flag_list	MAP_FLAGS = {
		MAP_FLAGS_VALUES, MAP_FLAGS_FMT, MAP_FLAGS_LEN
	};

	/* mmap / mmap2 / mprotect */
	if ((bin_elf_class == ELFCLASS64 && (orig_rax == 9 || orig_rax == 10)) || \
		(bin_elf_class == ELFCLASS32 && (orig_rax == 192 || orig_rax == 90 || orig_rax == 125)))
	{
		if (type == MAP_PROT)
			return (print_fmt_flags(child, reg_value, &MAP_PROT_FLAGS));
		else if (type == FLAGS)
			return (print_fmt_flags(child, reg_value, &MAP_FLAGS));
	}
	write(STDOUT_FILENO, "{FLAGS}", 7);
	return (1);
}
