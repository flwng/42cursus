/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:46:20 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:42:59 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = 0;
	if (c == 0)
		return (ft_strchr(s, 0));
	while (*s)
	{
		if (*s == (unsigned char)c)
			ptr = s;
		s++;
	}
	return ((char *)(ptr));
}
