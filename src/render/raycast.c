/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:58:57 by aoneil            #+#    #+#             */
/*   Updated: 2026/11/28 17:04:46 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_game *g, t_ray *r, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH -1;
	r->dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	r->dir_y = g->player.dir_y + g->player.plane_y * camera_x;
	r->map_x = (int)g->player.pos_x;
	r->map_y = (int)g->player.pos_y;
	r->delta_x = 1e30;
	if (r->dir_x != 0)
		r->delta_x = fabs(1 / r->dir_x);
	r->delta_y = 1e30;
	if (r->dir_y != 0)
		r->delta_y = fabs(1 / r->dir_y);
}

static void	init_step(t_player *p, t_ray *r)
{
	r->step_x = 1;
	r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_x;
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_x;
	}
	r->step_y = 1;
	r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_y;
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_y;
	}
}

static void	run_dda(t_config *cfg, t_ray *r)
{
	while (1)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_y < 0 || r->map_x >= cfg->map_w
			|| r->map_y >= cfg->map_h || cfg->map[r->map_y][r->map_x] == '1')
			return ;
	}
}

void	cast_ray(t_game *g, t_ray *r, int x)
{
	init_ray(g, r, x);
	init_step(&g->player, r);
	run_dda(&g->config, r);
	if (r->side == 0)
		r->perp_dist = r->side_dist_x - r->delta_x;
	else
		r->perp_dist = r->side_dist_y - r->delta_y;
	if (r->perp_dist < 0.0001)
		r->perp_dist = 0.0001;
}
