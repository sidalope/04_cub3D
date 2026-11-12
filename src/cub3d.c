/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:59:54 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 16:25:06 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_args(t_game *data, int ac, char *av[])
{
	if (ac != 2 || ft_strlen(av[1]) < 5
			|| !ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		error(data, "usage: ./cub3d <path>/<map name>.cub", ERR_USAGE);
}

int	main(int ac, char *av[])
{
	t_game data;
	// - arg handling
	init(&data);
	validate_args(&data, ac, av);
 	// - read map and 6 args
 	// - parse the map, check errors
 	// - leak check for malformed files

	return (0);
}
