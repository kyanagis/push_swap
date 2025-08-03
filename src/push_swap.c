/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:51:04 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 01:36:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (i == 0 || (i == 1 && (s[0] == '+' || s[0] == '-')))
		return (0);
	return (1);
}

int	list_size(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
int	is_sorted(t_node *st)
{
	if (!st || !st->next)
		return (1);
	while (st->next)
	{
		if (st->value > st->next->value)
			return (0);
		st = st->next;
	}
	return (1);
}
void	sort_three(t_node **a)
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

void	sort_manager(t_node **stack_a, t_node **stack_b)
{
	size_t	size;

	(void)stack_b;
	// if (is_sorted(*stack_a))
	// free_all(&stack_a, &stack_b);
	size = list_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	// else if (size <= 5)
	// 	sort_five(stack_a, stack_b);
	// else if (size <= 100)
	// 	sort_medium(stack_a, stack_b);
	// else
	// 	sort_large(stack_a, stack_b);
	// free_all(stack_a, stack_b);
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
	// sort algo　追加予
	sort_manager(&stack_a, &stack_b);
	// free_all(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
