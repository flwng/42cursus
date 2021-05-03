/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:42:38 by flwang            #+#    #+#             */
/*   Updated: 2021/04/30 15:56:25 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_map2d(t_all *all)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = -1;
	while (++y < all->fmt.map_size)
	{
		x = -1;
		while (++x < ft_strlen(all->fmt.map[y]))
		{
			if (all->fmt.map[y][x] == '1')
			{
				i = y * 64 - 1;
				while (++i < (y + 1) * 64)
				{
					j = x * 64 - 1;
					while (++j < (x + 1) * 64)
						my_mlx_pixel_put(&(all->img), j, i, 0xff00000);
				}
			}
		}
	}
}

void	draw_player(t_all *all)
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
	while (all->fmt.map[y / 64][x / 64] != '1')
	{
		my_mlx_pixel_put(&(all->img), x, y, 0x0000ff00);
		y += all->fmt.dir_y * 64;
		x += all->fmt.dir_x * 64;
	}
}
