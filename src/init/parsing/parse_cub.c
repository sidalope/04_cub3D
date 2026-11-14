/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:29:25 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/15 00:05:29 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_cub_file(t_game *game)
{
	parse_configs(game, game->cub_fd);
	parse_map(game, game->cub_fd);
	close(game->cub_fd);
	game->cub_fd = -1;
}
