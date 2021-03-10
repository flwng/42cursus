/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltortora <ltortora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:37:11 by ltortora          #+#    #+#             */
/*   Updated: 2021/02/02 16:55:42 by ltortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				nextline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void			checkavanzo(char avanzo[BUFFER_SIZE + 1], char *buff)
{
	int i;
	int j;

	j = 0;
	if (nextline(avanzo) == 1)
	{
		i = ft_nstrlen(avanzo) + 1;
		while (avanzo[i + j])
		{
			avanzo[j] = avanzo[i + j];
			j++;
		}
		avanzo[j] = 0;
		return ;
	}
	i = ft_nstrlen(buff);
	if (buff[i] == '\n')
		i++;
	while (buff[i])
		avanzo[j++] = buff[i++];
	avanzo[j] = 0;
}

int				get_next_line(int fd, char **line)
{
	static char				avanzo[BUFFER_SIZE + 1];
	char					*buff;
	int						ris;

	*line = 0;
	ris = defr(line, fd);
	if (ris == -1 || !(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	*line = ft_strnjoin(*line, avanzo);
	ris = 1;
	buff[0] = 0;
	while (ris > 0)
	{
		if (nextline(avanzo) == 1 || nextline(buff) == 1)
			break ;
		if ((ris = read(fd, buff, BUFFER_SIZE)) == -1)
			return (freestuff(line, buff));
		buff[ris] = 0;
		*line = ft_strnjoin(*line, buff);
	}
	checkavanzo(avanzo, buff);
	free(buff);
	if (ris == 0)
		return (0);
	return (1);
}
