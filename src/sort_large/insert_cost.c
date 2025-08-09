

#include "push_swap_large.h"

static void	assign_best(t_move *b, t_cand c, int cost)
{
	b->rot_a = c.ra;
	b->rot_b = c.rb;
	b->pos_a = c.pos;
	b->val = c.val;
	b->cost = cost;
}

int	move_cost(int ra, int rb)
{
	int	cn;
	int	an;

	cn = abs_i(ra);
	an = abs_i(rb);
	if ((ra >= 0 && rb >= 0) || (ra < 0 && rb < 0))
		return ((cn > an ? cn : an) + 1);
	return (cn + an + 1);
}

int	move_max(int ra, int rb)
{
	int	cn;
	int	an;

	cn = abs_i(ra);
	an = abs_i(rb);
	return (cn > an ? cn : an);
}

void	upd_best(t_move *b, t_cand c)
{
	int cost;
	int diff;
	int sumd;

	cost = move_cost(c.ra, c.rb);
	if (cost < b->cost)
		return (assign_best(b, c, cost));
	if (cost > b->cost)
		return ;
	diff = move_max(c.ra, c.rb) - move_max(b->rot_a, b->rot_b);
	if (diff < 0)
		return (assign_best(b, c, cost));
	if (diff > 0)
		return ;
	sumd = (abs_i(c.ra) + abs_i(c.rb)) - (abs_i(b->rot_a) + abs_i(b->rot_b));
	if (sumd < 0 || (sumd == 0 && c.pos < b->pos_a))
		assign_best(b, c, cost);
}