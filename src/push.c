#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	pb(t_node **a, t_node **b)
{
	pa(b, a);
}
