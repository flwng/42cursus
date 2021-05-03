#include "cub3d.h"

void	read_res(char *line, t_fmt **fmt)
{
	if (*line == 'R')
	{
		line++;
		while (ft_isspace(*line))
			line++;
		if (ft_isdigit(*line))
			(*fmt)->res_x = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line))
			line++;
		if (ft_isdigit(*line))
			(*fmt)->res_y = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		if (*line != 0)
			print_error();
	}
}

void	read_path(char *line, t_fmt **fmt)
{
	int	i;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (line[0] == 'N' && line[1] == 'O')
		(*fmt)->north = ft_strdup(line + i);
	else if (line[0] == 'S' && line[1] == 'O')
		(*fmt)->south = ft_strdup(line + i);
	else if (line[0] == 'E' && line[1] == 'A')
		(*fmt)->east = ft_strdup(line + i);
	else if (line[0] == 'W' && line[1] == 'E')
		(*fmt)->west = ft_strdup(line + i);
	else if (line[0] == 'S')
		(*fmt)->sprite = ft_strdup(line + i);
}

void	get_info(char *line, t_fmt *fmt)
{
	if (*line == 'R')
	{
		read_res(line, &fmt);
		if (fmt->res_x == -1 || fmt->res_y == -1)
			print_error();
	}
	else if (!(ft_strncmp(line, "NO", 2)) || !(ft_strncmp(line, "SO", 2))
		|| !(ft_strncmp(line, "WE", 2)) || !(ft_strncmp(line, "EA", 2))
		|| !(ft_strncmp(line, "S ", 2)))
		read_path(line, &fmt);
	else if (*line == 'F')
		fmt->floor = rgb_hex(line);
	else if (*line == 'C')
		fmt->ceil = rgb_hex(line);
	else if (ft_isspace(*line) || *line == '1')
		fmt->map = read_map(line, &fmt);
	else if (*line != 0)
		print_error();
}

void	check_map(char *line, t_fmt *fmt, t_spr *spr, int map)
{
	if (map && (fmt->map_size == 0 || fmt->map_size == 1))
		map_firstrow(line, *fmt);
	if (map && fmt->map_size > 0 && *line != 0)
		check_mapline(line, fmt, spr);
}

t_fmt	read_info(char *argv, t_spr *spr)
{
	t_fmt	fmt;
	char	*line;
	int		map_nl;
	int		map;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error();
	init_fmt(&fmt);
	map_nl = 0;
	map = 0;
	while (get_next_line(fd, &line))
	{
		check_double(line, fmt);
		check_nl_map(line, &map_nl, &map);
		check_map(line, &fmt, spr, map);
		get_info(line, &fmt);
		free(line);
	}
	free(line);
	close(fd);
	check_fmt(&fmt);
	map_lastrow(fmt);
	return (fmt);
}
