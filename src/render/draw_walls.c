#include "cub3d.h"

/* E red, W green, S blue, N yellow */
static int	wall_color(t_ray *r)
{
	if (r->side == 0 && r->dir_x > 0)
		return(0xC0392B);
	if (r->side == 0)
		return(0x27AE60);
	if (r->dir_y >0)
		return (0x2980B9);
	return (0xF1C40F);
}

static void	draw_column(t_game *g, t_ray *r, int x)
{
	int	line_h;
	int	start;
	int	end;
	int	color;

	line_h = (int)(WIN_HEIGHT / r->perp_dist);
	start = WIN_HEIGHT / 2 - line_h / 2;
	if (start < 0)
		start = 0;
	end = WIN_HEIGHT / 2 + line_h / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	color = wall_color(r);
	while (start <= end)
	{
		put_pixel(&g->screen, x, start, color);
		start++;
	}
}

void		draw_walls(t_game *g)
{
	t_ray	r;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(g,&r,x);
		draw_column(g,&r,x);
		x++;
	}
}

