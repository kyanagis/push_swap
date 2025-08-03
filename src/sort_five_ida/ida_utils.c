/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ida_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:08:24 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 08:07:51 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	inv_heuristic(const t_state *s)
// {
// 	int	i;
// 	int	j;
// 	int	inv;

// 	inv = 0;
// 	i = -1;
// 	while (++i < s->len_a)
// 	{
// 		j = i;
// 		while (++j < s->len_a)
// 			if (s->a[i] > s->a[j])
// 				++inv;
// 	}
// 	return (inv / 2);
// }

#define MAX_SIZE 200

int	lis_heuristic(const t_state *s)
{
	char	keep[MAX_SIZE];
	int		lis_len;

	if (s->len_a <= 1)
		return (0);
	lis_len = mark_lis(s->a, s->len_a, keep);
	// malloc失敗時のエラーハンドリング
	if (lis_len < 0)
		error_exit(); // 既存のエラー処理関数を想定
	// ヒューリスティック値を計算して返す
	return (s->len_a - lis_len);
}
int	is_goal(const t_state *s)
{
	int	i;

	if (s->len_b)
		return (0);
	i = -1;
	while (++i < s->len_a - 1)
		if (s->a[i] > s->a[i + 1])
			return (0);
	return (1);
}

void	exec_op(t_state *s, int op)
{
	if (op == OP_SA)
		op_sa(s);
	else if (op == OP_RA)
		op_ra(s);
	else if (op == OP_RRA)
		op_rra(s);
	else if (op == OP_PB)
		op_pb(s);
	else
		op_pa(s);
}

int	inverse_op(int op)
{
	if (op == OP_RA)
		return (OP_RRA);
	if (op == OP_RRA)
		return (OP_RA);
	if (op == OP_PB)
		return (OP_PA);
	if (op == OP_PA)
		return (OP_PB);
	return (OP_SA);
}
