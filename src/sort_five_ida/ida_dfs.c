/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:56:21 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 06:31:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_five.h"

static int			dfs(t_state *now, int g);
static int			explore(t_state *now, int g, int op);

static t_ida_ctx	*ida_ctx(void)
{
	static t_ida_ctx	s;

	return (&s);
}

static int	explore(t_state *now, int g, int op)
{
	t_state	next;
	int		t;

	if ((g && inverse_op(op) == ida_ctx()->path[g - 1]) || (op == OP_PA
			&& !now->len_b) || (op == OP_PB && !now->len_a))
		return (INT_MAX);
	next = *now;
	exec_op(&next, op);
	ida_ctx()->path[g] = op;
	t = dfs(&next, g + 1);
	if (t == FOUND)
		return (FOUND);
	return (t);
}

static int	dfs(t_state *now, int g)
{
	int	f;
	int	min;
	int	op;
	int	t;

	f = g + inv_heuristic(now);
	if (f > ida_ctx()->bound)
		return (f);
	if (is_goal(now))
	{
		ida_ctx()->path[g] = -1;
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
	ida_ctx()->bound = bound;
	ida_ctx()->path = path;
	return (dfs(root, 0));
}
