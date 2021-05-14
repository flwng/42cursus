#include "libft/libft.h"

void	rra(t_list **a)
{
	t_list	*start;
	t_list	*last;

	if ((*a)->next)
	{
		start = *a;
		while ((*a)->next->next)
			*a = (*a)->next;
		last = (*a)->next;
		(*a)->next = 0;
		(*a) = last;
		(*a)->next = start;
	}
}

void	rrb(t_list **b)
{
	t_list	*start;
	t_list	*last;

	if ((*b)->next)
	{
		start = *b;
		while ((*b)->next->next)
			*b = (*b)->next;
		last = (*b)->next;
		(*b)->next = 0;
		(*b) = last;
		(*b)->next = start;
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
