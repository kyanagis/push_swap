/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 02:40:34 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:50:57 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_node **s)
{
	t_node	*cur;
	t_node	*next;

	cur = *s;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*s = NULL;
}

void	free_all(t_node **a, t_node **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
}
