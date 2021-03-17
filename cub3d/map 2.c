#include "cub3d.h"
#include "libft/libft.h"

void	read_res(char *line, t_fmt **fmt)
{
	if (*line == 'R')
	{
		line++;
		while (ft_isspace(*line))
			line++;;
		if (ft_isdigit(*line))
			(*fmt)->res_x = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line))
			line++;
		if (ft_isdigit(*line))
			(*fmt)->res_y = ft_atoi(line);
	}
}

void	read_path(char *line, t_fmt **fmt)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		line += 3;
		(*fmt)->north = ft_strdup(line);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		line += 3;
		(*fmt)->south = ft_strdup(line);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		line += 3;
		(*fmt)->east = ft_strdup(line);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		line += 3;
		(*fmt)->west = ft_strdup(line);
	}
	else if (line[0] == 'S')
	{
		line += 2;
		(*fmt)->sprite = ft_strdup(line);
	}
}

/*void	rgb_hex(char *line, t_fmt *fmt)
{
	int	color;

	while (*line)
	{
		while (
}*/

void	get_info(char *line, t_fmt *fmt)
{	
	if (*line == 'R')
		read_res(line, &fmt);
	else if (!(ft_strncmp(line, "NO", 2)) || !(ft_strncmp(line, "SO", 2)) ||
			!(ft_strncmp(line, "WE", 2)) || !(ft_strncmp(line, "EA", 2)) ||
			!(ft_strncmp(line, "S ", 2)))
		read_path(line, &fmt);
	else if (*line == 'F' || *line == 'C')
		;//rgb_hex(line, &fmt);
	else if (ft_isspace(*line) || *line == '1')
		;//read_map();
	else if (*line != '\n' && *line != 0)
	{
		perror("Error\n");
		exit(1);
	}
}

t_fmt	read_info(int fd)
{
	t_fmt	fmt;
	char	*line;

	while (get_next_line(fd, &line))
		get_info(line, &fmt);
	return (fmt);
}
