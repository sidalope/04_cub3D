/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:04:43 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/28 17:23:34 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_up(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	while (i < 4)
	{
		if (game->tex[i].ptr)
			mlx_destroy_image(game->mlx, game->tex[i].ptr);
		i++;
	}
	if (game->screen.ptr)
		mlx_destroy_image(game->mlx, game->screen.ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
