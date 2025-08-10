/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:51:30 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 06:28:32 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_large.h"

static void	free_error_exit(int *arr, char *idx, char **keep_val)
{
	if (arr)
		free(arr);
	if (idx)
		free(idx);
	if (*keep_val)
		free(*keep_val);
	error_exit();
}

static void	build_keep_mask(t_node *a, char **keep_val, int *lis_len)
{
	int		n;
	int		*arr;
	char	*idx;

	n = (int)list_size_fast(a);
	arr = (int *)malloc(sizeof(int) * n);
	idx = (char *)malloc(sizeof(char) * n);
	*keep_val = (char *)malloc(sizeof(char) * n);
	if (!arr || !idx || !*keep_val)
		free_error_exit(arr, idx, keep_val);
	build_arr_from_a(a, arr, n);
	*lis_len = mark_lis(arr, n, idx);
	if (*lis_len < 0)
		free_error_exit(arr, idx, keep_val);
	make_keep_by_value(arr, idx, *keep_val, n);
	free(arr);
	free(idx);
}

void	sort_large(t_node **a, t_node **b)
{
	int		n;
	int		lis_len;
	char	*keep;
	t_move	mv;

	n = (int)list_size_fast(*a);
	if (n <= 1)
		return ;
	compress_in_place(*a, n);
	build_keep_mask(*a, &keep, &lis_len);
	push_nonlis_to_b_fast(a, b, keep);
	free(keep);
	if ((int)list_size_fast(*a) <= 3)
		sort_three(a);
	while (*b)
	{
		init_move(&mv);
		compute_best_move_from_b(*a, *b, &mv);
		do_rr_combo(a, b, &mv.rot_a, &mv.rot_b);
		rotate_a_by(a, mv.rot_a);
		rotate_b_by(b, mv.rot_b);
		pa(a, b);
	}
	rotate_min_to_top(a);
}
