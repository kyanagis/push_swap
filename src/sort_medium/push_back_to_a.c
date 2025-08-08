/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:31:13 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 03:38:39 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_move
{
	int		pos_a;
	int		pos_b;
	int		rot_a;
	int		rot_b;
	int		cost;
}			t_move;

static void	init_move(t_move *m)
{
	m->pos_a = 0;
	m->pos_b = 0;
	m->rot_a = 0;
	m->rot_b = 0;
	m->cost = INT_MAX;
}
static void	compute_best_move(t_node *a, t_node *b, t_move *best);
static void	do_combined_rot(t_node **a, t_node **b, int *ra_cost, int *rb_cost);
static void	rotate_a_to(t_node **a, int rot);
static void	rotate_b_to(t_node **b, int rot);

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	t_move best;

	while (*stack_b)
	{
		init_move(&best);
	}
}