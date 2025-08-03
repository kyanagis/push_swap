
#include "push_swap.h"

t_node	*lstlast(t_node *lst)
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
	ft_putendl_fd(MSG_SA, STDOUT_FILENO);
}

void	sb(t_node **b)
{
	sa(b);
	ft_putendl_fd(MSG_SB, STDOUT_FILENO);
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sa(b);
	ft_putendl_fd(MSG_SS, STDOUT_FILENO);
}
