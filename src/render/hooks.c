#include "cub3d.h"

int	close_game(t_game *game)
{
	clean_up(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);

	else if (keycode == KEY_W || KEY_S)
	{
		move_player(game, keycode);
		render_frame(game);
	}
	return (0);
}

