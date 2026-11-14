/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:26:46 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/14 20:08:02 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_screen(t_game *game)
{
	t_img	*s;

	s = &game->screen;
	s->ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!s->ptr)
		exit_error(game, NULL, ERR_MLX_IMG);
	s->addr = mlx_get_data_addr(s->ptr, &s->bpp, &s->line_len, &s->endian);
	s->width = WIN_WIDTH;
	s->height = WIN_HEIGHT;
}

void	init_mlx(t_game	*game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_syserror(game, NULL, ERR_MLX_INIT);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		exit_syserror(game, NULL, ERR_MLX_WIN);
}
