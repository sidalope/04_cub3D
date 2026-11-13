/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:59:54 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/13 10:11:41 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_args(t_game *game, int ac, char *av[])
{
	if (ac != 2 || ft_strlen(av[1]) < 5
				|| !ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		exit_error(game, NULL, ERR_USEAGE);
}

int	main(int ac, char *av[])
{
	t_game	game;
	// - arg handling
	validate_args(&game, ac, av);
	init(&game, av[1]);
	// - read map and 6 args
	// - parse the map, check errors
 	// - leak check for malformed files
	return (0);
}
