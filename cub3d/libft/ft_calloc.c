/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:37:16 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:34:06 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		alc;

	alc = size * count;
	ptr = malloc(alc);
	if (!(ptr))
		return (0);
	ft_bzero(ptr, alc);
	return (ptr);
}
