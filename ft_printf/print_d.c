/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:16:19 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:33:26 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr(char *tmp2, int *count)
{
	while (*tmp2)
	{
		write(1, tmp2, 1);
		(*count)++;
		tmp2++;
	}
}

int		print_d(t_info *info, va_list ap)
{
	int		count;
	int		tmp;
	char	*tmp2;
	int		len;
	char	*tofree;

	count = 0;
	tmp = va_arg(ap, int);
	tmp2 = ft_itoa(tmp);
	tofree = tmp2;
	len = ft_strlen(tmp2);
	if (tmp == 0)
		(info->prec == 0) ? zero_noprec(info, &count) :
			zero_with_prec(info, &count);
	else
	{
		count = neg_int(tmp, &tmp2, &len, info);
		if (info->minus == 0)
			num_nominus(info, &count, len, &tmp2);
		else
			num_minus(info, &count, len, tmp2);
	}
	free(tofree);
	return (count);
}

void	ft_negnum(t_info *info, int *count, int *len, char **tmp2)
{
	write(1, "-", 1);
	(*tmp2)++;
	(*count)++;
	if (info->width == 0)
	{
		while (info->prec + 1 > (*len)++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	else
	{
		while (info->prec + 1 > (*len)++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
}
