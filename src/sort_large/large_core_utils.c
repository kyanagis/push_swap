/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_core_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:51:51 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:21:50 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_large.h"

void	init_move(t_move *m)
{
	m->pos_a = 0;
	m->pos_b = 0;
	m->rot_a = 0;
	m->rot_b = 0;
	m->cost = INT_MAX;
	m->val = 0;
}

int	abs_i(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

size_t	list_size_fast(t_node *a)
{
	size_t	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

t_node	*last_node(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

int	min_index(t_node *a)
{
	int	i;
	int	idx;
	int	minv;

	i = 0;
	idx = 0;
	minv = INT_MAX;
	while (a)
	{
		if (a->value < minv)
		{
			minv = a->value;
			idx = i;
		}
		a = a->next;
		i++;
	}
	return (idx);
}
