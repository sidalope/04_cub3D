/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:22:28 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/13 13:27:30 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	read_colors(t_game *game, char *color_str)
// {
// 	int		i;
// 	int		rgb;
// 	char	**tmp_rgb;

// 	i = 0;
// 	rgb = 0;
// 	if (!color_str || color_str[0] != 'F')
// 		return (-1);
// 	else
// 	{
// 		tmp_rgb = ft_split(color_str, ',');
// 		if (!tmp_rgb)
// 			exit_syserror(game, "ft_split", ERR_MALLOC);
// 		while (i < 3 && tmp_rgb[i])
// 		{
// 			rgb |= ft_atoi(tmp_rgb[i]) << (8 * i);
// 			i++;
// 		}
// 	}
// 	return (rgb);
// }

// // must empty newlines
// // validate file readability later
// int	read_textures(t_game *game, int fd)
// {
// 	char	*tmp_tex;

// 	tmp_tex = NULL;
// 	tmp_tex = get_next_line(fd);
// 	if (!tmp_tex || ft_strlen(tmp_tex) < 6
// 				|| tmp_tex[0] != 'N' || tmp_tex[1] != 'O')
// 		return (0);
// 	game->config->tex[0] = ft_strdup(tmp_tex);
// 	tmp_tex = get_next_line(fd);
// 	if (!tmp_tex || ft_strlen(tmp_tex) < 6
// 				|| tmp_tex[0] != 'S' || tmp_tex[1] != 'O')
// 		return (0);
// 	game->config->tex[0] = ft_strdup(tmp_tex);
// 	tmp_tex = get_next_line(fd);
// 	if (!tmp_tex || ft_strlen(tmp_tex) < 6
// 				|| tmp_tex[0] != 'W' || tmp_tex[1] != 'E')
// 		return (0);
// 	game->config->tex[0] = ft_strdup(tmp_tex);
// 	tmp_tex = get_next_line(fd);
// 	if (!tmp_tex || ft_strlen(tmp_tex) < 6
// 				|| tmp_tex[0] != 'E' || tmp_tex[1] != 'A')
// 		return (0);
// 	game->config->tex[0] = ft_strdup(tmp_tex);
// 	return (1);
// }

// void	read_cub(t_game *game, char *cub_file)
// {
// 	int		fd;
// 	char	*tmp_line;

// 	tmp_line = NULL;
// 	fd = -1;
// 	fd = open(cub_file, O_RDONLY);
// 	if (fd == -1)
// 		exit_syserror(game, NULL, ERR_FILEOP);
// 	if (!read_textures(game, fd))
// 	{
// 		close(fd);
// 		exit_error(game, "invalid texture identifier: ", ERR_INVALID_CUB);
// 	}
// 	tmp_line = get_next_line(fd);
// 	if (!tmp_line)
// 		exit_error(game, "missing color specification: ", ERR_INVALID_CUB);
// 	game->config->floor_color = read_colors(game, tmp_line);
// 	tmp_line = get_next_line(fd);
// 	if (!tmp_line)
// 		exit_error(game, "missing color specification: ", ERR_INVALID_CUB);
// 	game->config->ceil_color = read_colors(game, tmp_line);
// 	if (game->config->floor_color == -1 || game->config->ceil_color == -1)
// 	{
// 		close(fd);
// 		exit_error(game, "invalid color specification: ", ERR_INVALID_CUB);
// 	}
// }

static void	init_mlx(t_game	*game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_syserror(game, NULL, ERR_MLX_INIT);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		exit_syserror(game, NULL, ERR_MLX_WIN);
	mlx_loop(game->mlx);
}

static void	parse_colour(t_game *game, char *rgb, int index)
{
	(void)game;
	(void) index;
	(void)rgb;
	// printf("%s", rgb);
}

static t_config_line	get_line_type(char *str)
{
    if (!str)
        return (INVALID_LINE);
	else if (str[0] == '\0')
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

static int	init_config_line(t_game *game, char *line)
{
    t_config_line	type;

    type = get_line_type(skip_whitespace(line));
	if (type == EMPTY_LINE)	
		return (2);
    else if (type == F_LINE)
	{
		parse_colour(game, line, 0);
        return (1);
	}
    else if (type == C_LINE)
    {
		parse_colour(game, line, 1);
        return (1);
	}
    else if (type == NO_LINE || type == SO_LINE
        || type == WE_LINE || type == EA_LINE)
	{
		game->config.tex[type] = ft_strdup(line);
		return (1);
	}
    return (0);
}

static void	read_config(t_game *game, char *cub_file)
{
	int		fd;
	char	*tmp_line;
	int		line_init_flag;
	int		config_params;

	fd = -1;
	tmp_line = NULL;
	config_params = 6;
	line_init_flag = -1;
	if (!cub_file)
		exit_error(game, "Invalid cub file: ", ERR_INIT);
	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
		exit_syserror(game, cub_file, ERR_FILEOP);
	tmp_line = get_next_line(fd);
	// validate non-error return of gnl
	while (tmp_line && config_params)
	{
		line_init_flag = init_config_line(game, tmp_line);
		if(line_init_flag == 1)
			config_params--;
		else if (line_init_flag == 0)
		{
			free(tmp_line);
			exit_error(game, "malformed .cub config line: ", ERR_INVALID_CUB);
		}
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	// printf("next line: %s", tmp_line);
	// printf("next line: %s", get_next_line(fd));
	// printf("next line: %s", get_next_line(fd));
	// printf("next line: %s", get_next_line(fd));
	
	// read_map(game, cub_file);
}

void	*init(t_game *game, char *cub_file)
{
	ft_bzero(game, sizeof(t_game));
	read_config(game, cub_file);
	// Worth writing a file handling wrapper for these two?
	
	init_mlx(game);
	return (game);
}
