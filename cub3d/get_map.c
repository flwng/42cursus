#include "cub3d.h"

void	map_firstrow(char *line, t_fmt fmt)
{
	int	i;

	i = 0;
	if (fmt.map_size == 0)
	{
		while (line[i])
		{
			if (line[i] != '1' && !(ft_isspace(line[i])))
				print_error();
			i++;
		}
	}
	else
	{
		while (line[i])
		{
			if (line[i] == '0' && fmt.map[0][i] != '1')
				print_error();
			i++;
		}
	}
}

void	get_pos_camera_dir(t_fmt **fmt, char c, int i)
{
	if ((*fmt)->px != -1)
		print_error();
	(*fmt)->px = (double)i;
	(*fmt)->py = (double)(*fmt)->map_size;
	if (c == 'N')
	{
		(*fmt)->pa = 3 * PI / 2;
		(*fmt)->dir_y = -1;
	}
	else if (c == 'S')
	{
		(*fmt)->dir_y = 1;
		(*fmt)->pa = PI / 2;
	}
	else if (c == 'W')
	{
		(*fmt)->pa = PI;
		(*fmt)->dir_x = -1;
	}
	else if (c == 'E')
	{
		(*fmt)->dir_x = 1;
		(*fmt)->pa = 0;
	}
}

void	check_before_line(t_fmt *fmt, char *line, int i, int check)
{
	if (check == 0)
	{
		if ((i > 0 && line[i] == ' ') && ((line[i - 1] != ' '
					&& line[i - 1] != '1')
				|| (line[i + 1] == ' ' && line[i + 1] != '1')
				|| (fmt->map[fmt->map_size - 1][i] != '1'
				&& fmt->map[fmt->map_size - 1][i] != ' ')))
			print_error();
	}
	else
		while (ft_strlen(line) < ft_strlen(fmt->map[fmt->map_size - 1])
			&& fmt->map[fmt->map_size - 1][i])
			if (fmt->map[fmt->map_size - 1][i++] != '1')
				print_error();
}

void	check_mapline(char *line, t_fmt *fmt, t_spr *spr)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i++] != '1' || line[ft_strlen(line) - 1] != '1')
		print_error();
	while (line[++i])
	{
		if (line[i] == '0' && fmt->map[fmt->map_size - 1][i] == ' ')
			print_error();
		if (line[i] == '2')
			ft_sprite(fmt, i, spr);
		if (line[i] == 'W' || line[i] == 'E' || line[i] == 'N'
			|| line[i] == 'S')
			get_pos_camera_dir(&fmt, line[i], i);
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && \
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && \
			line[i] != 'W' && !(ft_isspace(line[i])))
			print_error();
		if (i > ft_strlen(fmt->map[fmt->map_size - 1]) - 1 && line[i] != '1')
			print_error();
		check_before_line(fmt, line, i, 0);
	}
	check_before_line(fmt, line, i, 1);
}

char	**read_map(char *line, t_fmt **fmt)
{
	char	**map;
	int		i;
	int		len;

	map = (char **)malloc(sizeof(char *) * (*fmt)->map_size + 2);
	i = 0;
	while (i < (*fmt)->map_size)
	{
		map[i] = (*fmt)->map[i];
		i++;
	}
	map[i] = ft_strdup(line);
	len = 0;
	while (map[i][len])
		len++;
	if ((*fmt)->mapb < len)
		(*fmt)->mapb = len;
	(*fmt)->map_size += 1;
	free((*fmt)->map);
	return (map);
}
