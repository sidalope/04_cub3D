/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:11:01 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/15 12:43:33 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(int *tmp_rgb)
{
	int		rgb;

	rgb = (tmp_rgb[0] << 16 | tmp_rgb[1] << 8 | tmp_rgb[2]);
	return (rgb);
}

// Could easily do the conversion in here
static int	parse_rgb_str(char *str, int *rgb)
{
	int 	i;

	i = 0;
	while (*str && i < 3)
	{
		rgb[i] = ft_atoi_cub3d(str);
		printf("%s --> %i: %i\n", str, i, rgb[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		str += ft_intlen(rgb[i]);
		if (!*str)
			break ;
		else if (i < 2 && *str == ',')
			str++;
		i++;
	}
	printf("BANG\n");
	printf("%i\n", i);
	if (i < 2 && *str)
		return (0);
	return (1);
}

static int	validate_colour_config_str(char *str, int *rgb)
{
	if (!str)
		return (0);
	if (*str == 'F' || *str == 'C')
		str++;
	else
		return (0);
	if (is_whitespace(*str))
		str++;
	else
		return (0);
	if(!parse_rgb_str(str, rgb))
		return (0);
	return (1);
}

/* type represents floor or ceiling and is indicated by either F_LINE or C_LINE */
void	parse_colour(t_game *game, char *config_string, int type)
{
	int		rgb[3];
	int		colour;

	if (!validate_colour_config_str(config_string, rgb))
		exit_error(game, config_string, ERR_INVALID_CUB);
	colour = rgb_to_int(rgb);
	if (type == F_LINE)
		game->config.floor_color = colour;
	else if (type == C_LINE)
		game->config.ceil_color = colour;
}
