/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 07:03:43 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:44:19 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_state *s)
{
	int	tmp;

	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
}

void	op_ra(t_state *s)
{
	int	tmp;
	int	i;

	tmp = s->a[0];
	i = -1;
	while (++i < s->len_a - 1)
		s->a[i] = s->a[i + 1];
	s->a[s->len_a - 1] = tmp;
}

void	op_rra(t_state *s)
{
	int	tmp;
	int	i;

	tmp = s->a[s->len_a - 1];
	i = s->len_a;
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[0] = tmp;
}

void	op_pb(t_state *s)
{
	int	i;

	i = s->len_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		--i;
	}
	s->b[0] = s->a[0];
	++s->len_b;
	i = 0;
	while (i < s->len_a - 1)
	{
		s->a[i] = s->a[i + 1];
		++i;
	}
	--s->len_a;
}

void	op_pa(t_state *s)
{
	int	i;

	i = s->len_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[0] = s->b[0];
	++s->len_a;
	i = 0;
	while (i < s->len_b - 1)
	{
		s->b[i] = s->b[i + 1];
		++i;
	}
	--s->len_b;
}
