/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_seed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:05:16 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:30:33 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_large.h"

void	build_arr_from_a(t_node *a, int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n && a)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
}

void	make_keep_by_value(const int *arr, const char *keep_idx, char *keep_val,
		int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		keep_val[i] = 0;
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (keep_idx[i])
			keep_val[arr[i]] = 1;
		i++;
	}
}

static int	steps_to_next_nonlis_forward(t_node *a, const char *keep_val)
{
	int		steps;
	t_node	*p;

	steps = 0;
	p = a;
	while (p && keep_val[p->value])
	{
		steps++;
		p = p->next;
	}
	return (steps);
}

static int	last_nonlis_index(t_node *a, const char *keep_val)
{
	int		idx;
	int		last;
	t_node	*p;

	idx = 0;
	last = -1;
	p = a;
	while (p)
	{
		if (!keep_val[p->value])
			last = idx;
		p = p->next;
		idx++;
	}
	return (last);
}

void	move_a_until_nonlis_top(t_node **a, const char *keep_val)
{
	int	df;
	int	last;
	int	sz;
	int	db;

	if (!*a)
		return ;
	if (!keep_val[(*a)->value])
		return ;
	df = steps_to_next_nonlis_forward(*a, keep_val);
	last = last_nonlis_index(*a, keep_val);
	sz = (int)list_size_fast(*a);
	if (last < 0)
		return ;
	db = sz - last;
	if (df <= db)
	{
		while (df-- > 0)
			ra(a);
	}
	else
	{
		while (db-- > 0)
			rra(a);
	}
}
