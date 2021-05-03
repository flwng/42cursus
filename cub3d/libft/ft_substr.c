/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:55:00 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:44:09 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char		*sub;
	int			i;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (!(sub))
		return (0);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}
