/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:09:49 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 16:28:21 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 600
# define WIN_HEIGHT 400

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

typedef enum e_error
{
	ERR_OTHER,
	ERR_MALLOC,
	ERR_FILEOP,
	ERR_USAGE,
	ERR_MLX
}				t_error;

typedef enum e_side
{
	N,
	E,
	S,
	W
}	t_side;

/* filled by the parser */
typedef struct s_config
{
	char	**map;        // NULL-terminated, rows padded with spaces to map_w
	int		map_w;
	int		map_h;
	int		spawn_x;      // column
	int		spawn_y;      // row; the letter on the map is replaced with '0'
	t_side	spawn_dir;
	char	*tex[4];      // texture paths, indexed by t_side
	int		floor_color;  // (r << 16) | (g << 8) | b
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
	t_img		*screen;
	t_img		*tex[4];
	t_player	*player;
	t_config	*config;
}	t_game;

// Error handling
void		error(t_game *data, char *context, t_error error_code);

// Utils
void		clean_up(t_game *data);

// Initialisation
t_game	*init();

#endif