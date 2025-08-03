#include "push_swap.h"

static void	core_push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_node **a, t_node **b)
{
	core_push(a, b);
	ft_putendl_fd(MSG_PA, STDOUT_FILENO);
}

void	pb(t_node **a, t_node **b)
{
	core_push(b, a);
	ft_putendl_fd(MSG_PB, STDOUT_FILENO);
}
