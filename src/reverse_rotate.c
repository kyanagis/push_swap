#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rra(b);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rra(b);
	write(STDOUT_FILENO, "rrr\n", 4);
}
