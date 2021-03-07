/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_%.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:09:56 by mbus              #+#    #+#             */
/*   Updated: 2021/03/06 16:07:31 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_perc(t_info *info)
{
	char	w;
	int		count;

	count = 0;
	w = ' ';
	if (info->zero == 1)
		w = '0';
	if (info->minus == 0)
	{
		while (count++ < info->width - 1)
			write(1, &w, 1);
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		while (count++ < info->width - 1)
			write(1, &w, 1);
	}
	return (count);
}
