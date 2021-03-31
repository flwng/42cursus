/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:48:57 by flwang            #+#    #+#             */
/*   Updated: 2021/01/22 11:49:28 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *line)
{
	size_t	len;

	if (!line)
		return (0);
	len = 0;
	while (line[len])
		len++;
	return (len);
}

t_buf	*new_node(int fd)
{
	t_buf	*node;

	if (!(node = malloc(sizeof(t_buf))))
		return (0);
	node->fd = fd;
	node->buf[0] = 0;
	node->next = 0;
	return (node);
}

t_buf	*find_fd(t_buf *list, int fd)
{
	if (list->fd == fd)
		return (list);
	while (list->next)
	{
		if (list->next->fd == fd)
			return (list->next);
		list = list->next;
	}
	list->next = new_node(fd);
	return (list->next);
}
