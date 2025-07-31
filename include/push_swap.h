/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:58:06 by kyanagis          #+#    #+#             */
/*   Updated: 2025/07/31 14:36:40 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	append_node(t_node **stack, int num);
void	error_exit(void);
t_node	*create_new_node(int value);
int		is_valid_number(char *s);

// parse
void	parse_arguments(int argc, char **argv, t_node **stack_a);
// ft_split_ws.c
char	**ft_split_ws(const char *s);
#endif
