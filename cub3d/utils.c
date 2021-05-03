#include "cub3d.h"
#include "mlx/mlx.h"

void	init_fmt(t_fmt *fmt)
{
	fmt->ceil = -1;
	fmt->east = 0;
	fmt->floor = -1;
	fmt->map = 0;
	fmt->map_size = 0;
	fmt->mapb = 0;
	fmt->north = 0;
	fmt->south = 0;
	fmt->res_x = -1;
	fmt->res_y = -1;
	fmt->sprite = 0;
	fmt->west = 0;
	fmt->px = -1;
	fmt->py = -1;
	fmt->dir_x = 0;
	fmt->dir_y = 0;
}

void	print_error(void)
{
	perror("Error\n");
	exit(1);
}

void	get_sprite_address(t_tex *tex)
{
	tex->north.adr = mlx_get_data_addr(tex->north.img,
			&(tex->north.bpp), &(tex->north.len), &(tex->north.end));
	tex->south.adr = mlx_get_data_addr(tex->south.img,
			&(tex->south.bpp), &(tex->south.len), &(tex->south.end));
	tex->east.adr = mlx_get_data_addr(tex->east.img,
			&(tex->east.bpp), &(tex->east.len), &(tex->east.end));
	tex->west.adr = mlx_get_data_addr(tex->west.img,
			&(tex->west.bpp), &(tex->west.len), &(tex->west.end));
	tex->sprite.adr = mlx_get_data_addr(tex->sprite.img,
			&(tex->sprite.bpp), &(tex->sprite.len), &(tex->sprite.end));
}

void	load_images(t_fmt *fmt, void *mlx, t_tex *tex)
{
	tex->north.img = mlx_xpm_file_to_image(mlx, fmt->north,
			&(tex->nw), &(tex->nh));
	tex->south.img = mlx_xpm_file_to_image(mlx, fmt->south,
			&(tex->sw), &(tex->sh));
	tex->east.img = mlx_xpm_file_to_image(mlx, fmt->east,
			&(tex->ew), &(tex->eh));
	tex->west.img = mlx_xpm_file_to_image(mlx, fmt->west,
			&(tex->ww), &(tex->wh));
	tex->sprite.img = mlx_xpm_file_to_image(mlx, fmt->sprite,
			&(tex->spw), &(tex->sph));
	if (tex->north.img == 0 || tex->south.img == 0
		|| tex->east.img == 0 || tex->west.img == 0
		|| tex->sprite.img == 0)
	{
		perror("Error\n");
		exit(1);
	}
	get_sprite_address(tex);
}
