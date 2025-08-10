/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 05:47:27 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:24:23 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_five.h"

static void	issue(int op, t_node **a, t_node **b)
{
	if (op == OP_SA)
		sa(a);
	else if (op == OP_RA)
		ra(a);
	else if (op == OP_RRA)
		rra(a);
	else if (op == OP_PB)
		pb(a, b);
	else if (op == OP_PA)
		pa(a, b);
	else
		error_exit();
}

static t_state	make_state(t_node *a)
{
	t_state	s;
	int		i;

	s.len_a = list_size(a);
	s.len_b = 0;
	i = -1;
	while (++i < s.len_a)
	{
		s.a[i] = a->value;
		a = a->next;
	}
	return (s);
}

static void	apply_path(t_node **a, t_node **b, const int *path, int depth)
{
	while (depth--)
		issue(*path++, a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int		path[12];
	int		depth;
	t_state	st;

	ft_memset(path, -1, sizeof(path));
	st = make_state(*a);
	depth = ida_star(&st, path);
	if (depth > 0)
		apply_path(a, b, path, depth);
}
