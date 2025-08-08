/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:01:03 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 18:53:27 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ida_star(const t_state *start, int *out)
// {
// 	t_state	root;
// 	int		bound;
// 	int		res;
// 	int		d;

// 	d = 0;
// 	root = *start;
// 	bound = inv_heuristic(&root);
// 	while (bound <= 12)
// 	{
// 		res = ida_search(&root, bound, out);
// 		if (res == FOUND)
// 			return (bound);
// 		bound = res;
// 	}
// 	return (-1);
// }

int	ida_star(const t_state *start, int *out)
{
	t_state	root;
	int		bound;
	int		next;
	int		d;

	root = *start;
	bound = inv_heuristic(&root);
	while (bound <= 12)
	{
		next = ida_search(&root, bound, out);
		if (next == FOUND)
		{
			d = 0;
			while (d < bound && out[d] != -1)
				++d;
			return (d);
		}
		bound = next;
	}
	return (-1);
}
