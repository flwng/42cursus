/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_h.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:26:33 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:56:31 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_parallel(t_all *all)
{
	if (all->cam.ra == 0 || all->cam.ra == PI)
	{
		all->cam.rx = all->fmt.ppx;
		all->cam.ry = all->fmt.ppy;
		return (1);
	}
	return (0);
}

void	find_sprite_h(t_all *all)
{
	int	i;

	if (all->fmt.map[(int)all->cam.ry / 64][(int)all->cam.rx / 64] == '2')
	{
		i = 0;
		while (i < all->spr.len)
		{
			if (i < all->spr.nact && all->spr.act[i] == i)
				break ;
			else if (all->cam.rx >= all->spr.sx[i]
				&& all->cam.rx <= all->spr.sx[i] + 64 && all->cam.ry >= \
				all->spr.sy[i] && all->cam.ry <= all->spr.sy[i] + 64 )
			{
				all->spr.act[all->spr.nact] = i;
				all->spr.nact++;
				break ;
			}
			i++;
		}
	}
}

void	find_wall_sprite(t_all *all, double *disth, double xo, double yo)
{
	while (1)
	{
		if (all->cam.ry > (all->fmt.map_size - 1) * 64 || all->cam.rx < 0
			|| all->cam.ry < 0 || all->fmt.map[(int)all->cam.ry / 64] \
			[(int)all->cam.rx / 64] == '1')
		{
			*disth = sqrt(pow(all->cam.rx - all->fmt.ppx, 2) + \
					pow(all->cam.ry - all->fmt.ppy, 2));
			break ;
		}
		find_sprite_h(all);
		all->cam.rx += xo;
		all->cam.ry += yo;
	}
}

void	check_h(t_all *all, double *disth)
{
	int		cond;
	double	xo;
	double	yo;

	cond = 0;
	if (all->cam.ra < PI)
	{
		all->cam.ry = (((int)all->fmt.ppy / 64) * 64) + 64;
		all->cam.rx = (all->fmt.ppy - all->cam.ry) * -1 / tan(all->cam.ra) \
					  + all->fmt.ppx;
		yo = 64;
		xo = -yo * -1 / tan(all->cam.ra);
	}
	if (all->cam.ra > PI)
	{
		all->cam.ry = (((int)all->fmt.ppy / 64) * 64) - 0.0001;
		all->cam.rx = (all->fmt.ppy - all->cam.ry) * -1 / tan(all->cam.ra) \
					  + all->fmt.ppx;
		yo = -64;
		xo = -yo * -1 / tan(all->cam.ra);
	}
	cond = x_parallel(all);
	if (cond == 0)
		find_wall_sprite(all, disth, xo, yo);
}
