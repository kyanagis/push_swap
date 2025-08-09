/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:01:32 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:11:34 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_large.h"
#include <limits.h>

void	fill_ac(t_node *a, t_ac *ac)
{
	int		i;
	t_node	*p;

	ac->a = a;
	ac->sa = (int)list_size_fast(a);
	ac->minv = INT_MAX;
	ac->maxv = INT_MIN;
	ac->posmin = 0;
	i = 0;
	p = a;
	while (p)
	{
		if (p->value < ac->minv)
		{
			ac->minv = p->value;
			ac->posmin = i;
		}
		if (p->value > ac->maxv)
			ac->maxv = p->value;
		p = p->next;
		i++;
	}
}

int	find_insert_idx_a(const t_ac *ac, int v)
{
	int		i;
	int		prev;
	t_node	*cur;

	if (ac->sa <= 1)
		return (0);
	if (v < ac->minv || v > ac->maxv)
		return (ac->posmin);
	prev = last_node(ac->a)->value;
	cur = ac->a;
	i = 0;
	while (i < ac->sa && cur)
	{
		if (prev < v && v < cur->value)
			return (i);
		prev = cur->value;
		cur = cur->next;
		i++;
	}
	return (ac->posmin);
}
