
#include "push_swap.h"

static void	core_swap(t_node **stack)
{
	t_node	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

void	sa(t_node **a)
{
	core_swap(a);
	ft_putendl_fd(MSG_SA, STDOUT_FILENO);
}

void	sb(t_node **b)
{
	core_swap(b);
	ft_putendl_fd(MSG_SB, STDOUT_FILENO);
}

void	ss(t_node **a, t_node **b)
{
	core_swap(a);
	core_swap(b);
	ft_putendl_fd(MSG_SS, STDOUT_FILENO);
}
