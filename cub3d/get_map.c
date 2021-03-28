#include "cub3d.h"

void	map_firstrow(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !(ft_isspace(line[i])))
			print_error();
		i++;
	}
}

void	check_mapline(char *line, t_fmt *fmt)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i++] != '1' || line[ft_strlen(line) - 1] != '1') 
		print_error();
	while (line[++i])
	{
		if (line[i] == 'W' || line[i] == 'E' || line[i] == 'N' || line[i] == 'S')
		{
			if (fmt->px != -1)
				print_error();
			fmt->px = i;
			fmt->py = fmt->map_size;
			fmt->pdir = line[i];
		}
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
			line[i] != 'W' && !(ft_isspace(line[i])))
			print_error();
	}
}

char	**read_map(char *line, t_fmt **fmt)
{
	char	**map;
	int	i;

	map = (char **)malloc(sizeof(char *) * (*fmt)->map_size + 1);
	i = 0;
	while (i < (*fmt)->map_size)
	{
		map[i] = (*fmt)->map[i];
		i++;
	}
	map[i] = ft_strdup(line);
	free((*fmt)->map);
	(*fmt)->map_size += 1;
	return (map);
}
