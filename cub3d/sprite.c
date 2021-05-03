/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:43:55 by flwang            #+#    #+#             */
/*   Updated: 2021/05/02 18:27:31 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	adjust_fray(double *fray)
{
	if (*fray > 2 * PI)
		*fray -= 2 * PI;
	else if (*fray < 0)
		*fray += 2 * PI;
}

void	get_center(t_all *all)
{
	int		i;
	double	fray;
	double	tmp;
	double	tmp2;

	i = 0;
	fray = -(all->fmt.pa - PI / 6 - 2 * PI);
	adjust_fray(&fray);
	while (i < all->spr.len)
	{
		all->spr.dist[i] = sqrt(pow(all->spr.sx[i] + 32 - all->fmt.ppx, 2) \
				+ pow(all->spr.sy[i] + 32 - all->fmt.ppy, 2));
		tmp = atan2(-(all->spr.sy[i] + 32 - all->fmt.ppy), all->spr.sx[i] \
				+ 32 - all->fmt.ppx);
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
}

void	draw_sprite(t_all *all, int r_count, double stepy, double sprite_yo)
{
	int		y;
	double	spriteo;

	spriteo = all->fmt.res_y / 2 - all->spr.spriteh / 2;
	all->spr.spritey = sprite_yo * stepy;
	y = 0;
	while (y < all->spr.spriteh && r_count >= all->spr.start
		&& r_count <= all->spr.end)
	{
		if (get_tex_color(&all->tex.sprite, all->spr.spritex, \
			all->spr.spritey) != 0)
			my_mlx_pixel_put(&all->img, r_count, y + spriteo, \
			get_tex_color(&all->tex.sprite, all->spr.spritex, \
			all->spr.spritey));
		y++;
		all->spr.spritey += stepy;
	}
}

void	get_start_end(t_all *all)
{
	all->spr.start = all->spr.center[all->spr.act[all->spr.nact - 1]] \
					 - ((all->spr.spriteh) / 2);
	all->spr.end = all->spr.center[all->spr.act[all->spr.nact - 1]] \
				  + ((all->spr.spriteh) / 2);
}

void	get_sprite(t_all *all, int r_count)
{
	double	stepy;
	double	sprite_yo;

	while (all->spr.nact > 0)
	{
		if (all->cam.dist > all->spr.dist[all->spr.act[all->spr.nact - 1]])
		{
			all->spr.spriteh = 64 * all->fmt.res_y \
							/ all->spr.dist[all->spr.act[all->spr.nact - 1]];
			stepy = all->tex.sph / all->spr.spriteh;
			sprite_yo = 0;
			get_start_end(all);
			all->spr.spritex = ((int)((r_count - all->spr.start)) % (int)(all->spr.spriteh)) \
							   * all->tex.spw / (all->spr.spriteh);
			if (all->spr.spriteh > all->fmt.res_y)
			{
				sprite_yo = (all->spr.spriteh - all->fmt.res_y) / 2;
				all->spr.spriteh = all->fmt.res_y;
			}
			draw_sprite(all, r_count, stepy, sprite_yo);
		}
		all->spr.nact--;
	}
}
