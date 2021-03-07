/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:47:14 by flwang            #+#    #+#             */
/*   Updated: 2021/03/07 16:47:16 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len(size_t nb, char *base)
{
	int	lenght;

	lenght = 0;
	if (nb == 0)
		lenght++;
	while (nb > 0)
	{
		nb = nb / ft_strlen(base);
		lenght++;
	}
	return (lenght);
}

char	*ft_utoa(size_t n, char *base)
{
	char	*str;
	size_t	nb;
	int		i;

	nb = n;
	i = len(n, base);
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[i--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	return (str);
}

int		print_x(t_info *info, va_list ap)
{
	size_t	tmp;
	int		count;
	char	*tmp2;
	int		len;

	count = 0;
	tmp = (size_t)(va_arg(ap, unsigned int));
	tmp2 = ft_utoa(tmp, "0123456789abcdef");
	len = ft_strlen(tmp2);
	if (tmp == 0 && info->prec == 0)
		zero_noprec(info, &count);
	else if (tmp == 0 && info->prec != 0)
		zero_with_prec(info, &count);
	else
	{
		if (info->minus == 0)
			num_nominus(info, &count, len, &tmp2);
		else
			num_minus(info, &count, len, tmp2);
	}
	free(tmp2);
	return (count);
}

int		print_upx(t_info *info, va_list ap)
{
	size_t	tmp;
	int		count;
	char	*tmp2;
	int		len;

	count = 0;
	tmp = (size_t)(va_arg(ap, unsigned int));
	tmp2 = ft_utoa(tmp, "0123456789ABCDEF");
	len = ft_strlen(tmp2);
	if (tmp == 0 && info->prec == 0)
		zero_noprec(info, &count);
	else if (tmp == 0 && info->prec != 0)
		zero_with_prec(info, &count);
	else
	{
		if (info->minus == 0)
			num_nominus(info, &count, len, &tmp2);
		else
			num_minus(info, &count, len, tmp2);
	}
	free(tmp2);
	return (count);
}
