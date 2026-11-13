/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:09:49 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/13 13:04:13 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 600
# define WIN_HEIGHT 400
# define ERR_MALLOC "malloc"
# define ERR_FILEOP "fileop"
# define ERR_USEAGE "usage: ./cub3d <path>/<map name>.cub"
# define ERR_MLX_INIT "mlx initialisation failure"
# define ERR_MLX_WIN "mlx window initialisation failure"
# define ERR_INVALID_CUB "malformed .cub file"
# define ERR_INIT "could not initialize"

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

/*
t_config_line and t_side can be conflated in
the future if there is certainty that t_side will 
never be accessed at index 4
*/
typedef enum e_config_line
{
    EMPTY_LINE = -2,
	INVALID_LINE = -1,
    NO_LINE,
    SO_LINE,
	WE_LINE,
	EA_LINE,
	F_LINE,
    C_LINE,
}	t_config_line;

typedef enum e_side
{
	N,
	S,
	W,
	E
}	t_side;

/* filled by the parser */
typedef struct s_config
{
	char	**map;			// NULL-terminated, rows padded with spaces to map_w
	int		map_w;
	int		map_h;
	int		spawn_x;		// column
	int		spawn_y;		// row; the letter on the map is replaced with '0'
	t_side	spawn_dir;
	char	*tex[4];		// texture paths, indexed by t_side
	int		floor_color;	// (r << 16) | (g << 8) | b
	int		ceil_color;
}	t_config;

/* rendering side */
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		screen;
	t_player	player;
	t_config	config;
}	t_game;

// Error handling
void		exit_error(t_game *game, char *context, char *error_code);
void		exit_syserror(t_game *game, char *context, char *error_id);

// Utils
void		clean_up(t_game *game);
char		*skip_whitespace(char *str);

// Initialisation
void		*init(t_game *game, char *cub_file);

#endif