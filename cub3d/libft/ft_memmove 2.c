/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:25:01 by flwang            #+#    #+#             */
/*   Updated: 2021/01/14 16:29:21 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		*invd;
	unsigned const char	*invs;

	if (dst == 0 && src == 0)
		return (0);
	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		invd = d + (len - 1);
		invs = s + (len - 1);
		while (len--)
			*invd-- = *invs--;
	}
	return (dst);
}
