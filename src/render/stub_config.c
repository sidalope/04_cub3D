/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stub_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:58:50 by aoneil            #+#    #+#             */
/*   Updated: 2026/11/28 17:07:29 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stub_config(t_config *cfg)
{
	static char	*map[] = {
		"11111111",
		"10000001",
		"10110001",
		"10000001",
		"11111111",
		NULL
	};

	cfg->map = map;
	cfg->map_w = 8;
	cfg->map_h = 5;
	cfg->spawn_x = 2;
	cfg->spawn_y = 3;
	cfg->spawn_dir = E;
	cfg->floor_color = 0x555555;
	cfg->ceil_color = 0x87CEEB;
	cfg->tex[N] = "textures/test/north.xpm";
	cfg->tex[S] = "textures/test/south.xpm";
	cfg->tex[W] = "textures/test/west.xpm";
	cfg->tex[E] = "textures/test/east.xpm";
	cfg->tex[N] = "textures/wolfenstein/mossy.xpm";
	cfg->tex[S] = "textures/wolfenstein/red_brick.xpm";
	cfg->tex[W] = "textures/wolfenstein/color_stone.xpm";
	cfg->tex[E] = "textures/wolfenstein/eagle.xpm";
}
