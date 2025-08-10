/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:51:14 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 01:36:23 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_large.h"

static int	binary_search(int *arr, int len, int key)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = len;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid;
	}
	return (low);
}

static void	reconstruct_lis(int len, int *tidx, int *prev, char *keep)
{
	int	k;

	k = tidx[len - 1];
	while (k != -1)
	{
		keep[k] = 1;
		k = prev[k];
	}
}

static int	alloc_bufs(int n, t_lisbuf *b)
{
	b->tails = (int *)malloc(sizeof(int) * n);
	if (!b->tails)
		return (1);
	b->tidx = (int *)malloc(sizeof(int) * n);
	if (!b->tidx)
	{
		free(b->tails);
		return (1);
	}
	b->prev = (int *)malloc(sizeof(int) * n);
	if (!b->prev)
	{
		free(b->tails);
		free(b->tidx);
		return (1);
	}
	b->len = 0;
	return (0);
}

static void	build_lis(const int *arr, int n, t_lisbuf *b)
{
	int	i;
	int	pos;

	i = 0;
	while (i < n)
	{
		pos = binary_search(b->tails, b->len, arr[i]);
		b->tails[pos] = arr[i];
		b->tidx[pos] = i;
		if (pos > 0)
			b->prev[i] = b->tidx[pos - 1];
		else
			b->prev[i] = -1;
		if (pos == b->len)
		{
			++(b->len);
		}
		++i;
	}
}

int	mark_lis(const int *arr, int n, char *keep)
{
	t_lisbuf	b;

	if (n <= 0)
		return (0);
	if (alloc_bufs(n, &b))
		return (-1);
	build_lis(arr, n, &b);
	zero_keep(keep, n);
	reconstruct_lis(b.len, b.tidx, b.prev, keep);
	free(b.tails);
	free(b.tidx);
	free(b.prev);
	return (b.len);
}
