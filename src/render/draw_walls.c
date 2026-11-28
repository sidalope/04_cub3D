/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:59:39 by aoneil            #+#    #+#             */
/*   Updated: 2026/11/28 17:10:26 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* E red, W green, S blue, N yellow */
// static int	wall_color(t_ray *r)
// {
// 	if (r->side == 0 && r->dir_x > 0)
// 		return(0xC0392B);
// 	if (r->side == 0)
// 		return(0x27AE60);
// 	if (r->dir_y >0)
// 		return (0x2980B9);
// 	return (0xF1C40F);
// }

static t_img	*wall_tex(t_game *g, t_ray *r)
{
	if (r->side == 0 && r->dir_x > 0)
		return (&g->tex[E]);
	if (r->side == 0)
		return (&g->tex[W]);
	if (r->dir_y > 0)
		return (&g->tex[S]);
	return (&g->tex[N]);
}

static int	calc_tex_x(t_game *g, t_ray *r, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (r->side == 0)
		wall_x = g->player.pos_y + r->perp_dist * r->dir_y;
	else
		wall_x = g->player.pos_x + r->perp_dist * r->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((r->side == 0 && r->dir_x < 0) || (r->side == 1 && r->dir_y > 0))
		tex_x = tex->width - tex_x -1;
	return (tex_x);
}

// static void	draw_column(t_game *g, t_ray *r, int x)
// {
// 	int		line_h;
// 	int		start;
// 	int		end;
// 	int		color;
// 	t_img	*tex;

// 	line_h = (int)(WIN_HEIGHT / r->perp_dist);
// 	start = WIN_HEIGHT / 2 - line_h / 2;
// 	if (start < 0)
// 		start = 0;
// 	end = WIN_HEIGHT / 2 + line_h / 2;
// 	if (end >= WIN_HEIGHT)
// 		end = WIN_HEIGHT - 1;
// 	// color = wall_color(r);
// 	tex = wall_tex(g, r);
// 	color = get_tex_pixel(tex, calc_tex_x(g,r,tex), tex->height / 2);
// 	while (start <= end)
// 	{
// 		put_pixel(&g->screen, x, start, color);
// 		start++;
// 	}
// }

// void		draw_walls(t_game *g)
// {
// 	t_ray	r;
// 	int		x;

// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		cast_ray(g,&r,x);
// 		draw_column(g,&r,x);
// 		x++;
// 	}
// }

static void	init_col(t_game *g, t_ray *r, t_col *c)
{
	c->tex = wall_tex(g, r);
	c->tex_x = calc_tex_x(g, r, c->tex);
	c->line_h = (int)(WIN_HEIGHT / r->perp_dist);
	if (c->line_h < 1)
		c->line_h = 1;
	c->start = WIN_HEIGHT / 2 - c->line_h / 2;
	c->end = WIN_HEIGHT / 2 + c->line_h / 2;
	c->step = (double)c->tex->height / c->line_h;
	c->tex_pos = 0;
	if (c->start < 0)
	{
		c->tex_pos = -c->start * c->step;
		c->start = 0;
	}
	if (c->end >= WIN_HEIGHT)
		c->end = WIN_HEIGHT;
}

static void	draw_column(t_game *g, int x, t_col *c)
{
	int	tex_y;
	int	y;

	y = c->start;
	while (y <= c->end)
	{
		tex_y = (int)c->tex_pos;
		if (tex_y >= c->tex->height)
			tex_y = c->tex->height - 1;
		put_pixel(&g->screen, x, y, get_tex_pixel(c->tex, c->tex_x, tex_y));
		c->tex_pos += c->step;
		y++;
	}
}

void	draw_walls(t_game *g)
{
	t_ray	r;
	int		x;
	t_col	c;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(g, &r, x);
		init_col(g, &r, &c);
		draw_column(g, x, &c);
		x++;
	}
}
