/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reg_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:30:24 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/18 19:30:59 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Print STR argument / return type
**
** https://linuxgazette.net/issue81/sandeep.html
*/

static char		*get_string_from_addr(pid_t child, unsigned long reg_value)
{
	unsigned long	tmp;
	unsigned long	read;
	char			*buf;
	int				allocated;

	read = 0;
	allocated = STR_BUFFER_LEN;
	buf = ft_xmalloc(allocated);
	while (1)
	{
		if ((int)(read + sizeof(tmp)) > allocated)
		{
			buf = ft_xrealloc(buf, allocated, allocated * 2);
			allocated = allocated * 2;
		}
		errno = 0;
		tmp = ptrace(PTRACE_PEEKDATA, child, reg_value + read);
		if (errno)
			return (NULL);
		ft_memcpy(buf + read, &tmp, sizeof(tmp));
		read += sizeof(tmp);
		if (ft_memchr(&tmp, 0, sizeof(tmp)))
			break ;
	}
	return (buf);
}

/*
** Write a string with custom replacement of invalid / non-printable characters
*/

static char		*escape_string(char *str)
{
	char	*tmp;
	char	buff[4];
	char	*new_str;
	unsigned int	i;
	char	*escaped_chars = "\n\t\f\r\v";
	char	*replacements[] = {
		"\\n",
		"\\t",
		"\\f",
		"\\r",
		"\\v"
	};

	i = 0;
	new_str = ft_xmalloc((ft_strlen(str) * 4 + 1) * sizeof(char));
	while (str && *str)
	{
		if ((tmp = ft_strchr(escaped_chars, *(str))))
		{
			ft_strcpy(new_str + i, replacements[tmp - escaped_chars]);
			i += 2;
		}
		else if (ft_isprint(*(str)))
			new_str[i++] = *str;
		else
		{
			sprintf(buff, "%hho", *str);
			new_str[i++] = '\\';
			ft_memcpy(new_str + i, buff, ft_strlen(buff));
			i += ft_strlen(buff);
		}
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char		*format_string(char **str)
{
	char	*new_str;
	char	*tmp;

	if (!*str)
		return (ft_strdup("NULL"));
	tmp = escape_string(*str);
	if (ft_strlen(*str) > 32)
		asprintf(&new_str, "\"%.32s\"...", tmp);
	else
		asprintf(&new_str, "\"%s\"", tmp);
	free(tmp);
	free(*str);
	*str = new_str;
	return (0);
}

static char		*get_fmt_string(pid_t child, unsigned long reg_value)
{
	char		*str;

	str = get_string_from_addr(child, reg_value);
	if (format_string(&str))
		return (NULL);
	return (str);
}

static char		*get_fmt_string_tab(pid_t child, unsigned long reg_value)
{
	unsigned int		i;
	unsigned long		data;
	char				*fmt;
	char				*current_str;
	char				*tmp;

	i = 0;
	while (1)
	{
		data = ptrace(PTRACE_PEEKDATA, child, reg_value + (i * sizeof(char *)));
		if (!(data))
			break ;
		if (!(current_str = get_string_from_addr(child, data)))
			break ;
		format_string(&current_str);
		if (i)
		{
			tmp = fmt;
			asprintf(&fmt, "%s, %s", fmt, current_str);
			free(tmp);
		}
		else
			asprintf(&fmt, "%s", current_str);
		free(current_str);
		i++;
	}
	tmp = fmt;
	asprintf(&fmt, "[%s]", fmt);
	free(tmp);
	return (fmt);
}

/*
** Choose the right method to print a register according to the syscall table
*/

char			*format_reg_value(pid_t child, int type, \
					unsigned long reg_value)
{
	int			printf_fmt_types[] = {
		INT, SIZE_T, SSIZE_T, LONG, UINT, ULONG
	};
	char		*printf_fmt_types_str[] = {
		"%d", "%zu", "%zd", "%ld", "%u", "%lu"
	};
	int			fmt_index;
	char		*ret;

	ret = NULL;
	if (type == UNDEF)
		return (0);
	if ((fmt_index = ft_int_index(printf_fmt_types, (sizeof(printf_fmt_types) / sizeof(int)), type)) != -1)
		asprintf(&ret, printf_fmt_types_str[fmt_index], reg_value);
	else if (type == PTR || type == STRUCT)
		reg_value ? \
			asprintf(&ret, "%p", reg_value) : \
			asprintf(&ret, "NULL");
	else if (type == HEX)
		reg_value ? \
			asprintf(&ret, "%p", reg_value) : \
			asprintf(&ret, "0", reg_value);
	else if (type == STR || type == BUFFER)
		ret = get_fmt_string(child, reg_value);
	else if (type == STR_TAB)
		ret = get_fmt_string_tab(child, reg_value);
	else if (type == SIGNO)
		asprintf(&ret, "SIG%s", str_signo(reg_value));
	else
		asprintf(&ret, "%s", "TODO");
	return (ret);
}
