#include "cub3d.h"

static int	is_wall(t_config *cfg, double x, double y)
{
	if (x < 0 || y < 0 || (int)x >= cfg->map_w || (int)y >= cfg->map_h)
		return (1);
	return (cfg->map[(int)y][(int)x] != '0');
}

static void	try_move(t_game *g, double dx, double dy)
{
	t_player	*p;
	double		mx;
	double		my;

	p = &g->player;
	mx = MARGIN;
	if ( dx < 0)
		mx = -MARGIN;
	my = MARGIN;
	if ( dy < 0)
		my = - MARGIN;
	if(!is_wall(&g->config, p->pos_x + dx + mx, p->pos_y))
		p->pos_x += dx;
	if(!is_wall(&g->config, p->pos_x, p->pos_y + dy + my))
		p->pos_y += dy;
}

void	move_player(t_game *g, int	key)
{
	t_player	*p;

	p = &g->player;
	if (key == KEY_W)
		try_move(g, p->dir_x * MOVE_SPEED, p->dir_y * MOVE_SPEED);
	else if (key == KEY_S)
		try_move(g, -p->dir_x * MOVE_SPEED, -p->dir_y * MOVE_SPEED);
	else if (key == KEY_A)
		try_move(g, p->dir_y * MOVE_SPEED, -p->dir_x * MOVE_SPEED);
	else if (key == KEY_D)
		try_move(g, -p->dir_y * MOVE_SPEED, p->dir_x * MOVE_SPEED);
	
}

void	rotate_player(t_player *p, double angle)
{
	double	old;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	old = p->dir_x;
	p->dir_x = p->dir_x * c - p->dir_y * s;
	p->dir_y = old * s + p->dir_y * c;
	old = p->plane_x;
	p->plane_x = p->plane_x * c - p->plane_y * s;
	p->plane_y = old * s + p->plane_y * c;
}
