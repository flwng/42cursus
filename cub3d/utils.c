#include "cub3d.h"

void	init_fmt(t_fmt *fmt)
{
	fmt->ceil = -1;
	fmt->east = 0;
	fmt->floor = -1;
	fmt->map = 0;
	fmt->map_size = 0;
	fmt->north = 0;
	fmt->south = 0;
	fmt->res_x = -1;
	fmt->res_y = -1;
	fmt->sprite = 0;
	fmt->west = 0;
	fmt->px = -1;
	fmt->py = -1;
	fmt->pdir = 0;
}

void	print_error(void)
{
	perror("Error\n");
	exit(1);
}
