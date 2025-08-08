#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

typedef struct s_move
{
	int			pos_a;
	int			pos_b;
	int			rot_a;
	int			rot_b;
	int			cost;
}				t_move;

static int	abs_i(int x)
{
	return ((x < 0) ? -x : x);
}

static void	rotate_a_by(t_node **a, int rot)
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

static void	rotate_b_by(t_node **b, int rot)
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

static int	index_of_min(t_node *a)
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
		++i;
	}
	return (idx);
}

static void	rotate_min_to_top(t_node **a)
{
	int	n;
	int	idx;
	int	rot;

	if (!a || !*a || !(*a)->next)
		return ;
	n = (int)list_size(*a);
	idx = index_of_min(*a);
	if (idx == 0)
		return ;
	rot = (idx <= n / 2) ? idx : idx - n;
	rotate_a_by(a, rot);
}

static void	list_to_array(t_node *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
}

static int	lis_len_only(const int *arr, int n)
{
	int	*tails;
	int	len;
	int	l;
	int	r;
	int	m;
	int	x;
	int	i;

	tails = (int *)malloc(sizeof(int) * n);
	if (!tails)
		return (-1);
	len = 0;
	i = 0;
	while (i < n)
	{
		x = arr[i];
		l = 0;
		r = len;
		while (l < r)
		{
			m = l + ((r - l) >> 1);
			if (tails[m] < x)
				l = m + 1;
			else
				r = m;
		}
		tails[l] = x;
		if (l == len)
			++len;
		++i;
	}
	free(tails);
	return (len);
}

static int	mark_lis(const int *arr, int n, char *keep)
{
	int	*tails;
	int	*tidx;
	int	*prev;
	int	len;
	int	l;
	int	r;
	int	m;
	int	i;
	int	x;
	int	pos;

	tails = (int *)malloc(sizeof(int) * n);
	if (!tails)
		return (-1);
	tidx = (int *)malloc(sizeof(int) * n);
	if (!tidx)
		return (free(tails), -1);
	prev = (int *)malloc(sizeof(int) * n);
	if (!prev)
		return (free(tails), free(tidx), -1);
	len = 0;
	i = 0;
	while (i < n)
	{
		x = arr[i];
		l = 0;
		r = len;
		while (l < r)
		{
			m = l + ((r - l) >> 1);
			if (tails[m] < x)
				l = m + 1;
			else
				r = m;
		}
		tails[l] = x;
		tidx[l] = i;
		prev[i] = (l > 0) ? tidx[l - 1] : -1;
		if (l == len)
			++len;
		++i;
	}
	i = 0;
	while (i < n)
		keep[i++] = 0;
	pos = tidx[len - 1];
	while (pos != -1)
	{
		keep[pos] = 1;
		pos = prev[pos];
	}
	free(tails);
	free(tidx);
	free(prev);
	return (len);
}

static int	find_min_max_pos(t_node *b, int *minv, int *maxv, int *pos_min,
		int *pos_max)
{
	int	i;
	int	m;
	int	M;
	int	pmin;
	int	pmax;
	int	v;

	if (!b)
		return (0);
	i = 0;
	m = INT_MAX;
	M = INT_MIN;
	pmin = 0;
	pmax = 0;
	while (b)
	{
		v = b->value;
		if (v < m)
		{
			m = v;
			pmin = i;
		}
		if (v > M)
		{
			M = v;
			pmax = i;
		}
		b = b->next;
		++i;
	}
	*minv = m;
	*maxv = M;
	*pos_min = pmin;
	*pos_max = pmax;
	return (1);
}

static int	find_pos_in_b_desc(t_node *b, int val)
{
	int		size;
	int		minv;
	int		maxv;
	int		pos_min;
	int		pos_max;
	int		i;
	int		prev;
	int		cur;
	t_node	*last;
	int		k;

	size = (int)list_size(b);
	if (size <= 1)
		return (0);
	find_min_max_pos(b, &minv, &maxv, &pos_min, &pos_max);
	if (val > maxv || val < minv)
		return (pos_max);
	i = 0;
	prev = 0;
	while (b && i < size)
	{
		if (i == 0)
		{
			last = b;
			k = 0;
			while (k < size - 1)
			{
				last = last->next;
				++k;
			}
			prev = last->value;
		}
		cur = b->value;
		if (prev >= val && val >= cur)
			return (i);
		prev = cur;
		b = b->next;
		++i;
	}
	return (0);
}

