/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:22:28 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 22:27:56 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	init_player(t_game *game)
// {
// 	game->player = player;
// 	game->floor_color = 0;
// 	game->ceil_color = 0;
// }

static void	init_mlx(t_game	*game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_syserror(game, NULL, ERR_MLX_INIT);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		exit_syserror(game, NULL, ERR_MLX_WIN);
	mlx_loop(game->mlx);
}

void	*init(t_game *game)
{
	ft_bzero(game, sizeof(game));
	init_mlx(game);
	return (game);
}
