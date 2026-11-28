/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:58:17 by aoneil            #+#    #+#             */
/*   Updated: 2026/11/28 17:02:22 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_one(t_game *game, t_img *tex, char *path)
{
	tex->ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->ptr)
		exit_error(game, path, ": cannot load texture");
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->line_len,
			&tex->endian);
}

void	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		load_one(game, &game->tex[i], game->config.tex[i]);
		i++;
	}
}

unsigned int	get_tex_pixel(t_img *tex, int x, int y)
{
	char	*src;

	src = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)src);
}