static int	signed_rot_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

static void	do_rr_combo(t_node **a, t_node **b, int *ra_cost, int *rb_cost)
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

static void	pick_best_variant(int pa, int pb, int sa, int sb, int posb,
		t_move *best)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	c1;
	int	c2;
	int	c3;
	int	c4;
	int	max1;
	int	max2;
	int	sum;
	int	sum_best;
	int	max_cur;
	int	max_best;

	ra = pa;
	rb = pb;
	rra = sa - pa;
	rrb = sb - pb;
	c1 = ((ra > rb) ? ra : rb) + 1;
	c2 = ((rra > rrb) ? rra : rrb) + 1;
	c3 = ra + rrb + 1;
	c4 = rra + rb + 1;
	if (c1 <= best->cost)
	{
		if (c1 < best->cost)
		{
			best->cost = c1;
			best->rot_a = ra;
			best->rot_b = rb;
			best->pos_b = posb;
		}
		else
		{
			max_cur = (ra > rb) ? ra : rb;
			max_best = (abs_i(best->rot_a) > abs_i(best->rot_b)) ? abs_i(best->rot_a) : abs_i(best->rot_b);
			if (max_cur < max_best || (max_cur == max_best && (ra
						+ rb) < (abs_i(best->rot_a) + abs_i(best->rot_b)))
				|| (max_cur == max_best && (ra + rb) == (abs_i(best->rot_a)
						+ abs_i(best->rot_b)) && posb < best->pos_b))
			{
				best->rot_a = ra;
				best->rot_b = rb;
				best->pos_b = posb;
			}
		}
	}
	if (c2 <= best->cost)
	{
		if (c2 < best->cost)
		{
			best->cost = c2;
			best->rot_a = -rra;
			best->rot_b = -rrb;
			best->pos_b = posb;
		}
		else
		{
			max_cur = (rra > rrb) ? rra : rrb;
			max_best = (abs_i(best->rot_a) > abs_i(best->rot_b)) ? abs_i(best->rot_a) : abs_i(best->rot_b);
			sum = rra + rrb;
			sum_best = abs_i(best->rot_a) + abs_i(best->rot_b);
			if (max_cur < max_best || (max_cur == max_best && sum < sum_best)
				|| (max_cur == max_best && sum == sum_best
					&& posb < best->pos_b))
			{
				best->rot_a = -rra;
				best->rot_b = -rrb;
				best->pos_b = posb;
			}
		}
	}
	if (c3 <= best->cost)
	{
		if (c3 < best->cost)
		{
			best->cost = c3;
			best->rot_a = ra;
			best->rot_b = -rrb;
			best->pos_b = posb;
		}
		else
		{
			max_cur = (ra > rrb) ? ra : rrb;
			max_best = (abs_i(best->rot_a) > abs_i(best->rot_b)) ? abs_i(best->rot_a) : abs_i(best->rot_b);
			sum = ra + rrb;
			sum_best = abs_i(best->rot_a) + abs_i(best->rot_b);
			if (max_cur < max_best || (max_cur == max_best && sum < sum_best)
				|| (max_cur == max_best && sum == sum_best
					&& posb < best->pos_b))
			{
				best->rot_a = ra;
				best->rot_b = -rrb;
				best->pos_b = posb;
			}
		}
	}
	if (c4 <= best->cost)
	{
		if (c4 < best->cost)
		{
			best->cost = c4;
			best->rot_a = -rra;
			best->rot_b = rb;
			best->pos_b = posb;
		}
		else
		{
			max_cur = (rra > rb) ? rra : rb;
			max_best = (abs_i(best->rot_a) > abs_i(best->rot_b)) ? abs_i(best->rot_a) : abs_i(best->rot_b);
			sum = rra + rb;
			sum_best = abs_i(best->rot_a) + abs_i(best->rot_b);
			if (max_cur < max_best || (max_cur == max_best && sum < sum_best)
				|| (max_cur == max_best && sum == sum_best
					&& posb < best->pos_b))
			{
				best->rot_a = -rra;
				best->rot_b = rb;
				best->pos_b = posb;
			}
		}
	}
	max1 = 0;
	max2 = 0;
	(void)max1;
	(void)max2;
}

