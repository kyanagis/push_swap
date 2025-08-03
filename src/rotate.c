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
	ft_putendl_fd(MSG_RA, STDOUT_FILENO);
}

void	rb(t_node **b)
{
	ra(b);
	ft_putendl_fd(MSG_RB, STDOUT_FILENO);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	ra(b);
	ft_putendl_fd(MSG_RR, STDOUT_FILENO);
}
