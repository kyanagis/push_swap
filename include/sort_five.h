/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 05:36:54 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 06:30:45 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FIVE_H
# define SORT_FIVE_H

# include "push_swap.h"

# define OP_SA 0
# define OP_RA 1
# define OP_RRA 2
# define OP_PB 3
# define OP_PA 4
# define OP_CNT 5
# define FOUND -42

typedef struct s_state
{
	int	a[5];
	int	b[5];
	int	len_a;
	int	len_b;
}		t_state;

typedef struct s_ida_ctx
{
	int	bound;
	int	*path;
}		t_ida_ctx;

int		ida_star(const t_state *start, int *out);
int		inv_heuristic(const t_state *s);
int		is_goal(const t_state *s);
int		ida_search(t_state *root, int bound, int *path);
int		inverse_op(int op);

void	exec_op(t_state *s, int op);
void	op_sa(t_state *s);
void	op_ra(t_state *s);
void	op_rra(t_state *s);
void	op_pb(t_state *s);
void	op_pa(t_state *s);

#endif