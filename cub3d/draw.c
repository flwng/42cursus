/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:00:34 by flwang            #+#    #+#             */
/*   Updated: 2021/04/30 15:53:34 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ceil_floor(t_img *img, t_fmt *fmt)
{
	int	x;
	int	y;

	y = 0;
	while (y < fmt->res_y / 2)
	{
		x = 0;
		while (x < fmt->res_x)
		{
			my_mlx_pixel_put(img, x, y, fmt->ceil);
			x++;
		}
		y++;
	}
	while (y < fmt->res_y)
	{
		x = 0;
		while (x < fmt->res_x)
			my_mlx_pixel_put(img, x++, y, fmt->floor);
		y++;
	}
}

unsigned int	get_tex_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->adr + (y * data->len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_wall(t_all *all, int r_count)
{
	int	y;

	y = 0;
	while (y < all->cam.lineh)
	{
		if (all->cam.ra > PI && all->cam.sidehit == 'h')
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo,
				get_tex_color(&all->tex.north, all->tex.tx, all->tex.ty));
		else if (all->cam.ra < PI && all->cam.sidehit == 'h')
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo,
				get_tex_color(&all->tex.south, all->tex.tx, all->tex.ty));
		else if (all->cam.ra > 3 * PI / 2 || all->cam.ra < PI / 2)
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo,
				get_tex_color(&all->tex.east, all->tex.tx, all->tex.ty));
		else if (all->cam.ra < 3 * PI / 2 && all->cam.ra > PI / 2)
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo,
				get_tex_color(&all->tex.west, all->tex.tx, all->tex.ty));
		y++;
		all->tex.ty += all->tex.ty_step;
	}
}

void	get_wall_text(t_all *all, int r_count)
{
	if (all->cam.sidehit == 'h')
		all->tex.tx = (int)(all->cam.rx / (all->tex.nw / 64)) % (all->tex.nw);
	if (all->cam.ra < PI && all->cam.sidehit == 'h')
		all->tex.tx = 63 - all->tex.tx;
	if (all->cam.sidehit == 'v')
		all->tex.tx = (int)(all->cam.ry / (all->tex.nw / 64))
			% (all->tex.nw);
	if (all->cam.sidehit == 'v'
		&& all->cam.ra > PI / 2 && all->cam.ra < 3 * PI / 2)
		all->tex.tx = 63 - all->tex.tx;
	draw_wall(all, r_count);
}
