/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:52:21 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 08:52:54 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MSG_H
# define PS_MSG_H

# define MSG_SA "sa"
# define MSG_SB "sb"
# define MSG_SS "ss"
# define MSG_PA "pa"
# define MSG_PB "pb"
# define MSG_RA "ra"
# define MSG_RB "rb"
# define MSG_RR "rr"
# define MSG_RRA "rra"
# define MSG_RRB "rrb"
# define MSG_RRR "rrr"

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif