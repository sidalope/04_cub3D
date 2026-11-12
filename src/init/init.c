/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:22:28 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 16:34:32 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	init_player(t_game *data)
// {
// 	data->player = player;
// 	data->floor_color = 0;
// 	data->ceil_color = 0;
// }

static void	init_mlx(t_game	*data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error(data, "mlx initialisation failure", ERR_MLX);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win)
		error(data, "mlx window initialisation failure", ERR_MLX);
	mlx_loop(data->mlx);
}

t_game	*init(t_game *data)
{
	ft_bzero(data, sizeof(data));
	init_mlx(data);
	return (data);
}
