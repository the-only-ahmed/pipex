/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 22:40:47 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/31 18:51:04 by vjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

static void		duplicate(int *files, int a, int b, int *fd)
{
	dup2(files[a], a);
	close(fd[a]);
	dup2(fd[b], b);
	close(fd[b]);
}

void			fn_pipe(char **av, int nb, char **env)
{
	int		*files;
	int		fd[2];
	int		father;
	char	**cmd1;
	char	**cmd2;

	files = erreurs(av);
	cmd1 = fn_commande(av[2], env, nb);
	cmd2 = fn_commande(av[3], env, nb);
	father = errors(fd, father);
	if (father > 0)
	{
		duplicate(files, 0, 1, fd);
		if ((execve(cmd1[0], cmd1, env)) == -1)
			ft_putstr(": Execve Failed.\n");
	}
	else
	{
		duplicate(files, 1, 0, fd);
		close(files[0]);
		close(files[1]);
		free(files);
		execve(cmd2[0], cmd2, env);
	}
}

int				*erreurs(char **av)
{
	int		*files;

	files = (int*)malloc(sizeof(int) * 2);
	if ((files[0] = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("Wrong Argument: ");
		ft_putendl(av[1]);
		exit(0);
	}
	if ((files[1] = open(av[4], O_RDWR | O_CREAT | O_TRUNC)) == -1)
	{
		ft_putstr("Wrong Argument: ");
		ft_putendl(av[4]);
		exit(0);
	}
	if (fchmod(files[1], S_IRWXU | S_IRGRP | S_IROTH) == -1)
	{
		ft_putendl("Permission error");
		exit(0);
	}
	return (files);
}

int				errors(int *fd, int father)
{
	if (pipe(fd) == -1)
	{
		ft_putendl("Broken pipe");
		exit(0);
	}
	father = fork();
	if (father < 0)
	{
		ft_putendl("Fork error");
		exit(0);
	}
	return (father);
}
