/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:52:23 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 01:55:11 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_buf(size_t n, int **arr, char **keep)
{
	*arr = malloc(sizeof(int *) * n);
	if (!*arr)
		return (1);
	*keep = malloc(sizeof(char *) * n);
	if (!*keep)
	{
		free(*arr);
		return (1);
	}
	return (0);
}

void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	size_t n;
	int *arr;
	char *keep;

	n = list_size(*stack_a);
	if (allocate_buf(n, &arr, &keep))
		error_exit();
}