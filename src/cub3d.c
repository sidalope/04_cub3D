/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:59:54 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/13 15:12:32 by aoneil           ###   ########.fr       */
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

	ft_bzero(&game, sizeof(t_game)); //this was important before arg check

	// - arg handling
	validate_args(&game, ac, av);
	init(&game, av[1]);
	// - read map and 6 args
	// - parse the map, check errors
 	// - leak check for malformed files
	
	stub_config(&game.config);
	init_screen(&game);
	render_frame(&game);
	mlx_hook(game.win, 2, 1L << 0,key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_expose_hook(game.win, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
