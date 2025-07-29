#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = lstlast(*a);
	last->next = first;
}

void	rb(t_node **b)
{
	ra(b);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	ra(b);
}
