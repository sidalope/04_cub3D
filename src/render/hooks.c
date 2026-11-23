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

	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
			|| keycode == KEY_D)
	{
		move_player(game, keycode);
		render_frame(game);
	}
	else if (keycode == KEY_LEFT)
	{
		rotate_player(&game->player, - ROT_SPEED);
		render_frame(game);
	}
	else if (keycode == KEY_RIGHT)
	{
		rotate_player(&game->player, ROT_SPEED);
		render_frame(game);
	}
	return (0);
}

