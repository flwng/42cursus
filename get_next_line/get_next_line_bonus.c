/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:08:30 by flwang            #+#    #+#             */
/*   Updated: 2021/01/22 11:54:17 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	del(t_buf **list, int fd)
{
	t_buf	*iter;
	t_buf	*temp;

	iter = *list;
	if (iter->fd == fd)
	{
		temp = iter->next;
		free(iter);
		*list = temp;
		return ;
	}
	while (iter->next->fd != fd)
		iter = iter->next;
	temp = find_fd(*list, fd);
	iter->next = temp->next;
	free(temp);
}

char	*reallocation(char **line)
{
	size_t	len;
	size_t	i;
	char	*new;

	len = ft_strlen(*line);
	if (!(new = malloc(len + BUFFER_SIZE + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = (*line)[i];
		i++;
	}
	new[i] = 0;
	free(*line);
	return (new);
}

int		newline(t_buf *list, char **line)
{
	int		found;
	size_t	len;
	size_t	iter;

	found = 0;
	iter = 0;
	if (!(*line = reallocation(line)))
		return (-1);
	len = ft_strlen(*line);
	while (list->buf[iter])
	{
		if (list->buf[iter] == '\n')
		{
			found = 1;
			iter++;
			break ;
		}
		(*line)[len++] = list->buf[iter++];
	}
	(*line)[len] = 0;
	len = 0;
	while (list->buf[iter])
		list->buf[len++] = list->buf[iter++];
	list->buf[len] = 0;
	return (found);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	*list;
	t_buf			*store;
	int				nl;
	int				r;

	if (BUFFER_SIZE <= 0 || (!list && !(list = new_node(fd))) ||
			!(store = find_fd(list, fd)) || fd < 0 || !line)
		return (-1);
	*line = 0;
	nl = 0;
	nl = newline(store, line);
	if (nl == 1 || nl == -1)
		return (nl);
	while ((r = read(fd, store->buf, BUFFER_SIZE)) > 0)
	{
		store->buf[r] = 0;
		nl = newline(store, line);
		if (nl == 1)
			return (nl);
	}
	if (r == -1)
		return (-1);
	del(&list, fd);
	return (nl);
}
