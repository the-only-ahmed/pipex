/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:28:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/31 18:46:22 by vjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int		main(int ac, char **av, char **env)
{
	int		nb;
	int		i;

	i = 0;
	if (ac != 5)
		return (-1);
	if ((nb = path_nb(env)) == -1)
		return (-1);
	while (i < 5)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr("Argument NULL\n");
			return (-1);
		}
		i = i + 1;
	}
	fn_pipe(av, nb, env);
		return (0);
}
