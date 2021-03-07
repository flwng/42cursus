/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:52:04 by flwang            #+#    #+#             */
/*   Updated: 2021/03/06 20:12:21 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->zero = 0;
	info->minus = 0;
	info->negnum = 0;
}

void	width_neg_star(t_info *info)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
		info->zero = 0;
	}
}

void	prec_star(t_info *info, va_list ap)
{
	info->prec = va_arg(ap, int);
	if (info->prec < -1)
		info->prec = -1;
}

int		ft_skip(char c, char *flags)
{
	while (*flags)
	{
		if (c == *flags)
			return (1);
		flags++;
	}
	return (0);
}

int		read_flags(const char **s, t_info *info)
{
	if (**s == '-')
	{
		info->minus = 1;
		info->zero = 0;
		(*s)++;
		return (1);
	}
	if (**s == '0')
	{
		if (info->minus == 0)
			info->zero = 1;
		(*s)++;
		return (1);
	}
	return (0);
}
