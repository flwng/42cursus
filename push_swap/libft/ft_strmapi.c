/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:47:46 by flwang            #+#    #+#             */
/*   Updated: 2021/01/18 17:48:56 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int			len;
	char					*ptr;
	unsigned int			i;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (!(ptr = malloc(len + 1)))
		return (0);
	while (s[i])
	{
		ptr[i] = f(i, (char)s[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
