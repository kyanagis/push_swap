/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:56:21 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 06:06:08 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dfs(t_state *now, int g, int bound, int *path);

static int	explore(t_state *now, int g, int op)
{
	t_state	next;
	int		t;

	if ((g && inverse_op(op) == g_ctx.path[g - 1]) || (op == OP_PA
			&& !now->len_b) || (op == OP_PB && !now->len_a))
		return (INT_MAX);
	next = *now;
	exec_op(&next, op);
	g_ctx.path[g] = op;
	t = dfs(&next, g + 1, g_ctx.bound, g_ctx.path);
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
		t = explore(now, g, op);
		if (t == FOUND)
			return (FOUND);
		if (t < min)
			min = t;
	}
	return (min);
}

int	ida_search(t_state *root, int bound, int *path)
{
	g_ctx.bound = bound;
	g_ctx.path = path;
	return (dfs(root, 0, bound, path));
}
