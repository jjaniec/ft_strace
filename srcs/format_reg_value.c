/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reg_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:30:24 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/07 14:38:37 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Write a string with custom replacement of invalid / non-printable characters
*/

static int		custom_write(int fd, char *str, size_t max_nbyte)
{
	char	*tmp;
	char	*escaped_chars = "\n\t";
	char	*replacements[] = {
		"\\n",
		"\\t"
	};

	for (size_t count = 0; count < max_nbyte && *(str + count); count++)
		if ((tmp = ft_strchr(escaped_chars, *(str + count))))
			write(fd, replacements[tmp - escaped_chars], \
				ft_strlen(replacements[tmp - escaped_chars]));
		else if (10 > *(str + count))
		{
			write(fd, "\\", 1);
			ft_putchar_fd(*(str + count) + '0', fd);
		}
		else
			write(fd, str + count, 1);
	return (0);
}

/*
** Print STR argument / return type
**
** https://linuxgazette.net/issue81/sandeep.html
*/

static int		print_string(pid_t child, unsigned long reg_value)
{
	unsigned long	tmp;
	unsigned long	read;
	char			buf[STR_BUFFER_LEN + 1];

	read = 0;
	buf[STR_BUFFER_LEN] = '\0';
	while (read < STR_BUFFER_LEN)
	{
		errno = 0;
		tmp = ptrace(PTRACE_PEEKDATA, child, reg_value + read);
		if (errno)
			return (1);
		ft_memcpy(buf + read, &tmp, sizeof(tmp));
		read += sizeof(tmp);
		if (ft_memchr(&tmp, 0, sizeof(tmp)))
			break ;
	}
	write(STDOUT_FILENO, "\"", 1);
	custom_write(STDOUT_FILENO, buf, (read < PRINTED_STR_LEN) ? (read) : (PRINTED_STR_LEN));
	write(STDOUT_FILENO, "\"", 1);
	if (read > PRINTED_STR_LEN)
		write(STDOUT_FILENO, "...", 3);
	return (0);
}

/*
** Handle map related prot flags
*/

static int		handle_map_prot(pid_t child, unsigned long reg_value)
{
	long	map_prots[] = {
			MAP_SHARED, MAP_PRIVATE, MAP_32BIT, MAP_ANONYMOUS, MAP_DENYWRITE,
			MAP_EXECUTABLE, MAP_FILE, MAP_FIXED, MAP_GROWSDOWN, MAP_HUGETLB,
			MAP_LOCKED, MAP_NONBLOCK, MAP_NORESERVE, MAP_POPULATE,
			MAP_STACK
	};
	char	*map_prots_str[] = {
			"MAP_SHARED", "MAP_PRIVATE", "MAP_32BIT", "MAP_ANONYMOUS", "MAP_DENYWRITE",
			"MAP_EXECUTABLE", "MAP_FILE", "MAP_FIXED", "MAP_GROWSDOWN", "MAP_HUGETLB",
			"MAP_LOCKED", "MAP_NONBLOCK", "MAP_NORESERVE", "MAP_POPULATE",
			"MAP_STACK"
	};
	char	*prot_fmt = NULL;
	char	*tmp;

	for (unsigned int i = 0; i < (sizeof(map_prots) / sizeof(map_prots[0])); i++)
	{
		if (reg_value & map_prots[i])
		{
			if (prot_fmt)
			{
				tmp = prot_fmt;
				asprintf(&prot_fmt, "%s|%s", map_prots_str[i]);
				free(tmp);
			}
			else
				prot_fmt = ft_strdup(map_prots_str[i]);
		}
	}
	write(STDOUT_FILENO, prot_fmt, ft_strlen(prot_fmt));
	free(prot_fmt);
	return (0);
}

/*
** Choose the right method to print a register according to the syscall table
*/

int				format_reg_value(pid_t child, int type, \
					unsigned long reg_value, unsigned int reg_index)
{
	int			printf_fmt_types[] = {
		INT, SIZE_T, SSIZE_T, LONG, UINT, HEX, ULONG, STRUCT
	};
	char		*printf_fmt_types_str[] = {
		"%d", "%zu", "%zd", "%ld", "%u", "%x", "%lu", "STRUCT"
	};
	int			fmt_index;

	if (type == UNDEF)
		return (0);
	if (reg_index != 0)
		write(STDOUT_FILENO, ", ", 2);
	if ((fmt_index = ft_int_index(printf_fmt_types, (sizeof(printf_fmt_types) / sizeof(int)), type)) != -1)
		ft_printf(printf_fmt_types_str[fmt_index], reg_value);
	else if (type == PTR)
		reg_value ? \
			ft_printf("%p", reg_value) : \
			ft_printf("NULL");
	else if (type == STR)
		print_string(child, reg_value);
	else if (type == MAP_PROT)
		handle_map_prot(child, reg_value);
	else
		ft_printf("%s", "TODO");
	return (1);
}
