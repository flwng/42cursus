/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:00:41 by flwang            #+#    #+#             */
/*   Updated: 2021/04/26 20:26:44 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "mlx/mlx.h"

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->adr + (y * data->len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int	key_press(int key, t_all *all)
{
	if (key == 53)
		exit(0);
	all->key[key] = 1;
	return (0);
}

int	key_release(int key, t_all *all)
{
	all->key[key] = 0;
	return (0);
}

void	draw_map2d(t_all *all)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	while (y < all->fmt.map_size)
	{
		x = 0;
		while (x < ft_strlen(all->fmt.map[y]))
		{
			if (all->fmt.map[y][x] == '1')
			{
				i = y * 64;
				while (i < (y + 1) * 64)
				{
					j = x * 64;
					while (j < (x + 1) * 64)
					{
						my_mlx_pixel_put(&(all->img), j, i, 0xff00000);
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}
}

/*void	draw_player(t_all *all)
{
	int	x;
	int	y;

	y = all->fmt.ppy - 4;
	while (y < all->fmt.ppy + 4)
	{
		x = all->fmt.ppx - 4;
		while (x < all->fmt.ppx + 4)
		{
			my_mlx_pixel_put(&(all->img), x, y, 0xffa500);
			x++;
		}
		y++;
	}
	x = all->fmt.ppx;
	y = all->fmt.ppy;
	while (all->fmt.map[y / all->fmt.propx][x / all->fmt.propx] != '1')

	{
		my_mlx_pixel_put(&(all->img), x, y, 0x0000ff00);
		y += all->fmt.dir_y * all->fmt.propx;
		x += all->fmt.dir_x * all->fmt.propx;
	}
}*/

int	loop(t_all *all)
{
	int	i;
	double	tmp;
	double	tmp2;
	double	fray;

	move_player(all);
	i = 0;
	fray = -(all->fmt.pa - PI / 6 - 2 * PI);
	if (fray > 2 * PI)
		fray -= 2 * PI;
	else if (fray < 0)
		fray += 2 * PI;
	while (i < all->spr.len)
	{
		all->spr.dist[i] = sqrt(pow(all->spr.sx[i] + 32 - all->fmt.ppx, 2) + pow(all->spr.sy[i] + 32 - all->fmt.ppy, 2));
		tmp = atan2(-(all->spr.sy[i] + 32 - all->fmt.ppy), all->spr.sx[i] + 32 - all->fmt.ppx);
		if (tmp < 0)
			tmp += 2 * PI;
		tmp2 = fray - tmp;
		if (tmp > 3 * PI / 2 && fray - PI / 6 < PI / 2)
			tmp2 += 2 * PI;
		else if (fray - PI / 6 > 3 * PI / 2 && tmp < PI / 2)
		   tmp2 -= 2 * PI;
		all->spr.center[i] = tmp2 * all->fmt.res_x / (PI / 3);
		i++;
	}
	all->img.img = mlx_new_image(all->mlx, all->fmt.res_x, all->fmt.res_y);
	all->img.adr = mlx_get_data_addr(all->img.img, &all->img.bpp, &all->img.len, &all->img.end);
	//draw_map2d(all);
	//draw_player(all);
	ceil_floor(&all->img, &all->fmt);	
	draw_ray(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	mlx_destroy_image(all->mlx, all->img.img);
	return (0);
}

void	start(char *argv, t_all *all)
{
	int	max_x;
	int	max_y;

	ft_bzero(all->key, 126);
	all->spr.len = 0;
	all->fmt = read_info(argv, &all->spr);
	all->spr.dist = malloc(sizeof(double) * all->spr.len);
	all->spr.act = malloc(sizeof(int) * all->spr.len);
	all->spr.center = malloc(sizeof(int) * all->spr.len);
	load_images(&(all->fmt), all->mlx, &(all->tex));
	all->fmt.ppx = all->fmt.px * 64 + 32;
	all->fmt.ppy = all->fmt.py * 64 + 32;
	mlx_get_screen_size(all->mlx, &max_x, &max_y);
	if (all->fmt.res_x > max_x)
		all->fmt.res_x = max_x;
	if (all->fmt.res_y > max_y)
		all->fmt.res_y = max_y;
	all->win = mlx_new_window(all->mlx, all->fmt.res_x, all->fmt.res_y, "prova");
	mlx_hook(all->win, 2, 1L<<0, key_press, all);
	mlx_hook(all->win, 3, 1L<<1, key_release, all);
	mlx_loop_hook(all->mlx, loop, all);
	mlx_loop(all->mlx);
}

int main(int argc, char **argv)
{
	t_all	all;

	if ((argc == 2 && ft_strncmp("--save", argv[1], 6)) == 0 || argc == 1)
		return (-1);
	//start should get the first image; in case of save, save this image
	else
	{
		all.mlx = mlx_init();
		start(argv[1], &all);
	}
	// if not save, mlx_loop
}
