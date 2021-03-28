#include "cub3d.h"

int	len(int nb, char *base)
{
	int	lenght;

	lenght = 0;
	if (nb == 0)
		lenght++;
	while (nb > 0)
	{
		nb = nb / ft_strlen(base);
		lenght++;
	}
	return (lenght);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*str;
	size_t	nb;
	int		i;

	nb = n;
	i = len(n, base);
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[i--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	return (str);
}
