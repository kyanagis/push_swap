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
	ft_putendl_fd(MSG_PA, STDOUT_FILENO);
}

void	pb(t_node **a, t_node **b)
{
	pa(b, a);
	ft_putendl_fd(MSG_PB, STDOUT_FILENO);
}
