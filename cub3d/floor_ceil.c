/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:19:51 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 17:05:41 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(int count, int r, int g, int b)
{
	if (count != 3)
		print_error();
	if (r < 0 || r > 255 || b < 0
		|| b > 255 || g < 0 || g > 255)
		print_error();
}

int	rgb_hex(char *line)
{
	int		count;
	int		r;
	int		g;
	int		b;

	count = 0;
	while (*line)
	{
		while (!(ft_isdigit(*(++line))))
			if ((*line == ',' && count == 0)
				|| !(ft_isspace(*line) && *line != ','))
				print_error();
		if (ft_isdigit(*line))
			count++;
		if (count == 1)
			r = ft_atoi(line);
		else if (count == 2)
			g = ft_atoi(line);
		else if (count == 3)
			b = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	error(count, r, g, b);
	return (r << 16 | g << 8 | b);
}
