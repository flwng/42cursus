#include "cub3d.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

void	my_mlx_put_pixel(t_img *data, int x, int y, int color)
{
	char    *dst;

    dst = data->adr + (y * data->len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	start(char *argv, void **mlx)
{
	t_fmt	fmt;
	t_img	img;
	int	fd;
	void	*win;
	int	x = 400;
	int	y = 100;

	fd = open(argv, O_RDONLY);
	fmt = read_info(fd);
	close(fd);
	win = mlx_new_window(*mlx, fmt.res_x, fmt.res_y, "prova");
	img.img = mlx_new_image(*mlx, 1200, 800);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	while (y < 600)
	{
		x = 400;
		while (x < 1000)
		{
			my_mlx_put_pixel(&img, x, y, fmt.floor);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(*mlx, win, img.img, 0, 0);
	mlx_loop(*mlx);
}

int main(int argc, char **argv)
{
	void	*mlx;

	if ((argc == 2 && ft_strncmp("--save", argv[1], 6)) == 0 || argc == 1)
		return (-1);
	else
	{
		mlx = mlx_init();
		start(argv[1], &mlx);
	}
}
