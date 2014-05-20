/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:29:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/30 17:29:08 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <libft.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>


int		path_nb(char **env);
char	*create_path(char *command, char **env, int nb);
char	*path_search(char *command, char **directories);
char	**fn_commande(char *str, char **env, int nb);
void	fn_pipe(char **av, int nb, char **env);
int		*erreurs(char **av);
int		errors(int *fd, int father);

#endif /* PIPE_H */
