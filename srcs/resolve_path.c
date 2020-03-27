/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:36:56 by joffreyjani       #+#    #+#             */
/*   Updated: 2020/03/27 19:56:49 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static bool		is_path_valid(char *exec)
{
	struct stat		exec_stat;

	if (lstat(exec, &exec_stat) == -1)
	{
		perror("lstat");
		return (false);
	}
	return (true);
}

static char		**split_path(char *path)
{
	char	*path_value;

	if (!path)
		return (NULL);
	path_value = path + ft_strlen("PATH=");
	return (ft_strsplit(path_value, ':'));
}

static char		*get_path_var(char **environ)
{
	while (environ && *environ)
	{
		if (ft_strstr(*environ, "PATH="))
			return (*environ);
		environ++;
	}
	return (NULL);
}

char	*resolve_path(char *cmd, char **environ)
{
	char			*path;
	char			**path_dirs;
	char			buffer[PATH_RES_BUFF_LEN];
	unsigned int	path_len;

	if (is_path_valid(cmd))
		return (ft_strdup(cmd));
	path = get_path_var(environ);
	path_dirs = split_path(path);
	while (path_dirs && *path_dirs)
	{
		path_len = ft_strlen(*path_dirs);
		ft_strcpy(buffer, *path_dirs);
		buffer[path_len] = '/';
		ft_strcpy(buffer + path_len + 1, cmd);
		printf("\t%s\n", buffer);
		if (is_path_valid(buffer))
			return (ft_strdup(buffer));
		path_dirs++;
	}
	return (NULL);
}
