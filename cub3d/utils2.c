/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:29:19 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 17:45:28 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_all *all)
{
	mlx_destroy_window(all->mlx, all->win);
	exit(0);
	return (0);
}

void	reallocation(t_spr *spr, int i, t_fmt *fmt)
{
	double	*tmpx;
	double	*tmpy;
	int		iter;

	tmpx = malloc(sizeof(double) * (spr->len + 1));
	tmpy = malloc(sizeof(double) * (spr->len + 1));
	iter = 0;
	while (iter < spr->len)
	{
		tmpx[iter] = spr->sx[iter];
		tmpy[iter] = spr->sy[iter];
		iter++;
	}
	free(spr->sx);
	free(spr->sy);
	tmpx[iter] = i * 64;
	tmpy[iter] = fmt->map_size * 64;
	spr->sx = tmpx;
	spr->sy = tmpy;
	spr->len++;
}

void	ft_sprite(t_fmt *fmt, int i, t_spr *spr)
{
	if (spr->len == 0)
	{
		spr->sx = malloc(sizeof(double) * (spr->len + 1));
		spr->sy = malloc(sizeof(double) * (spr->len + 1));
		spr->sx[spr->len] = i * 64;
		spr->sy[spr->len] = fmt->map_size * 64;
		spr->len++;
	}
	else
		reallocation(spr, i, fmt);
}
