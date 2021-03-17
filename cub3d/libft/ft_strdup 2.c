/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:46:33 by flwang            #+#    #+#             */
/*   Updated: 2021/01/13 19:21:41 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void		*ptr;
	size_t		len;

	len = ft_strlen(s1) + 1;
	if (!(ptr = malloc(len)))
		return (0);
	return (char *)(ft_memcpy(ptr, s1, len));
}
