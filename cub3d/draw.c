/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:00:34 by flwang            #+#    #+#             */
/*   Updated: 2021/04/26 20:26:38 by flwang           ###   ########.fr       */
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
    char    *dst;

    dst = data->adr + (y * data->len + x * (data->bpp / 8));
    return(*(unsigned int*)dst);
}

void	get_wall_text(t_all *all, int r_count) 
{
	int y = 0;

	if (all->cam.sidehit == 'h')
	{
		all->tex.tx = (int)(all->cam.rx / (all->tex.nw / 64)) % (all->tex.nw);
		if (all->cam.ra < PI)
			all->tex.tx = 63 - all->tex.tx;
	}
	else
	{
		all->tex.tx = (int)(all->cam.ry / (all->tex.nw / 64)) % (all->tex.nw);
		if (all->cam.ra > PI / 2 && all->cam.ra < 3 * PI / 2)
			all->tex.tx = 63 - all->tex.tx;
	}
	while (y < all->cam.lineh)
	{
		if (all->cam.ra > PI && all->cam.sidehit == 'h')
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo, get_tex_color(&all->tex.north, all->tex.tx, all->tex.ty));
		else if (all->cam.ra < PI && all->cam.sidehit == 'h')
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo, get_tex_color(&all->tex.south, all->tex.tx, all->tex.ty));
		else if (all->cam.ra > 3 * PI / 2 || all->cam.ra < PI / 2)
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo, get_tex_color(&all->tex.east, all->tex.tx, all->tex.ty));
		else if (all->cam.ra < 3 * PI / 2 && all->cam.ra > PI / 2)
			my_mlx_pixel_put(&all->img, r_count, y + all->cam.lineo, get_tex_color(&all->tex.west, all->tex.tx, all->tex.ty));
		y++;
		all->tex.ty += all->tex.ty_step;
	}
}

void	get_sprite(t_all *all, int r_count)
{
	double	spriteh;
	double	stepy;
	double	sprite_yo;
	double	spriteo;
	double	spritey;
	double	spritex;
	double	start;
	double	end;

	/*int	i = 0;
	while (all->spr.act[i] != -1)
	{
		all->spr.dist[i] = sqrt(pow(all->spr.sx[all->spr.act[i]] + 32  - all->fmt.ppx, 2) + pow(all->spr.sy[all->spr.act[i]] + 32 - all->fmt.ppy, 2));
		i++;
	}*/
	while (all->spr.nact > 0)
	{
		if (all->cam.dist > all->spr.dist[all->spr.act[all->spr.nact - 1]])
		{
			spriteh = 64 * all->fmt.res_y / all->spr.dist[all->spr.act[all->spr.nact - 1]];
			stepy = all->tex.sph / spriteh;
			sprite_yo = 0;
			if (spriteh > all->fmt.res_y)
			{
				sprite_yo = (spriteh - all->fmt.res_y) / 2;
				spriteh = all->fmt.res_y;
			}
			spriteo = all->fmt.res_y / 2 - spriteh / 2;
			spritey = sprite_yo * stepy;
			int y = 0;
			start = all->spr.center[all->spr.act[all->spr.nact - 1]] - ((spriteh + sprite_yo) / 2);
			end = all->spr.center[all->spr.act[all->spr.nact - 1]] + ((spriteh + sprite_yo) / 2);
	/*all->cam.rx_sprite *= cos(all->fmt.pa);
	all->cam.ry_sprite *= sin(all->fmt.pa);*/
		/*	if (all->fmt.pa == 3 * PI / 2 || all->fmt.pa == PI / 2)
				spritex = (int)(all->spr.rsx[all->spr.nact - 1] / (all->tex.spw / 64)) % (all->tex.spw);
			else if (all->fmt.pa == PI || all->fmt.pa == 0)
				spritex = (int)(all->spr.rsy[all->spr.nact - 1] / (all->tex.spw / 64)) % (all->tex.spw);*/
			//printf("%d\n", all->spr.center[all->spr.nact - 1]);
			spritex = ((int)((r_count - start)) % (int)(spriteh + sprite_yo)) * all->tex.spw / (spriteh + sprite_yo);
			while (y < spriteh && r_count >= start && r_count <= end)
			{
				if (get_tex_color(&all->tex.sprite, spritex, spritey) != 0)
					my_mlx_pixel_put(&all->img, r_count, y + spriteo, get_tex_color(&all->tex.sprite, spritex, spritey));
				y++;
				spritey += stepy;
			}
		}
		all->spr.nact--;
	}
}
