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
# include <math.h>

# define PI 3.1415926535

typedef struct s_img
{
	void	*img;
	char	*adr;
	int		bpp;
	int		len;
	int		end;
}				t_img;

typedef struct s_fmt
{
	int			res_x;
	int			res_y;
	int			propx;
	int			propy;
	float		ppy;
	float		ppx;
	int			floor;
	int			ceil;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	char		**map;
	int			map_size;
	double		px;
	double		py;
	double		pa;
	double		dir_x;
	double		dir_y;
	int			mapb;
}				t_fmt;

typedef struct s_cam
{
	double		rx;
	double		ry;
	double		ra;
	double		dist;
	char		sidehit;
	char		sprite_hit;
	double		lineh;
	double		lineo;
	double		dist_sprite;
}				t_cam;

typedef struct s_tex
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_img		sprite;
	int			nw;
	int			nh;
	int			sw;
	int			sh;
	int			ew;
	int			eh;
	int			ww;
	int			wh;
	int			spw;
	int			sph;
	double		tx;
	double		ty;
	double		ty_step;
	double		ty_o;
}				t_tex;

typedef struct s_spr
{
	double		*sx;
	double		*sy;
	double		*dist;
	int			*center;
	int			len;
	int			*act;
	int			nact;
	double		spriteh;
	double		start;
	double		end;
	double		spritex;
	double		spritey;
}				t_spr;

typedef struct s_all
{
	t_img	img;
	t_fmt	fmt;
	t_cam	cam;
	t_tex	tex;
	t_spr	spr;
	void	*mlx;
	void	*win;
	int		key[126];
}				t_all;

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			clear_image(t_img *img, t_fmt fmt);
void			print_error(void);
t_fmt			read_info(char *argv, t_spr *spr);
char			**read_map(char *line, t_fmt **fmt);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa_base(int n, char *base);
void			init_fmt(t_fmt *fmt);
void			check_double(char *line, t_fmt fmt);
void			map_lastrow(t_fmt fmt);
void			check_nl_map(char *line, int *map_nl, int *map);
void			check_fmt(t_fmt *fmt);
void			check_mapline(char *line, t_fmt *fmt, t_spr *spr);
void			map_firstrow(char *line, t_fmt fmt);
void			load_images(t_fmt *fmt, void *mlx, t_tex *tex);
void			move_player(t_all *all);
void			draw_ray(t_all *all);
void			check_h(t_all *all, double *disth);
void			check_v(t_all *all, double disth);
void			get_wall_text(t_all *all, int r_count);
void			ceil_floor(t_img *img, t_fmt *fmt);
void			get_sprite(t_all *all, int r_count);
void			ft_sprite(t_fmt *fmt, int i, t_spr *spr);
unsigned int	get_tex_color(t_img *data, int x, int y);
void			get_sprite(t_all *all, int r_count);
void			get_center(t_all *all);
int				rgb_hex(char *line);
void			ft_screenshot(char *argv, t_all *all);
int				close_win(t_all *all);
#endif
