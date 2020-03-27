/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 18:33:28 by joffreyjani       #+#    #+#             */
/*   Updated: 2020/03/27 19:57:41 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

int		main(int ac, char **av, char **environ)
{
	(void)ac;
	(void)av;

	printf("%s\n", resolve_path(av[1], environ));
	return (42);
}
