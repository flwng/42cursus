/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:25:18 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:14:25 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_with_prec(t_info *info, int *count)
{
	char	w;

	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	if (info->prec == -1)
		info->prec = 1;
	if (info->minus == 0)
	{
		while ((*count)++ < info->width - info->prec)
			write(1, &w, 1);
		while (info->prec-- > 0)
		{
			write(1, "0", 1);
			(*count)++;
		}
		(*count)--;
	}
	else
	{
		while ((*count)++ < info->prec)
			write(1, "0", 1);
		(*count)--;
		while ((*count)++ < info->width)
			write(1, &w, 1);
		(*count)--;
	}
}

void	zero_noprec(t_info *info, int *count)
{
	char	w;

	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	while ((*count)++ < info->width)
		write(1, &w, 1);
	(*count)--;
}

int		neg_int(int tmp, char **tmp2, int *len, t_info *info)
{
	if (tmp < 0)
	{
		info->negnum = 1;
		if (info->minus == 1 || (info->zero == 1 && info->prec == -1))
		{
			write(1, "-", 1);
			(*tmp2)++;
			return (1);
		}
	}
	return (0);
}

void	num_nominus(t_info *info, int *count, int len, char **tmp2)
{
	char	w;

	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	if (info->prec >= len)
	{
		if (info->negnum == 1)
			info->width--;
		while ((*count)++ < info->width - info->prec)
			write(1, &w, 1);
		(*count)--;
		if (info->negnum == 1)
			ft_negnum(info, count, &len, tmp2);
		while (info->prec > len++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	else
		while (info->width > len++)
		{
			write(1, &w, 1);
			(*count)++;
		}
	putstr(*tmp2, count);
}

void	num_minus(t_info *info, int *count, int len, char *tmp2)
{
	if (info->prec >= len)
	{
		if (info->negnum == 1)
			len--;
		while (info->prec > len++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	while (*tmp2)
	{
		write(1, tmp2, 1);
		(*count)++;
		tmp2++;
	}
	while (info->width > (*count)++)
		write(1, " ", 1);
	(*count)--;
}
