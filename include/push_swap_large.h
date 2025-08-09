#ifndef PUSH_SWAP_LARGE_H
# define PUSH_SWAP_LARGE_H

# include "push_swap.h"
# include <stddef.h>

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

int				abs_i(int x);
size_t			list_size_fast(t_node *a);
void			init_move(t_move *m);

t_node			*last_node(t_node *a);

void			rotate_a_by(t_node **a, int rot);
void			rotate_b_by(t_node **b, int rot);
void			do_rr_combo(t_node **a, t_node **b, int *ra_c, int *rb_c);
void			rotate_min_to_top(t_node **a);
void			sort_three(t_node **a);
int				min_index(t_node *a);
void			compress_in_place(t_node *a, int n);

void			build_arr_from_a(t_node *a, int *arr, int n);
void			make_keep_by_value(const int *arr, const char *keep_idx,
					char *keep_val, int n);
int				steps_to_next_nonlis_forward(t_node *a, const char *keep_val);
int				last_nonlis_index(t_node *a, const char *keep_val);
void			move_a_until_nonlis_top(t_node **a, const char *keep_val);

void			push_nonlis_to_b_fast(t_node **a, t_node **b,
					const char *keep_val);

int				move_cost(int ra, int rb);
int				move_max(int ra, int rb);
void			upd_best(t_move *b, t_cand c);
void			fill_ac(t_node *a, t_ac *ac);
int				find_insert_idx_a(const t_ac *ac, int v);
void			consider_b_node(const t_ctx *ctx, int idx_b, int vb);
void			compute_best_move_from_b(t_node *a, t_node *b, t_move *best);

void			sort_large(t_node **a, t_node **b);

int				mark_lis(const int *arr, int n, char *keep);

#endif