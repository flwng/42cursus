/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:25:14 by flwang            #+#    #+#             */
/*   Updated: 2021/01/19 13:52:30 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*ptr;
	unsigned char		*ptr1;
	void				*nul;
	size_t				i;

	i = 0;
	ptr = src;
	ptr1 = dst;
	nul = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			ptr1[i] = ptr[i];
			return (dst + ++i);
		}
		ptr1[i] = ptr[i];
		i++;
	}
	return (nul);
}
