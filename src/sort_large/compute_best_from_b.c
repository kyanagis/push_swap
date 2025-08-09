/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_best_from_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:24:24 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 05:24:29 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_large.h"

void	consider_b_node(const t_ctx *ctx, int idx_b, int vb)
{
	int		pa;
	t_cand	c;

	pa = find_insert_idx_a(ctx->ac, vb);
	c.pos = idx_b;
	c.val = vb;
	c.ra = pa;
	c.rb = idx_b;
	upd_best(ctx->best, c);
	c.ra = pa - ctx->ac->sa;
	c.rb = idx_b - ctx->sb;
	upd_best(ctx->best, c);
	c.ra = pa;
	c.rb = idx_b - ctx->sb;
	upd_best(ctx->best, c);
	c.ra = pa - ctx->ac->sa;
	c.rb = idx_b;
	upd_best(ctx->best, c);
}

static void	iterate_nodes(const t_ctx *ctx, t_node *b)
{
	int		i;
	t_node	*p;

	i = 0;
	p = b;
	while (i < ctx->sb && p)
	{
		consider_b_node(ctx, i, p->value);
		p = p->next;
		i++;
	}
}

void	compute_best_move_from_b(t_node *a, t_node *b, t_move *best)
{
	int		sb;
	t_ac	ac;
	t_ctx	ctx;

	sb = (int)list_size_fast(b);
	fill_ac(a, &ac);
	ctx.ac = &ac;
	ctx.sb = sb;
	ctx.best = best;
	iterate_nodes(&ctx, b);
}
