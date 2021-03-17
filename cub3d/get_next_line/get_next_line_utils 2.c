/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltortora <ltortora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:28:29 by ltortora          #+#    #+#             */
/*   Updated: 2021/02/02 16:55:44 by ltortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_nstrlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char			*ft_strnjoin(char *s1, char *s2)
{
	char					*newstr;
	unsigned int			i;
	unsigned int			len1;
	unsigned int			len2;

	if (!s1 && !s2)
		return (0);
	len1 = (s1) ? ft_nstrlen(s1) : 0;
	len2 = (s2) ? ft_nstrlen(s2) : 0;
	i = 0;
	if (!(newstr = malloc(len1 + len2 + 1)))
		return (0);
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < len1 + len2)
	{
		newstr[i] = s2[i - len1];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

int				freestuff(char **line, char *buff)
{
	free(*line);
	*line = 0;
	free(buff);
	return (-1);
}

int				defr(char **line, int fd)
{
	int r;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	else
		r = 1;
	return (r);
}
