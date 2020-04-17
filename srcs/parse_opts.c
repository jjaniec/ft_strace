/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 22:02:11 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/17 12:03:16 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

char			**parse_opts(t_ft_strace_opts *opts, int ac, char **av)
{
	char	**ptr;

	(void)ac;
	ptr = av + 1;
	while (ptr && *ptr && **ptr == '-')
	{
		if (ft_strchr(*ptr + 1, 'c'))
			opts->c = true;
		else if (ft_strchr(*ptr + 1, 'd')) /* (*ptr)[1] == 'd') */
		{
			if (!(ptr[1] && ft_str_is_positive_numeric(ptr[1])))
				return (NULL);
			opts->d = ft_atoi(ptr[1]);
			ptr++;
		}
		else if ((*ptr)[1] == '-' && (*ptr)[2] == '\0')
			return (ptr + 1);
		else
		{
			dprintf(ERR_FD, ERR_PREFIX "Unrecognized option: %s\n", (*ptr + 1));
			return (NULL);
		}
		ptr++;
	}
	return (ptr);
}
