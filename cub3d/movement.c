/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:58:16 by flwang            #+#    #+#             */
/*   Updated: 2021/04/24 19:59:18 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_down(t_all *all)
{
	if (all->key[13] && !all->key[1])
	{
		all->fmt.ppy += all->fmt.dir_y * 5;
		all->fmt.ppx += all->fmt.dir_x * 5;
		if (all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '1' \
			|| all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '2')
		{
			all->fmt.ppy -= all->fmt.dir_y * 5;
			all->fmt.ppx -= all->fmt.dir_x * 5;
		}
	}
	else if (all->key[1] && !all->key[13])
	{
		all->fmt.ppy -= all->fmt.dir_y * 5;
		all->fmt.ppx -= all->fmt.dir_x * 5;
		if (all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '1' \
			|| all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '2')
		{
			all->fmt.ppy += all->fmt.dir_y * 5;
			all->fmt.ppx += all->fmt.dir_x * 5;
		}
	}
}

void	left_right(t_all *all)
{
	if (all->key[0] && !all->key[2])
	{
		all->fmt.ppx -= 5 * -sin(all->fmt.pa);
		all->fmt.ppy -= 5 * cos(all->fmt.pa);
		if (all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '1' \
			|| all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '2')
		{
			all->fmt.ppx += 5 * -sin(all->fmt.pa);
			all->fmt.ppy += 5 * cos(all->fmt.pa);
		}
	}
	else if (all->key[2] && !all->key[0])
	{
		all->fmt.ppx += 5 * -sin(all->fmt.pa);
		all->fmt.ppy += 5 * cos(all->fmt.pa);
		if (all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '1' \
			|| all->fmt.map[(int)all->fmt.ppy / 64][(int)all->fmt.ppx / 64] == '2')
		{
			all->fmt.ppx -= 5 * -sin(all->fmt.pa);
			all->fmt.ppy -= 5 * cos(all->fmt.pa);
		}
	}
}

void	move_player(t_all *all)
{
	up_down(all);
	left_right(all);
	if (all->key[124] && !all->key[123])
	{
		all->fmt.pa += 0.1;
		if (all->fmt.pa > 2 * PI)
			all->fmt.pa -= 2 * PI;
		all->fmt.dir_x = cos(all->fmt.pa);
		all->fmt.dir_y = sin(all->fmt.pa);
	}
	else if (all->key[123] && !all->key[124])
	{
		all->fmt.pa -= 0.1;
		if (all->fmt.pa < 0)
			all->fmt.pa += 2 * PI;
		all->fmt.dir_x = cos(all->fmt.pa);
		all->fmt.dir_y = sin(all->fmt.pa);
	}
}
