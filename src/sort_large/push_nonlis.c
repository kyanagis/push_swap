/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_nonlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:53:44 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:22:02 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_large.h"

static int	has_nonlis_local(t_node *a, const char *keep_val)
{
	while (a)
	{
		if (!keep_val[a->value])
			return (1);
		a = a->next;
	}
	return (0);
}

void	push_nonlis_to_b_fast(t_node **a, t_node **b, const char *keep_val)
{
	int	pivot;

	while (has_nonlis_local(*a, keep_val))
	{
		if (keep_val[(*a)->value])
		{
			move_a_until_nonlis_top(a, keep_val);
			continue ;
		}
		pivot = ((int)list_size_fast(*a) + (int)list_size_fast(*b)) / 2;
		pb(a, b);
		if (*b && (*b)->next && (*b)->value <= pivot)
			rb(b);
	}
}
