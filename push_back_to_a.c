
#include "push_swap.h"
#include <limits.h>

typedef struct s_move
{
	int			pos_a;
	int			pos_b;
	int			rot_a;
	int			rot_b;
	int			cost;
}				t_move;

static void		init_move(t_move *m);
static int		iabs_int(int x);
int				index_of_min(t_node *a);
static t_node	*last_node(t_node *a);
static int		find_insert_idx_in_a(t_node *a, int val);
static int		signed_rot_cost(int pos, int size);
static int		move_cost(int ra, int rb);
static int		is_better(int cost, int ra, int rb, int posb,
					const t_move *best);
static void		compute_best_move(t_node *a, t_node *b, t_move *best);
static void		do_combined_rot(t_node **a, t_node **b, int *ra_cost,
					int *rb_cost);
static void		rotate_a_to(t_node **a, int rot);
static void		rotate_b_to(t_node **b, int rot);

static void	init_move(t_move *m)
{
	m->pos_a = 0;
	m->pos_b = 0;
	m->rot_a = 0;
	m->rot_b = 0;
	m->cost = INT_MAX;
}

static int	iabs_int(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	index_of_min(t_node *a)
{
	int	i;
	int	min_idx;
	int	min_val;

	if (!a)
		return (0);
	i = 0;
	min_idx = 0;
	min_val = INT_MAX;
	while (a)
	{
		if (a->value < min_val)
		{
			min_val = a->value;
			min_idx = i;
		}
		a = a->next;
		++i;
	}
	return (min_idx);
}

static t_node	*last_node(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

static int	find_insert_idx_in_a(t_node *a, int val)
{
	int		i;
	int		size;
	int		prev_val;
	t_node	*cur;

	if (!a || !a->next)
		return (0);
	size = list_size(a);
	prev_val = last_node(a)->value;
	cur = a;
	i = 0;
	while (i < size && cur)
	{
		if (prev_val < val && val < cur->value)
			return (i);
		prev_val = cur->value;
		cur = cur->next;
		++i;
	}
	return (index_of_min(a));
}

static int	signed_rot_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

static int	move_cost(int ra, int rb)
{
	int	overlap;

	overlap = 0;
	if ((ra > 0 && rb > 0) || (ra < 0 && rb < 0))
		overlap = (iabs_int(ra) < iabs_int(rb)) ? iabs_int(ra) : iabs_int(rb);
	return (iabs_int(ra) + iabs_int(rb) - overlap + 1);
}

static int	is_better(int cost, int ra, int rb, int posb, const t_move *best)
{
	int	cur_sum;
	int	best_sum;

	if (cost < best->cost)
		return (1);
	if (cost > best->cost)
		return (0);
	cur_sum = iabs_int(ra) + iabs_int(rb);
	best_sum = iabs_int(best->rot_a) + iabs_int(best->rot_b);
	if (cur_sum < best_sum)
		return (1);
	if (cur_sum > best_sum)
		return (0);
	if (iabs_int(ra) < iabs_int(best->rot_a))
		return (1);
	if (iabs_int(ra) > iabs_int(best->rot_a))
		return (0);
	return (posb < best->pos_b);
}

static void	compute_best_move(t_node *a, t_node *b, t_move *best)
{
	int		size_a;
	int		size_b;
	int		i;
	int		pos_a;
	int		ra_cost;
	int		rb_cost;
	int		cost;
	t_node	*node;

	size_a = list_size(a);
	size_b = list_size(b);
	node = b;
	i = 0;
	while (i < size_b)
	{
		pos_a = find_insert_idx_in_a(a, node->value);
		ra_cost = signed_rot_cost(pos_a, size_a);
		rb_cost = signed_rot_cost(i, size_b);
		cost = move_cost(ra_cost, rb_cost);
		if (is_better(cost, ra_cost, rb_cost, i, best))
		{
			best->pos_a = pos_a;
			best->pos_b = i;
			best->rot_a = ra_cost;
			best->rot_b = rb_cost;
			best->cost = cost;
		}
		node = node->next;
		++i;
	}
}

static void	do_combined_rot(t_node **a, t_node **b, int *ra_cost, int *rb_cost)
{
	while (*ra_cost > 0 && *rb_cost > 0)
	{
		rr(a, b);
		--(*ra_cost);
		--(*rb_cost);
	}
	while (*ra_cost < 0 && *rb_cost < 0)
	{
		rrr(a, b);
		++(*ra_cost);
		++(*rb_cost);
	}
}

static void	rotate_a_to(t_node **a, int rot)
{
	while (rot > 0)
	{
		ra(a);
		--rot;
	}
	while (rot < 0)
	{
		rra(a);
		++rot;
	}
}

static void	rotate_b_to(t_node **b, int rot)
{
	while (rot > 0)
	{
		rb(b);
		--rot;
	}
	while (rot < 0)
	{
		rrb(b);
		++rot;
	}
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	t_move	best;

	while (*stack_b)
	{
		init_move(&best);
		compute_best_move(*stack_a, *stack_b, &best);
		do_combined_rot(stack_a, stack_b, &best.rot_a, &best.rot_b);
		rotate_a_to(stack_a, best.rot_a);
		rotate_b_to(stack_b, best.rot_b);
		pa(stack_a, stack_b);
	}
}
