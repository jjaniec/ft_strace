/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:53:42 by joffreyjani       #+#    #+#             */
/*   Updated: 2020/03/29 21:29:54 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char			**parse_opts(t_ft_strace_opts *opts, int ac, char **av)
{
	char	**ptr;

	ptr = av + 1;
	while (ptr && *ptr && **ptr == '-')
	{
		if ((*ptr)[1] == 'c')
		{
			printf("|%s| is_numeric ? %d\n", ptr[1], ft_str_is_positive_numeric(ptr[1]));
			if (!(ptr[1] && ft_str_is_positive_numeric(ptr[1])))
				return (NULL);
			opts->c = ft_atoi(ptr[1]);
			ptr++;
		}
		else if ((*ptr)[1] == '-' && (*ptr)[2] == '\0')
			return (ptr + 1);
		else
		{
			ft_printf(ERR_PREFIX "Unrecognized option: %s\n", (*ptr + 1));
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}
