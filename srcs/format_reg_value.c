/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_reg_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:30:24 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/25 17:52:52 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

/*
** Print STR argument / return type
**
** https://linuxgazette.net/issue81/sandeep.html
*/

static char		*get_string_from_addr(pid_t child, unsigned long reg_value, \
					bool use_string_len, size_t string_len)
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
		if ((!use_string_len && ft_memchr(&tmp, 0, sizeof(tmp))) || \
			(use_string_len && (size_t)read >= string_len))
			break ;
	}
	return (buf);
}

/*
** Write a string with custom replacement of invalid / non-printable characters
*/

static char		*escape_string(char *str, bool use_string_len, size_t string_len)
{
	char	*tmp;
	char	buff[4];
	char	*new_str;
	unsigned int	i;
	unsigned int	orig_string_index;
	char	*escaped_chars = "\n\t\f\r\v\0";
	char	*replacements[] = {
		"\\n",
		"\\t",
		"\\f",
		"\\r",
		"\\v",
		"\\0"
	};

	i = 0;
	orig_string_index = 0;
	new_str = ft_xmalloc(((use_string_len) ? (string_len) : (ft_strlen(str)) * 4 + 1) * \
		sizeof(char));
	while (str && orig_string_index < 33 && ((use_string_len && (size_t)i < string_len) || \
		(!use_string_len && str[orig_string_index])))
	{
		if ((tmp = ft_strchr(escaped_chars, str[orig_string_index])))
		{
			ft_strcpy(new_str + i, replacements[tmp - escaped_chars]);
			i += 2;
		}
		else if (ft_isprint(str[orig_string_index]))
			new_str[i++] = str[orig_string_index];
		else
		{
			sprintf(buff, "%hho", str[orig_string_index]);
			new_str[i++] = '\\';
			ft_memcpy(new_str + i, buff, ft_strlen(buff));
			i += ft_strlen(buff);
		}
		orig_string_index++;
	}
	new_str[i] = '\0';
	tmp = new_str;
	if (orig_string_index >= 33)
		asprintf(&new_str, "\"%.*s\"...", i - 1, new_str);
	else
		asprintf(&new_str, "\"%s\"", new_str);
	free(tmp);
	return (new_str);
}

static char		*format_string(char **str, bool use_string_len, size_t string_len)
{
	char	*tmp;

	if (!*str)
		return (ft_strdup("NULL"));
	tmp = escape_string(*str, use_string_len, string_len);
	free(*str);
	*str = tmp;
	return (0);
}

static char		*get_fmt_string(pid_t child, unsigned long reg_value, \
					bool use_string_len, size_t string_len)
{
	char		*str;

	str = get_string_from_addr(child, reg_value, use_string_len, string_len);
	if (format_string(&str, use_string_len, string_len))
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
		if (!(current_str = get_string_from_addr(child, data, false, 0)))
			break ;
		format_string(&current_str, false, 0);
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
					unsigned long reg_value, unsigned char bin_elf_class, \
					struct user_regs_struct *pre_user_regs)
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
	else if (type == STR)
		ret = get_fmt_string(child, reg_value, false, 0);
	else if (type == BUFFER && pre_user_regs)
	{
		// read
		if ((bin_elf_class == ELFCLASS64 && pre_user_regs->orig_rax == 0) || \
			(bin_elf_class == ELFCLASS32 && pre_user_regs->orig_rax == 3))
			ret = get_fmt_string(child, reg_value, true, (size_t)(pre_user_regs->rdx));
	}
	else if (type == STR_TAB)
		ret = get_fmt_string_tab(child, reg_value);
	else if (type == SIGNO)
		asprintf(&ret, "SIG%s", str_signo(reg_value));
	else
		asprintf(&ret, "%s", "TODO");
	return (ret);
}
