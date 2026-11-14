#include "cub3d.h"

static void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = game->config.ceil_color;
		else
			color = game->config.floor_color;
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(&game->screen, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(t_game *game)
{
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.ptr, 0, 0);
	return (0);
}
