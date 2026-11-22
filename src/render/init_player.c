#include "cub3d.h"

static void	set_dir(t_player *p, t_side dir)
{
	p->dir_x = 0;
	p->dir_y = 0;
	if (dir == N)
		p->dir_y = -1;
	else if (dir == S)
		p->dir_y = 1;
	else if (dir == E) 
		p->dir_x = 1;
	else if (dir == W)
		p->dir_x = -1;
}

void	init_player(t_game *game)
{
	t_player	*p;

	p = &game->player;
	p->pos_x = game->config.spawn_x + 0.5;
	p->pos_y = game->config.spawn_y + 0.5;
	set_dir(p, game->config.spawn_dir);
	p->plane_x = -p->dir_y * FOV;
	p->plane_y = p->dir_x * FOV;
}
