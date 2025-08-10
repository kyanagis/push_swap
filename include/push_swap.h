/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:58:06 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 06:08:04 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ps.h"
# include "stack.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	parse_arguments(int argc, char **argv, t_node **stack_a);
char	**ft_split_ws(const char *s);
int		list_size(t_node *lst);
t_node	*lstlast(t_node *lst);
t_node	*create_new_node(int value);
void	append_node(t_node **stack, int num);

void	free_stack(t_node **s);
void	stack_free_all(t_node **a, t_node **b);

void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_large(t_node **stack_a, t_node **stack_b);

#endif
