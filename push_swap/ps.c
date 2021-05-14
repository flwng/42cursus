#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp_next;
	
	if ((*a)->next)
	{
		tmp_next = (*a)->next->next;	
		ft_lstadd_front(a, (*a)->next);
		(*a)->next->next = tmp_next;
	}
}

void	sb(t_list **b)
{
	t_list	*tmp_next;

	if ((*b)->next)
	{
		tmp_next = (*b)->next->next;	
		ft_lstadd_front(b, (*b)->next);
		(*b)->next->next = tmp_next;
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_lstadd_front(a, ft_lstnew((*b)->content));
	tmp = *a;	
	*a = (*a)->next;
	free(tmp);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_lstadd_front(b, ft_lstnew((*a)->content));
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
}
