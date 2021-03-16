#include "cub3d.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

int	start(char *argv, void **mlx)
{
	t_fmt	fmt;
	int	fd;
	void	*win;

	fd = open(argv, O_RDONLY);
	fmt = read_info(fd);
	win = mlx_new_window(*mlx, fmt.res_x, fmt.res_y, "prova");
	mlx_loop(*mlx);
	return (1);
}

int main(int argc, char **argv)
{
	void	*mlx;

	if ((argc == 2 && ft_strncmp("--save", argv[1], 6)) == 0 || argc == 1)
		return (-1);
	else
	{
		mlx = mlx_init();
		start(argv[1], &mlx);
	}
}
