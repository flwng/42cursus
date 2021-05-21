/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:55:00 by flwang            #+#    #+#             */
/*   Updated: 2021/01/14 19:07:49 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (!(sub = malloc(len + 1)))
		return (0);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
