/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:58:06 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/04 08:53:00 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ida_star.h"
# include "libft.h"
# include "ps.h"
# include "stack.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	error_exit(void);

int		mark_lis(const int *arr, int n, char *keep);
// parse
void	parse_arguments(int argc, char **argv, t_node **stack_a);
// ft_split_ws.c
char	**ft_split_ws(const char *s);
// node_utils.c
int		list_size(t_node *lst);
t_node	*lstlast(t_node *lst);
t_node	*create_new_node(int value);
void	append_node(t_node **stack, int num);

// free_utils.c
void	free_all(t_node **a, t_node **b);
#endif
