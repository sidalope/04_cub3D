/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:59:54 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/16 20:06:49 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_args(int ac, char *av[])
{
	if (ac != 2 || ft_strlen(av[1]) < 5
		|| !ft_strnstr(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		printf("Error\n%s\n", ERR_USEAGE);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_game	game;

	validate_args(ac, av);
	init(&game, av[1]);
	// - parse the map, check errors
	// - leak check for malformed files
	// printf("floor: %i\n ceiling: %i\n", game.config.ceil_color, game.config.ceil_color);
	// printf("tex NO: %s\ntex SO: %s\ntex WE: %s\ntex EA: %s\n",
	// 		game.config.tex[0], game.config.tex[1], game.config.tex[2], game.config.tex[3]);
	stub_config(&game.config);
	init_screen(&game);
	render_frame(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_expose_hook(game.win, render_frame, &game);
	mlx_loop(game.mlx);
	clean_up(&game);
	return (0);
}
