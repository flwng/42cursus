/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:19:50 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:35:13 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	s;

	s = 0;
	if (n < 0)
	{
		while (n <= -10)
		{
			s++;
			n = n / 10;
		}
		s += 1;
	}
	else
	{
		while (n >= 10)
		{
			s++;
			n = n / 10;
		}
	}
	return (s + 1);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	nbr;
	int				limit;
	int				len;

	len = size(n);
	limit = 0;
	ptr = malloc(len + 1);
	if (!(ptr))
		return (0);
	ptr[len--] = 0;
	if (n < 0)
	{
		nbr = (unsigned int)(n * -1);
		ptr[0] = '-';
		limit += 1;
	}
	else
		nbr = (unsigned int)n;
	while (len >= limit)
	{
		ptr[len--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (ptr);
}
