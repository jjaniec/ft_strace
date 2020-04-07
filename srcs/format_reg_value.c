/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reg_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:30:24 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/07 16:56:03 by jjaniec          ###   ########.fr       */
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
** Choose the right method to print a register according to the syscall table
*/

int				format_reg_value(pid_t child, int type, \
					unsigned long reg_value)
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
	if ((fmt_index = ft_int_index(printf_fmt_types, (sizeof(printf_fmt_types) / sizeof(int)), type)) != -1)
		ft_printf(printf_fmt_types_str[fmt_index], reg_value);
	else if (type == PTR)
		reg_value ? \
			ft_printf("%p", reg_value) : \
			ft_printf("NULL");
	else if (type == STR)
		print_string(child, reg_value);
	else
		ft_printf("%s", "TODO");
	return (1);
}
