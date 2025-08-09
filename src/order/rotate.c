/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:50:45 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:52:57 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	core_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = lstlast(*stack);
	last->next = first;
}

void	ra(t_node **a)
{
	core_rotate(a);
	ft_putendl_fd(MSG_RA, STDOUT_FILENO);
}

void	rb(t_node **b)
{
	core_rotate(b);
	ft_putendl_fd(MSG_RB, STDOUT_FILENO);
}

void	rr(t_node **a, t_node **b)
{
	core_rotate(a);
	core_rotate(b);
	ft_putendl_fd(MSG_RR, STDOUT_FILENO);
}
