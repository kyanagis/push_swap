#include "push_swap.h"

static void	core_rev_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	core_rev_rotate(a);
	ft_putendl_fd(MSG_RRA, STDOUT_FILENO);
}

void	rrb(t_node **b)
{
	core_rev_rotate(b);
	ft_putendl_fd(MSG_RRB, STDOUT_FILENO);
}

void	rrr(t_node **a, t_node **b)
{
	core_rev_rotate(a);
	core_rev_rotate(b);
	ft_putendl_fd(MSG_RRR, STDOUT_FILENO);
}
