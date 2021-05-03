/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:01:09 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 17:45:10 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_file_screenshot(int fd, t_all *all)
{
	int	i;
	int	j;
	int	color;

	i = all->fmt.res_y;
	while (--i >= 0)
	{
		j = -1;
		while (++j < all->fmt.res_x)
		{
			color = *(int *)(all->img.adr + (i * all->img.len
						+ j * (all->img.bpp / 8)));
			write(fd, &color, 4);
		}
	}
}

void	ft_screenshot2(t_all *all, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = all->fmt.res_x * all->fmt.res_y * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &all->fmt.res_x, 4);
	write(fd, &all->fmt.res_y, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

void	create_image(t_all *all)
{
	int	fd;
	int	size_screen;
	int	zero;
	int	size;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, 0777);
	size_screen = all->fmt.res_x * all->fmt.res_y * 4 + 54;
	zero = 0;
	size = all->fmt.res_x * all->fmt.res_y;
	if (fd < 0)
		print_error();
	ft_screenshot2(all, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	ft_file_screenshot(fd, all);
	close(fd);
}

void	get_image(t_all *all)
{
	int	i;

	create_image(all);
	i = 0;
	while (i < all->fmt.map_size)
		free(all->fmt.map[i++]);
	free(all->fmt.map);
	mlx_destroy_image(all->mlx, all->img.img);
	exit(0);
}

void	ft_screenshot(char *argv, t_all *all)
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
	get_center(all);
	all->img.img = mlx_new_image(all->mlx, all->fmt.res_x, all->fmt.res_y);
	all->img.adr = mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.len, &all->img.end);
	ceil_floor(&all->img, &all->fmt);
	draw_ray(all);
	get_image(all);
}
