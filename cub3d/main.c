/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:00:41 by flwang            #+#    #+#             */
/*   Updated: 2021/05/05 19:48:03 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	key_press(int key, t_all *all)
{
	int	i;

	i = 0;
	if (key == 53)
	{
		while (i < all->fmt.map_size)
			free(all->fmt.map[i++]);
		free(all->fmt.map);
		exit(0);
	}
	all->key[key] = 1;
	return (0);
}

int	key_release(int key, t_all *all)
{
	all->key[key] = 0;
	return (0);
}

int	loop(t_all *all)
{
	move_player(all);
	get_center(all);
	all->img.img = mlx_new_image(all->mlx, all->fmt.res_x, all->fmt.res_y);
	all->img.adr = mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.len, &all->img.end);
	ceil_floor(&all->img, &all->fmt);
	draw_ray(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	mlx_destroy_image(all->mlx, all->img.img);
	return (0);
}

void	start(char *argv, t_all *all)
{
	int	max_x;
	int	max_y;

	ft_bzero(all->key, 126);
	all->spr.len = 0;
	all->fmt = read_info(argv, &all->spr);
	all->spr.dist = malloc(sizeof(double) * all->spr.len);
	all->spr.act = malloc(sizeof(int) * all->spr.len);
	all->spr.center = malloc(sizeof(int) * all->spr.len);
	load_images(&(all->fmt), all->mlx, &(all->tex));
	all->fmt.ppx = all->fmt.px * 64 + 32;
	all->fmt.ppy = all->fmt.py * 64 + 32;
	mlx_get_screen_size(all->mlx, &max_x, &max_y);
	if (all->fmt.res_x > max_x)
		all->fmt.res_x = max_x;
	if (all->fmt.res_y > max_y)
		all->fmt.res_y = max_y;
	all->win = mlx_new_window(all->mlx, all->fmt.res_x,
			all->fmt.res_y, "prova");
	mlx_hook(all->win, 2, 1L << 0, key_press, all);
	mlx_hook(all->win, 3, 1L << 1, key_release, all);
	mlx_hook(all->win, 17, 1L << 17, close_win, all);
	mlx_loop_hook(all->mlx, loop, all);
	mlx_loop(all->mlx);
}

int	main(int argc, char **argv)
{
	t_all	all;
	int		i;

	if ((argc == 3 && (ft_strncmp("--save", argv[2], 6)) == 0))
	{
		i = ft_strlen(argv[1]);
		if (argv[1][i - 1] != 'b' && argv[1][i - 2] != 'u'
			&& argv[1][i - 3] != 'c' && argv[1][i - 4] != '.')
			print_error();
		all.mlx = mlx_init();
		ft_screenshot(argv[1], &all);
	}
	else if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		if (argv[1][i - 1] != 'b' && argv[1][i - 2] != 'u'
			&& argv[1][i - 3] != 'c' && argv[1][i - 4] != '.')
			print_error();
		all.mlx = mlx_init();
		start(argv[1], &all);
	}
	else
		print_error();
}
