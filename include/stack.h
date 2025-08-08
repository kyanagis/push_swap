/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:52:55 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 03:44:39 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <unistd.h>
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node *head; // 先頭
	t_node *tail; // 末尾
	size_t size;  // 要素数
}					t_stack;

typedef struct s_lisbuf
{
	int				*tails;
	int				*tidx;
	int				*prev;
	int				len;
}					t_lisbuf;

#endif
