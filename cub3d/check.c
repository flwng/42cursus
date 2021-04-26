#include "cub3d.h"
#include <stdio.h>

void	check_double(char *line, t_fmt fmt)
{
	if (line[0] == 'N' && line[1] == 'O')
		if (fmt.north != 0)
			print_error();
	if (line[0] == 'S' && line[1] == 'O')
		if (fmt.south != 0)
			print_error();
	if (line[0] == 'E' && line[1] == 'A')
		if (fmt.east != 0)
			print_error();
	if (line[0] == 'W' && line[1] == 'E')
		if (fmt.west != 0)
			print_error();
	if (line[0] == 'S')
		if (fmt.sprite != 0)
			print_error();
	if (line[0] == 'R')
		if (fmt.res_x != -1 && fmt.res_y != -1)
			print_error();
	if (line[0] == 'F')
		if (fmt.floor != -1)
			print_error();
	if (line[0] == 'C')
		if (fmt.ceil != -1)
			print_error();
}

void	map_lastrow(t_fmt fmt)
{
	int i;

	i = 0;
	while (fmt.map[fmt.map_size - 1][i])
	{
		if (fmt.map[fmt.map_size - 1][i] != '1' &&
			!(ft_isspace(fmt.map[fmt.map_size - 1][i])))
			print_error();
		if (fmt.map[fmt.map_size - 2][i] == '0' &&
			fmt.map[fmt.map_size - 1][i] != '1')
			print_error();
	i++;
	}
}

void	check_nl_map(char *line, int *map_nl, int *map)
{
	if (!*map && (ft_isspace(*line) || *line == '1'))
		*map = 1;
	if (*map && *line == 0)
		*map_nl = 1;
	if (*map_nl && (ft_isspace(*line) || *line == '1'))
		print_error();
}

void	check_fmt(t_fmt fmt)
{
	if (fmt.ceil == 1 || fmt.floor == -1 || fmt.east == 0 || fmt.west == 0 ||
		fmt.north == 0 || fmt.south == 0 || fmt.px == -1 || fmt.sprite == 0 ||
		fmt.map == 0)
		print_error();
}	
