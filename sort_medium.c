/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:52:23 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/09 04:52:27 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	allocate_buf(size_t n, int **arr, char **keep)
{
	*arr = malloc(sizeof(int) * n);
	if (!*arr)
		return (1);
	*keep = malloc(sizeof(char) * n);
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

static void	push_non_lis_to_b(t_node **stack_a, t_node **stack_b,
		const char *keep, int n, int lis_len)
{
	int	i;
	int	pb_count;
	int	nz;

	nz = n - lis_len;
	pb_count = 0;
	i = 0;
	while (i < n && pb_count < nz)
	{
		if (keep[i] == 1)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			++pb_count;
		}
		++i;
	}
}

void	rotate_min_to_top(t_node **stack_a)
{
	int	n;
	int	idx;
	int	rot;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	n = list_size(*stack_a);
	if (n <= 1)
		return ;
	idx = index_of_min(*stack_a);
	if (idx == 0)
		return ;
	rot = (idx <= n / 2) ? idx : idx - n;
	while (rot > 0)
	{
		ra(stack_a);
		--rot;
	}
	while (rot < 0)
	{
		rra(stack_a);
		++rot;
	}
}

void	sort_medium(t_node **stack_a, t_node **stack_b)
{
	size_t	n;
	int		*arr;
	char	*keep;
	int		lis_len;

	n = list_size(*stack_a);
	if (allocate_buf(n, &arr, &keep))
		error_exit();
	list_to_array(*stack_a, arr);
	lis_len = mark_lis(arr, (int)n, keep);
	if (lis_len < 0)
	{
		free(arr);
		free(keep);
		error_exit();
	}
	push_non_lis_to_b(stack_a, stack_b, keep, (int)n, lis_len);
	free(arr);
	free(keep);
	push_back_to_a(stack_a, stack_b);
	rotate_min_to_top(stack_a);
}
