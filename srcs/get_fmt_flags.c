/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:24:55 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/17 15:10:36 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Return a formated string of syscall flags (each separated by a '|')
*/

static char	*fmt_flag_list(pid_t child, unsigned long reg_value, \
						t_ft_strace_flag_list *flag_list)
{
	char		*s;
	char		*tmp;
	bool		add_pipe;

	(void)child;
	add_pipe = false;
	s = NULL;
	for (unsigned int i = 0; i < flag_list->size; i++)
	{
		tmp = s;
		if (reg_value & flag_list->flags[i])
		{
			if (add_pipe)
			{
				asprintf(&s, "%s|%s", s, flag_list->flags_fmt[i]);
				free(tmp);
			}
			else
				asprintf(&s, flag_list->flags_fmt[i]);
			add_pipe = true;
		}
	}
	return (s);
}


/*
** Handle syscall flags by looking the associated
** flags string tables with their syscall ids and return
** a string containing the formated flags
*/

char		*get_fmt_flags(pid_t child, unsigned char bin_elf_class, \
				unsigned long orig_rax, int type, \
				unsigned long reg_value)
{
	t_ft_strace_flag_list	MAP_PROT_FLAGS = {
		MAP_PROT_VALUES, MAP_PROT_FMT, MAP_PROT_LEN
	};
	t_ft_strace_flag_list	MAP_FLAGS = {
		MAP_FLAGS_VALUES, MAP_FLAGS_FMT, MAP_FLAGS_LEN
	};

	char	*ret;
	/* mmap / mmap2 / mprotect */
	if ((bin_elf_class == ELFCLASS64 && (orig_rax == 9 || orig_rax == 10)) || \
		(bin_elf_class == ELFCLASS32 && (orig_rax == 192 || orig_rax == 90 || orig_rax == 125)))
	{
		if (type == MAP_PROT)
			ret = fmt_flag_list(child, reg_value, &MAP_PROT_FLAGS);
		else if (type == FLAGS)
			ret = fmt_flag_list(child, reg_value, &MAP_FLAGS);
	}
	else
		asprintf(&ret, "{FLAGS}");
	return (ret);
}
