/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:32:51 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/25 16:11:53 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

static bool		is_path_valid(char *exec)
{
	struct stat		exec_stat;

	if (lstat(exec, &exec_stat) == -1)
		return (false);
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
	int				i;

	if (is_path_valid(cmd))
		return (ft_strdup(cmd));
	path = get_path_var(environ);
	path_dirs = split_path(path);
	i = 0;
	while (path_dirs && path_dirs[i])
	{
		path_len = ft_strlen(path_dirs[i]);
		ft_strcpy(buffer, path_dirs[i]);
		buffer[path_len] = '/';
		ft_strcpy(buffer + path_len + 1, cmd);
		if (is_path_valid(buffer))
		{
			free(path_dirs[i]);
			return (ft_strdup(buffer));
		}
		free(path_dirs[i]);
		i++;
	}
	free(path_dirs);
	return (NULL);
}
