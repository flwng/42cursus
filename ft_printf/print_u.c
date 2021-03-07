/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:29:05 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:23:37 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_zero_with_prec(t_info *info, int *count)
{
	char w;

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

void	u_zero_noprec(t_info *info, int *count)
{
	while ((*count)++ < info->width)
		write(1, " ", 1);
	(*count)--;
}

void	u_num_nominus(t_info *info, int *count, int len)
{
	char w;

	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	if (info->prec > len)
	{
		while ((*count)++ < info->width - info->prec)
			write(1, &w, 1);
		(*count)--;
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
}

void	u_num_minus(t_info *info, int *count, int len, char *tmp2)
{
	if (info->prec > len)
	{
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

int		print_u(t_info *info, va_list ap)
{
	int		count;
	size_t	tmp;
	char	*tmp2;
	int		len;

	count = 0;
	tmp = (size_t)va_arg(ap, unsigned int);
	tmp2 = ft_utoa(tmp, "0123456789");
	len = ft_strlen(tmp2);
	if (tmp == 0 && info->prec == 0)
		u_zero_noprec(info, &count);
	else if (tmp == 0 && info->prec != 0)
		u_zero_with_prec(info, &count);
	else
	{
		if (info->minus == 0)
		{
			u_num_nominus(info, &count, len);
			putstr(tmp2, &count);
		}
		else
			u_num_minus(info, &count, len, tmp2);
	}
	free(tmp2);
	return (count);
}
