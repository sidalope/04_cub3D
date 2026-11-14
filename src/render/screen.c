#include "cub3d.h"

void	init_screen(t_game *game)
{
	t_img	*s;

	s = &game->screen;
	s->ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!s->ptr)
		exit_error(game, NULL, "mlx_new_image failed");
	s->addr = mlx_get_data_addr(s->ptr, &s->bpp, &s->line_len, &s->endian);
	s->width = WIN_WIDTH;
	s->height = WIN_HEIGHT;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
