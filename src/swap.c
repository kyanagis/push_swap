
#include "push_swap.h"

static t_node	*lstlast(t_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	sa(t_node **a)
{
	t_node	*first;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = (*a)->next;
	(*a)->next = first;
}

void	sb(t_node **b)
{
	sa(b);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sa(b);
}
