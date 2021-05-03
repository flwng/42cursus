/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:38:50 by flwang            #+#    #+#             */
/*   Updated: 2021/05/03 14:28:35 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nextline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	checkavanzo(char avanzo[BUFFER_SIZE + 1], char *buff)
{
	int	i;
	int	j;

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

int	init(char **line, int *ris, char **buff, int fd)
{
	*line = 0;
	*buff = malloc(BUFFER_SIZE + 1);
	*ris = defr(line, fd);
	if (*ris == -1 || !*buff)
		return (-1);
	*ris = 1;
	*buff[0] = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char				avanzo[BUFFER_SIZE + 1];
	char					*buff;
	int						ris;

	if ((init(line, &ris, &buff, fd)) == -1)
		return (-1);
	*line = ft_strnjoin(*line, avanzo);
	while (ris > 0)
	{
		if (nextline(avanzo) == 1 || nextline(buff) == 1)
			break ;
		ris = read(fd, buff, BUFFER_SIZE);
		if (ris == -1)
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
