/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:50:42 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:50:43 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	core_push(t_node **dest, t_node **src)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_node **a, t_node **b)
{
	core_push(a, b);
	ft_putendl_fd(MSG_PA, STDOUT_FILENO);
}

void	pb(t_node **a, t_node **b)
{
	core_push(b, a);
	ft_putendl_fd(MSG_PB, STDOUT_FILENO);
}
