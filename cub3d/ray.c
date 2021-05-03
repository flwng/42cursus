/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:04:54 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 15:49:02 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ty_step(t_all *all)
{
	if (all->cam.ra > PI && all->cam.sidehit == 'h')
		all->tex.ty_step = all->tex.nh / all->cam.lineh;
	else if (all->cam.ra < PI && all->cam.sidehit == 'h')
		all->tex.ty_step = all->tex.sh / all->cam.lineh;
	else if (all->cam.ra > PI * 3 / 2 || all->cam.ra < PI / 2)
		all->tex.ty_step = all->tex.eh / all->cam.lineh;
	else if (all->cam.ra > PI / 2 && all->cam.ra < 3 * PI / 2)
		all->tex.ty_step = all->tex.wh / all->cam.lineh;
}

void	draw_walls_sprite(t_all *all, int r_count)
{
	double	ca;

	ca = all->fmt.pa - all->cam.ra;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	else if (ca < 0)
		ca += 2 * PI;
	all->cam.dist *= cos(ca);
	all->cam.lineh = 64 * all->fmt.res_y / all->cam.dist;
	get_ty_step(all);
	all->tex.ty_o = 0;
	if (all->cam.lineh > all->fmt.res_y)
	{
		all->tex.ty_o = (all->cam.lineh - all->fmt.res_y) / 2;
		all->cam.lineh = all->fmt.res_y;
	}
	all->cam.lineo = all->fmt.res_y / 2 - all->cam.lineh / 2;
	all->tex.ty = all->tex.ty_o * all->tex.ty_step;
	get_wall_text(all, r_count);
	get_sprite(all, r_count);
	all->cam.ra += 1.0472 / all->fmt.res_x;
}

void	get_min_dist(t_all *all, double tmpx, double tmpy, double disth)
{
	if (disth < all->cam.dist)
	{	
		all->cam.rx = tmpx;
		all->cam.ry = tmpy;
		all->cam.dist = disth;
		all->cam.sidehit = 'h';
	}
}

void	init_var(t_all *all, double *disth)
{
	int		i;

	i = 0;
	while (i < all->spr.len)
		all->spr.act[i++] = -1;
	all->spr.nact = 0;
	all->cam.dist_sprite = 10000000;
	*disth = 10000000;
}

void	draw_ray(t_all *all)
{
	int		r_count;
	double	tmpx;
	double	tmpy;
	double	disth;

	r_count = 0;
	all->cam.ra = all->fmt.pa - PI / 6;
	if (all->cam.ra < 0)
		all->cam.ra += 2 * PI;
	all->cam.sprite_hit = 0;
	while (r_count < all->fmt.res_x)
	{
		init_var(all, &disth);
		check_h(all, &disth);
		tmpx = all->cam.rx;
		tmpy = all->cam.ry;
		check_v(all, disth);
		get_min_dist(all, tmpx, tmpy, disth);
		draw_walls_sprite(all, r_count);
		if (all->cam.ra > PI * 2)
			all->cam.ra -= PI * 2;
		r_count++;
	}
}
