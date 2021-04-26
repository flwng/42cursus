/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:35:29 by flwang            #+#    #+#             */
/*   Updated: 2021/04/26 20:26:43 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	y_parallel(t_all *all)
{
	if (all->cam.ra == PI * 3 / 2 || all->cam.ra == PI / 2)
	{
		all->cam.rx = all->fmt.ppx;
		all->cam.ry = all->fmt.ppy;
		return (1);
	}
	return (0);
}

void	find_wall_sprite_v(t_all *all, double xo, double yo, double disth)
{
	int	i;

	i = 0;
	while (1)
	{
		if (all->cam.ry  > (all->fmt.map_size - 1) * 64 || all->cam.rx < 0 || all->cam.ry < 0 ||
			all->fmt.map[(int)all->cam.ry / 64][(int)all->cam.rx / 64] == '1')
		{
			all->cam.dist = sqrt(pow(all->cam.rx - all->fmt.ppx, 2) + pow(all->cam.ry - all->fmt.ppy, 2));
			all->cam.sidehit = 'v';
			break ;
		}
		if (all->fmt.map[(int)all->cam.ry / 64][(int)all->cam.rx / 64] == '2' &&
			disth > sqrt(pow(all->cam.rx - all->fmt.ppx, 2) + pow(all->cam.ry - all->fmt.ppy, 2)))
		{
			i = 0;
			while (i < all->spr.len)
			{
				if (i < all->spr.nact && all->spr.act[all->spr.nact - 1] == i)
					break ;
				else if (all->cam.rx >= all->spr.sx[i] && all->cam.rx <= all->spr.sx[i] + 64 \
					&& all->cam.ry >= all->spr.sy[i] && all->cam.ry <= all->spr.sy[i] + 64 )
				{
					all->spr.act[all->spr.nact] = i;
					all->spr.nact++;
					break ;
				}
				i++;
			}
		}
		all->cam.rx += xo;
		all->cam.ry += yo;
	}
}

void	check_v(t_all *all, double disth)
{
	int		cond;
	double	xo;
	double	yo;

	cond = 0;
	if (all->cam.ra > PI / 2 && all->cam.ra < PI * 3 / 2)
	{
		all->cam.rx = (((int)all->fmt.ppx / 64) * 64) - 0.0001;
		all->cam.ry = (all->fmt.ppx - all->cam.rx) * -tan(all->cam.ra) + all->fmt.ppy;
		xo = -64;
		yo = -xo * -tan(all->cam.ra);
	}
	if (all->cam.ra > PI * 3 / 2 || all->cam.ra < PI / 2)
	{
		all->cam.rx = (((int)all->fmt.ppx / 64) * 64) + 64;
		all->cam.ry = (all->fmt.ppx - all->cam.rx) * -tan(all->cam.ra) + all->fmt.ppy;
		xo = 64;
		yo = -xo * -tan(all->cam.ra);
	}
	cond = y_parallel(all);
	if (cond == 0) 
		find_wall_sprite_v(all, xo, yo, disth);
}
