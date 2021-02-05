/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:05:55 by flwang            #+#    #+#             */
/*   Updated: 2021/01/18 11:29:47 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

typedef struct		s_buf
{
	int		fd;
	char		buf[BUFFER_SIZE + 1];
	struct s_buf	*next;
}			t_buf;

size_t			ft_strlen(char *line);
t_buf			*new_node(int fd);
t_buf			*find_fd(t_buf *list, int fd);

#endif
