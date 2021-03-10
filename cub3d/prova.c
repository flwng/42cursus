#include "cub3d.h"
#include "mlx/mlx.h"

void	my_mlx_put_pixel(t_img *data, int x, int y, int color)
{
	char    *dst;

    dst = data->adr + (y * data->len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;
	int	x = 400;
	int	y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 800, "viva mbus");
	img.img = mlx_new_image(mlx, 1200, 800);
	img.adr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	while (y < 600)
	{
		x = 400;
		while (x < 1000)
		{
			my_mlx_put_pixel(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);

}
