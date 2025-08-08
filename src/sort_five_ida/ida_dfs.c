/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:07:03 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 18:53:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dfs(t_state *now, int g, int bound, int *path);
static int	explore(t_state *now, int g, int bound, int *path, int op)
{
	t_state	next;
	int		t;

	//  往復・無効手を弾く
	if ((g && inverse_op(op) == path[g - 1]) || (op == OP_PA && !now->len_b)
		|| (op == OP_PB && !now->len_a))
		return (INT_MAX);
	next = *now;
	exec_op(&next, op);
	path[g] = op;
	t = dfs(&next, g + 1, bound, path);
	if (t == FOUND)
		return (FOUND);
	return (t);
}
static int	dfs(t_state *now, int g, int bound, int *path)
{
	int	f;
	int	min;
	int	op;
	int	t;

	f = g + inv_heuristic(now);
	if (f > bound)
		return (f);
	if (is_goal(now))
	{
		path[g] = -1;
		return (FOUND);
	}
	min = INT_MAX;
	op = -1;
	while (++op < OP_CNT)
	{
		t = explore(now, g, bound, path, op);
		if (t == FOUND)
			return (FOUND);
		if (t < min)
			min = t;
	}
	return (min);
}

int	ida_search(t_state *root, int bound, int *path)
{
	return (dfs(root, 0, bound, path));
}