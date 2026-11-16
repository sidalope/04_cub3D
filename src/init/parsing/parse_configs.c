/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_configs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:32:10 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/16 19:55:34 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_config_line	get_line_type(char *str)
{
    if (!str)
        return (INVALID_LINE);
	else if (str[0] == '\0' || str[0] == '\n')
		return (EMPTY_LINE);
    else if(str[0] == 'F')
		return (F_LINE);
	else if(str[0] == 'C')
		return (C_LINE);
    else if (!ft_strncmp(str, "NO ", 3))
        return (NO_LINE);
    else if (!ft_strncmp(str, "SO ", 3))
        return (SO_LINE);
    else if (!ft_strncmp(str, "WE ", 3))
        return (WE_LINE);
    else if (!ft_strncmp(str, "EA ", 3))
        return (EA_LINE);
    return (INVALID_LINE);
}

static int	parse_config_str(t_game *game, char *line)
{
    t_config_line	type;

	line = skip_whitespace(line);
    type = get_line_type(line);
	if (type == EMPTY_LINE)	
		return (2);
    else if (type == F_LINE)
        return (parse_colour(game, line, F_LINE), 1);
    else if (type == C_LINE)
        return (parse_colour(game, line, C_LINE), 1);
    else if (type == NO_LINE || type == SO_LINE
        || type == WE_LINE || type == EA_LINE)
	{
		game->config.tex[type] = ft_strdup(line);
		if (!game->config.tex[type])
			exit_error(game, "parse_config_str: ft_strdup(): ", ERR_MALLOC);
		return (1);
	}
    return (0);
}

static int parse_line(t_game *game, char *next_line, int *n_params_left)
{
	int		parseable;

	parseable = -1;
	if (!n_params_left)
		return (0);
	if (*n_params_left && next_line)
	{
		parseable = parse_config_str(game, next_line);
		if(parseable == 1)
			(*n_params_left)--;
		else if (parseable == 0)
			return (0);
	}
	return (1);
}

void	parse_configs(t_game *game, int fd)
{
	int		gnl_error;
	int		n_params;

	gnl_error = 0;
	n_params = 6;
	game->config.config_buf = get_next_line(fd, &gnl_error);
	while (game->config.config_buf && !gnl_error && n_params)
	{
		parse_line(game, game->config.config_buf, &n_params);
		free(game->config.config_buf);
		game->config.config_buf = NULL;
		if (!n_params)
			break ;
		game->config.config_buf = get_next_line(fd, &gnl_error);
	}
	if (gnl_error || n_params)
	{
		// Needs more clarity
		exit_error(game, "malformed .cub config line: ", ERR_INVALID_CUB);
	}
}
