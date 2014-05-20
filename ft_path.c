/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:23:57 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/31 18:52:27 by vjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int		path_nb(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*create_path(char *command, char **env, int nb)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_strsplit(env[nb], ':');
	path[0] = &path[0][5];
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], "/\0");
		i++;
	}
	return (path_search(command, path));
}

char	*path_search(char *command, char **directories)
{
	DIR				*directory;
	struct dirent	*lecture;
	int				i;

	i = 0;
	while (directories[i] != NULL)
	{
		if ((directory = opendir(directories[i])) != NULL)
		{
			while ((lecture = readdir(directory)) != NULL)
			{
				if (ft_strcmp(lecture->d_name, command) == 0)
					return (directories[i]);
			}
		}
		i++;
	}
	return (NULL);
}

char	**fn_commande(char *str, char **env, int nb)
{
	char	**cmd;
	char	*ch;

	cmd = ft_strsplit(str, ' ');
	ch = create_path(cmd[0], env, nb);
	if (!ch)
	{
		ft_putendl("Error");
		exit(0);
	}
	cmd[0] = ft_strjoin(ch, cmd[0]);
	return (cmd);
}
