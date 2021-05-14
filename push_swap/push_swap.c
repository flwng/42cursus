#include "push_swap.h"

void	create_list_string(t_list **a, char *argv, int *min)
{
	char	**split;
	int	iter;
	int	str_len;
	int	num;

	iter = 0;
	split = ft_split(argv, ' ');
	str_len = 0;
	if (split[str_len] == 0)
		exit(1);
	while (split[iter])
	{
		str_len = 0;
		while (split[iter][str_len])
		{
			if (!ft_isdigit(split[iter][str_len]))
				exit(1);
			str_len++;
		}
		num = ft_atoi(split[iter++]);
		if (*min > num)
			*min = num;
		ft_lstadd_back(a, ft_lstnew(num));
	}
}

int	order(t_list *a, int min)
{
	while (a->content != min)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

/*void	algo(t_list **a, int min)
{
	t_list	*start;

	
}*/

int main(int argc, char **argv)
{
	t_list	*a;
	int	i;
	int	min;
	int	num;

	if (argc <= 1)
		exit(1);
	min = -2147483648;
	if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			if (!ft_isdigit(*argv[i]))
				exit(1);
			num = ft_atoi(argv[i++]);
			if (min > num)
				min = num;
			ft_lstadd_back(&a, ft_lstnew(num));
		}
	}
	if (argc == 2)
		create_list_string(&a, argv[1], &min);		
}
