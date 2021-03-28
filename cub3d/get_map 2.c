#include "cub3d.h"

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
