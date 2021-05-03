/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:03:41 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:43:35 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinboth(char a, char const *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	k;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	k = 0;
	while (isinboth(s1[i], set) && s1[i])
		i++;
	while (isinboth(s1[len - 1], set) && i < len)
		len--;
	ptr = malloc(len - i + 1);
	if (!(ptr))
		return (0);
	while (i < len)
		ptr[k++] = s1[i++];
	ptr[k] = 0;
	return (ptr);
}
