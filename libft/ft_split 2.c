/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:50 by flwang            #+#    #+#             */
/*   Updated: 2021/01/14 11:30:39 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	char	*startw;
	size_t	index;
	size_t	size;

	if (!(split = (char **)malloc(sizeof(char *) * cntword(s, c) + 1)))
		return (0);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			startw = (char *)s;
			while (*s && *s != c)
				s++;
			size = s - startw + 1;
			if (!(split[index] = (char *)malloc(size)))
				return (0);
			ft_strlcpy(split[index++], startw, size);
		}
		else
			s++;
	}
	split[index] = 0;
	return (split);
}
