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
}		t_fmt;

t_fmt	read_info(int fd);
char	**read_map(char *line, t_fmt **fmt);
int	ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int n, char *base);
#endif
