/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:11:20 by flwang            #+#    #+#             */
/*   Updated: 2020/11/02 19:11:22 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	basei(char c, char *base)
{
	int count;

	count = 0;
	while (*base != c)
	{
		count++;
		base++;
	}
	return (count);
}

int	ft_atoi_rev(char *str, int len, char *base)
{
	int sum;
	int sign;

	sign = 1;
	sum = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= base[0] && *str <= base[len - 1])
	{
		sum = sum * len + basei(*str, base);
		str++;
	}
	return (sum * sign);
}

int	is_valid(char *base, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int l;
	int s;

	l = ft_strlen(base);
	if (l == 0 || l == 1 || is_valid(base, l) == 0)
		return (0);
	s = ft_atoi_rev(str, l, base);
	return (s);
}
