/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:04:43 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/16 14:05:59 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_up(t_game *game)
{
	int		i;

	i = 0;
	if (!game)
		return ;
	if (game->screen.ptr)
		mlx_destroy_image(game->mlx, game->screen.ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	while (i < 4)
	{
		if (game->config.tex[i])
			free(game->config.tex[i]);
		i++;
	}
	if (game->cub_fd != -1)
		close(game->cub_fd);
	free(game->config.config_buf);
	get_next_line(-1, &i);
}
