/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_best_from_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:54:16 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 04:55:03 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_large.h"

void	consider_b_node(const t_ctx *ctx, int idx_b, int vb)
{
	int		pa;
	int		ra_f;
	int		ra_r;
	int		rb_f;
	int		rb_r;
	t_cand	c;

	pa = find_insert_idx_a(ctx->ac, vb);
	ra_f = pa;
	ra_r = pa - ctx->ac->sa;
	rb_f = idx_b;
	rb_r = idx_b - ctx->sb;
	c.pos = idx_b;
	c.val = vb;
	c.ra = ra_f;
	c.rb = rb_f;
	upd_best(ctx->best, c);
	c.ra = ra_r;
	c.rb = rb_r;
	upd_best(ctx->best, c);
	c.ra = ra_f;
	c.rb = rb_r;
	upd_best(ctx->best, c);
	c.ra = ra_r;
	c.rb = rb_f;
	upd_best(ctx->best, c);
}

void	compute_best_move_from_b(t_node *a, t_node *b, t_move *best)
{
	t_ac	ac;
	t_node	*p;
	int		sb;
	int		i;
	t_ctx	ctx;

	fill_ac(a, &ac);
	p = b;
	sb = (int)list_size_fast(b);
	ctx.ac = &ac;
	ctx.sb = sb;
	ctx.best = best;
	i = 0;
	while (i < sb && p)
	{
		consider_b_node(&ctx, i, p->value);
		p = p->next;
		i++;
	}
}
