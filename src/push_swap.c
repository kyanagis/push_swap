/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:51:04 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 04:53:44 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_sorted(const t_node *stack)
{
	const t_node	*cur = stack;

	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	sort_three(t_node **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;
	if (f < s && s < t)
		return ;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else
		rra(a);
}

static void	sort_manager(t_node **stack_a, t_node **stack_b)
{
	size_t	size;

	if (is_sorted(*stack_a))
		return ;
	size = list_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 6)
		sort_five(stack_a, stack_b);
	else if (size <= 100)
		sort_medium(stack_a, stack_b);
	// else
	// 	sort_large(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	parse_arguments(argc, argv, &stack_a);
	sort_manager(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
