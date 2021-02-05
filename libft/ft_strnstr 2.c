/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:51:49 by flwang            #+#    #+#             */
/*   Updated: 2021/01/14 19:20:54 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	l;

	if (!len && (!*haystack || !*needle))
		return (char *)(haystack);
	while (*haystack && len)
	{
		i = 0;
		k = 0;
		l = len;
		if (!(needle[i]) || !haystack[i])
			return (char *)(haystack);
		while (needle[i] == *(haystack + k++) && l)
		{
			if (needle[i + 1] == 0)
				return (char *)(haystack);
			l--;
			i++;
		}
		if (len-- < ft_strlen(needle))
			return (0);
		haystack++;
	}
	return (0);
}
