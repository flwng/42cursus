/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:08:26 by flwang            #+#    #+#             */
/*   Updated: 2021/01/18 17:45:22 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ptr = malloc(len)))
		return (0);
	ft_strlcpy(ptr, s1, len);
	ft_strlcat(ptr, s2, len);
	free(s1);
	free(s2);
	return (ptr);
}
