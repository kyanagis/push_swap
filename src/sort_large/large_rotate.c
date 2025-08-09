/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:18:40 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:18:51 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_large.h"

void	rotate_a_by(t_node **a, int rot)
{
	while (rot > 0)
	{
		ra(a);
		rot--;
	}
	while (rot < 0)
	{
		rra(a);
		rot++;
	}
}

void	rotate_b_by(t_node **b, int rot)
{
	while (rot > 0)
	{
		rb(b);
		rot--;
	}
	while (rot < 0)
	{
		rrb(b);
		rot++;
	}
}

void	do_rr_combo(t_node **a, t_node **b, int *ra_c, int *rb_c)
{
	while (*ra_c > 0 && *rb_c > 0)
	{
		rr(a, b);
		(*ra_c)--;
		(*rb_c)--;
	}
	while (*ra_c < 0 && *rb_c < 0)
	{
		rrr(a, b);
		(*ra_c)++;
		(*rb_c)++;
	}
}

void	rotate_min_to_top(t_node **a)
{
	int	n;
	int	idx;
	int	k;

	if (!a || !*a || !(*a)->next)
		return ;
	n = (int)list_size_fast(*a);
	idx = min_index(*a);
	if (idx <= n / 2)
	{
		k = idx;
		while (k-- > 0)
			ra(a);
	}
	else
	{
		k = n - idx;
		while (k-- > 0)
			rra(a);
	}
}

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}
