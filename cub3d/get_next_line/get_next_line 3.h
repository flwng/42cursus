/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltortora <ltortora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:52:37 by ltortora          #+#    #+#             */
/*   Updated: 2021/02/03 12:28:17 by ltortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#define BUFFER_SIZE 1
int				ft_nstrlen(char *s);
char			*ft_strnjoin(char *s1, char *s2);
int				nextline(char *str);
void			checkavanzo(char avanzo[BUFFER_SIZE + 1], char *buff);
int				get_next_line(int fd, char **line);
int				freestuff(char **line, char *buff);
int				defr(char **line, int fd);
#endif