static t_node	*last_node(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

static int	find_insert_idx_in_a_cached(t_node *a, int val, int size_a,
		int minv, int maxv, int pos_min)
{
	int		i;
	int		prev;
	t_node	*cur;

	if (size_a <= 1)
		return (0);
	if (val < minv || val > maxv)
		return (pos_min);
	prev = last_node(a)->value;
	cur = a;
	i = 0;
	while (i < size_a && cur)
	{
		if (prev < val && val < cur->value)
			return (i);
		prev = cur->value;
		cur = cur->next;
		++i;
	}
	return (pos_min);
}

static void	compute_best_move(t_node *a, t_node *b, t_move *best)
{
	int		size_a;
	int		size_b;
	int		minv_a;
	int		maxv_a;
	int		pos_min_a;
	int		i;
	t_node	*curb;
	int		v;
	int		pos_a;
	int		pa;
	int		pb;
	int		idx;
	t_node	*p;

	size_a = (int)list_size(a);
	size_b = (int)list_size(b);
	minv_a = INT_MAX;
	maxv_a = INT_MIN;
	pos_min_a = 0;
	{
		idx = 0;
		p = a;
		while (p)
		{
			if (p->value < minv_a)
			{
				minv_a = p->value;
				pos_min_a = idx;
			}
			if (p->value > maxv_a)
				maxv_a = p->value;
			p = p->next;
			++idx;
		}
	}
	curb = b;
	i = 0;
	while (i < size_b)
	{
		v = curb->value;
		pos_a = find_insert_idx_in_a_cached(a, v, size_a, minv_a, maxv_a,
				pos_min_a);
		pa = pos_a;
		pb = i;
		pick_best_variant(pa, pb, size_a, size_b, i, best);
		curb = curb->next;
		++i;
	}
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	t_move	best;

	while (*b)
	{
		best.pos_a = 0;
		best.pos_b = 0;
		best.rot_a = 0;
		best.rot_b = 0;
		best.cost = INT_MAX;
		compute_best_move(*a, *b, &best);
		do_rr_combo(a, b, &best.rot_a, &best.rot_b);
		rotate_a_by(a, best.rot_a);
		rotate_b_by(b, best.rot_b);
		pa(a, b);
	}
}

static void	push_non_lis_to_b_smart(t_node **a, t_node **b, const char *keep,
		int n, int lis_len)
{
	int	to_pb;
	int	i;
	int	size_b;
	int	posb;

	to_pb = n - lis_len;
	i = 0;
	while (i < n && to_pb > 0)
	{
		if (keep[i])
			ra(a);
		else
		{
			size_b = (int)list_size(*b);
			if (size_b >= 2)
			{
				posb = find_pos_in_b_desc(*b, (*a)->value);
				rotate_b_by(b, signed_rot_cost(posb, size_b));
			}
			pb(a, b);
			--to_pb;
		}
		++i;
	}
}

static int	find_best_head_k(const int *arr, int n)
{
	int	*tmp;
	int	k;
	int	best_k;
	int	best_len;
	int	len;
	int	i;

	tmp = (int *)malloc(sizeof(int) * n);
	if (!tmp)
		return (0);
	best_k = 0;
	best_len = -1;
	k = 0;
	while (k < n)
	{
		i = 0;
		while (i < n)
		{
			tmp[i] = arr[(i + k) % n];
			++i;
		}
		len = lis_len_only(tmp, n);
		if (len > best_len)
		{
			best_len = len;
			best_k = k;
		}
		++k;
	}
	free(tmp);
	return (best_k);
}

void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	int		n;
	int		*arr;
	char	*keep;
	int		lis_len;
	int		k;
	int		rot;

	n = (int)list_size(*stack_a);
	if (n <= 1)
		return ;
	arr = (int *)malloc(sizeof(int) * n);
	keep = (char *)malloc(sizeof(char) * n);
	if (!arr || !keep)
	{
		if (arr)
			free(arr);
		if (keep)
			free(keep);
		error_exit();
	}
	list_to_array(*stack_a, arr);
	k = find_best_head_k(arr, n);
	if (k > 0 && k <= n / 2)
		rot = k;
	else if (k > 0)
		rot = k - n;
	else
		rot = 0;
	rotate_a_by(stack_a, rot);
	list_to_array(*stack_a, arr);
	lis_len = mark_lis(arr, n, keep);
	if (lis_len < 0)
	{
		free(arr);
		free(keep);
		error_exit();
	}
	push_non_lis_to_b_smart(stack_a, stack_b, keep, n, lis_len);
	free(arr);
	free(keep);
	push_back_to_a(stack_a, stack_b);
	rotate_min_to_top(stack_a);
}
