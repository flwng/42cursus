#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <string.h>

typedef struct	s_img
{
	void	*img;
	char	*adr;
	int		bpp;
	int		len;
	int		end;
}			t_img;

typedef struct	s_fmt
{
	int	res_x;
	int	res_y;
	int	floor;
	int	ceil;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*sprite;
	char	**map;
	int	map_size;
	int	px;
	int	py;
	char	pdir;
}		t_fmt;

void	print_error(void);
t_fmt	read_info(int fd);
char	**read_map(char *line, t_fmt **fmt);
int	ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int n, char *base);
void	init_fmt(t_fmt *fmt);
void	check_double(char *line, t_fmt fmt);
void	map_lastrow(t_fmt fmt);
void	check_nl_map(char *line, int *map_nl, int *map);
void	check_fmt(t_fmt fmt);
void	check_mapline(char *line, t_fmt *fmt);
void	map_firstrow(char *line);
#endif
