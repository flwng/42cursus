/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:46:38 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:46:40 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_info *info, va_list ap)
{
	char	w;
	char	c;
	int		count;

	count = 0;
	c = va_arg(ap, int);
	if (info->zero == 0)
		w = ' ';
	else
		w = '0';
	if (info->minus == 0)
		while (count++ < info->width - 1)
			write(1, &w, 1);
	if (info->prec != 0)
		write(1, &c, 1);
	if (info->minus == 1)
		while (count++ < info->width - 1)
			write(1, &w, 1);
	return (count);
}

char	*str_null(char *tmp, int *null)
{
	if (tmp == 0)
	{
		*null = 1;
		tmp = malloc(7);
		tmp[0] = '(';
		tmp[1] = 'n';
		tmp[2] = 'u';
		tmp[3] = 'l';
		tmp[4] = 'l';
		tmp[5] = ')';
		tmp[6] = 0;
	}
	return (tmp);
}

int		str_nominus(t_info *info, int len, char w, char *tmp)
{
	int	count;

	count = 0;
	if (info->minus == 0)
	{
		if (info->prec != -1)
			while (count++ < info->width - info->prec)
				write(1, &w, 1);
		else
			while (count++ < info->width - len)
				write(1, &w, 1);
		if (info->prec >= 0)
		{
			write(1, tmp, info->prec);
			count += info->prec;
		}
		else
		{
			write(1, tmp, len);
			count += len;
		}
	}
	return (count);
}

int		str_minus(t_info *info, int len, char w, char *tmp)
{
	int count;

	count = 0;
	if (info->minus == 1)
	{
		if (info->prec != -1)
		{
			write(1, tmp, info->prec);
			count += info->prec;
		}
		else
		{
			write(1, tmp, len);
			count += len;
		}
		while (count++ < info->width)
			write(1, &w, 1);
	}
	return (count);
}

int		print_s(t_info *info, va_list ap)
{
	char	*tmp;
	char	w;
	int		len;
	int		count;
	int		null;

	count = 0;
	null = 0;
	tmp = va_arg(ap, char *);
	tmp = str_null(tmp, &null);
	len = ft_strlen(tmp);
	if (info->prec > len)
		info->prec = len;
	if (info->zero == 0)
		w = ' ';
	else
		w = '0';
	count += str_nominus(info, len, w, tmp);
	count += str_minus(info, len, w, tmp);
	if (null == 1)
		free(tmp);
	return (count - 1);
}
