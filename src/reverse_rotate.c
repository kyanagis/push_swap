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
	ft_putendl_fd(MSG_RRA, STDOUT_FILENO);
}

void	rrb(t_node **b)
{
	rra(b);
	ft_putendl_fd(MSG_RRB, STDOUT_FILENO);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rra(b);
	ft_putendl_fd(MSG_RRR, STDOUT_FILENO);
}
