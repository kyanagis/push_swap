/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:52:23 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 02:03:22 by kyanagis         ###   ########.fr       */
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

static void	list_to_array(t_node *a, int *arr)
{
	size_t	i;

	i = 0;
	while (a)
	{
		arr[i] = a->value;
		a = a->next;
		++i;
	}
}
void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	size_t	n;
	int		*arr;
	char	*keep;

	n = list_size(*stack_a);
	if (allocate_buf(n, &arr, &keep))
		error_exit();
	list_to_array(*stack_a, arr);
	if (mark_lis(arr, (int)n, keep) < 0)
	{
		free(arr);
		free(keep);
		error_exit();
	}
	push_non_lis_to_b(stack_a, stack_b, keep, (int)n);
	free(arr);
	free(keep);
	push_back_to_a(a, b);
	rotate_min_to_top(a);
}
