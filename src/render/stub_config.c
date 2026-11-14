#include "cub3d.h"

void	stub_config(t_config *cfg)
{
	static char	*map[] = {
		"11111111",
		"10000001",
		"10110001",
		"10000001",
		"11111111",
		NULL
	};

	cfg->map = map;
	cfg->map_w = 8;
	cfg->map_h = 5;
	cfg->spawn_x = 2;
	cfg->spawn_y = 3;
	cfg->spawn_dir = N;
	cfg->floor_color = 0x555555;
	cfg->ceil_color = 0x87CEEB;
}
