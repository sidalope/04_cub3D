/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:22:28 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/15 00:05:15 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game, char *cub_file)
{
	ft_bzero(game, sizeof(t_game));
	if (!cub_file)
		exit_error(game, "Invalid cub file: ", ERR_INIT);
	game->cub_fd = open(cub_file, O_RDONLY);
	if (game->cub_fd == -1)
		exit_syserror(game, cub_file, ERR_FILEOP);
	parse_cub_file(game);
	
	init_mlx(game);
}
