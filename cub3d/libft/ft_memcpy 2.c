/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:00:02 by flwang            #+#    #+#             */
/*   Updated: 2021/01/13 17:06:47 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*ptr;
	unsigned char		*ptr1;
	size_t				i;

	i = 0;
	ptr = src;
	ptr1 = dst;
	if (!ptr && !ptr1)
		return (0);
	while (i < n)
	{
		ptr1[i] = ptr[i];
		i++;
	}
	return (dst);
}
