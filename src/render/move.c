#include "cub3d.h"

void	move_player(t_game *g, int	key)
{
	t_player	*p;

	p = &g->player;
	if (key == KEY_W)
	{
		p->pos_x += p->dir_x * MOVE_SPEED;
		p->pos_y += p->dir_y * MOVE_SPEED;
	}
	if (key == KEY_S)
	{
		p->pos_x -= p->dir_x * MOVE_SPEED;
		p->pos_y -= p->dir_y * MOVE_SPEED;
	
	}
}