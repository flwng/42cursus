/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:47:29 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:47:34 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*size_to_hex(size_t to_conv, char *base)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(len(to_conv, base));
	while (to_conv > 0)
	{
		tmp[i] = base[to_conv % 16];
		i++;
		to_conv = to_conv / 16;
	}
	tmp[i] = 0;
	return (tmp);
}

static int	null_p_nominus(t_info *info)
{
	int	count;

	if (info->prec == 0)
	{
		count = 2;
		write(1, "0x", 2);
		while (info->width > count++)
			write(1, " ", 1);
	}
	else
	{
		count = 3;
		write(1, "0x0", 3);
		while (info->width > count++)
			write(1, " ", 1);
	}
	count--;
	return (count);
}

static int	null_p(t_info *info)
{
	int	count;

	if (info->minus == 0)
	{
		if (info->prec == 0)
		{
			count = 2;
			while (info->width > count++)
				write(1, " ", 1);
			write(1, "0x", 2);
		}
		else
		{
			count = 3;
			while (info->width > count++)
				write(1, " ", 1);
			write(1, "0x0", 3);
		}
		count--;
	}
	else
		count = null_p_nominus(info);
	return (count);
}

static void	print_p2(int index, char *tmp, int *count, t_info *info)
{
	while (index >= 0)
	{
		write(1, &tmp[index], 1);
		(*count)++;
		index--;
	}
	if (info->minus == 1)
	{
		while (info->width > (*count)++)
			write(1, " ", 1);
		(*count)--;
	}
}

int			print_p(t_info *info, va_list ap)
{
	size_t	to_conv;
	int		count;
	char	*tmp;
	int		index;

	to_conv = (size_t)(va_arg(ap, void *));
	if (to_conv == 0)
		count = null_p(info);
	else
	{
		tmp = size_to_hex(to_conv, "0123456789abcdef");
		count = 2;
		if (info->minus == 0)
		{
			while (info->width > ft_strlen(tmp) + count++)
				write(1, " ", 1);
			count--;
		}
		write(1, "0x", 2);
		index = ft_strlen(tmp) - 1;
		print_p2(index, tmp, &count, info);
		free(tmp);
	}
	return (count);
}
