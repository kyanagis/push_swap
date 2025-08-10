/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 00:57:18 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:36:02 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_LARGE_H
# define SORT_LARGE_H

# include "push_swap.h"

typedef struct s_move
{
	int			pos_a;
	int			pos_b;
	int			rot_a;
	int			rot_b;
	int			cost;
	int			val;
}				t_move;

typedef struct s_ac
{
	t_node		*a;
	int			sa;
	int			minv;
	int			maxv;
	int			posmin;
}				t_ac;

typedef struct s_cand
{
	int			ra;
	int			rb;
	int			pos;
	int			val;
}				t_cand;

typedef struct s_ctx
{
	const t_ac	*ac;
	int			sb;
	t_move		*best;
}				t_ctx;

void			compute_best_move_from_b(t_node *a, t_node *b, t_move *best);
// coord
void			compress_in_place(t_node *a, int n);
// insert_cost.c
void			upd_best(t_move *b, t_cand c);
// insert_utils.c
void			fill_ac(t_node *a, t_ac *ac);
int				find_insert_idx_a(const t_ac *ac, int v);
// large_core_utils.c
void			init_move(t_move *m);
int				min_index(t_node *a);
int				abs_i(int x);
size_t			list_size_fast(t_node *a);
t_node			*last_node(t_node *a);
// large_rotate.c
void			rotate_a_by(t_node **a, int rot);
void			rotate_b_by(t_node **b, int rot);
void			do_rr_combo(t_node **a, t_node **b, int *ra_c, int *rb_c);
void			rotate_min_to_top(t_node **a);

// lis_seed.c
void			build_arr_from_a(t_node *a, int *arr, int n);
void			make_keep_by_value(const int *arr, const char *keep_idx,
					char *keep_val, int n);

void			move_a_until_nonlis_top(t_node **a, const char *keep_val);

// push_nonlis.c
void			push_nonlis_to_b_fast(t_node **a, t_node **b,
					const char *keep_val);

void			zero_keep(char *keep, int n);
int				mark_lis(const int *arr, int n, char *keep);

#endif