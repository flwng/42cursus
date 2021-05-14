#include "libft/libft.h"
#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*start;

	if ((*a)->next != 0)
	{
		start = *a;
		(*a) = (*a)->next;
		start->next = 0;
		ft_lstadd_back(a, start);
	}
}

void	rb(t_list **b)
{
	t_list	*start;

	if ((*b)->next != 0)
	{
		start = *b;
		(*b) = (*b)->next;
		start->next = 0;
		ft_lstadd_back(b, start);
	}
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
