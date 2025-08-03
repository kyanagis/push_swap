/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 07:03:43 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 07:03:47 by kyanagis         ###   ########.fr       */
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

// void	op_pb(t_state *s)
// {
// 	int	i;

// 	s->b[s->len_b++] = s->a[0];
// 	i = -1;
// 	while (++i < s->len_a - 1)
// 		s->a[i] = s->a[i + 1];
// 	--s->len_a;
// }

// void	op_pa(t_state *s)
// {
// 	int	i;

// 	i = s->len_a + 1;
// 	while (--i > 0)
// 		s->a[i] = s->a[i - 1];
// 	s->a[0] = s->b[--s->len_b];
// 	++s->len_a;
// }

void	op_pb(t_state *s) // A → B (トップは添字 0)
{
	int i = s->len_b; // 現在の B の末尾
	while (i > 0)     // 右シフトで空きを作る
	{
		s->b[i] = s->b[i - 1];
		--i;
	}
	s->b[0] = s->a[0]; // A のトップを B[0] へ
	++s->len_b;
	i = 0;
	while (i < s->len_a - 1) // A を左シフト
	{
		s->a[i] = s->a[i + 1];
		++i;
	}
	--s->len_a;
}
void	op_pa(t_state *s) // B → A
{
	int i = s->len_a; // A を右シフトして空きを作る
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[0] = s->b[0]; // B のトップを A[0] へ
	++s->len_a;

	i = 0;
	while (i < s->len_b - 1) // B を左シフト
	{
		s->b[i] = s->b[i + 1];
		++i;
	}
	--s->len_b;
}