/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_compress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 04:04:46 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/10 04:53:03 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_large.h"
#include <stdlib.h>

static void	swap_i(int *x, int *y)
{
	int	t;

	t = *x;
	*x = *y;
	*y = t;
}

static void	qsort_rec(int *a, int l, int r)
{
	int	i;
	int	j;
	int	p;

	i = l;
	j = r;
	p = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] < p)
			i++;
		while (a[j] > p)
			j--;
		if (i <= j)
		{
			swap_i(&a[i], &a[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		qsort_rec(a, l, j);
	if (i < r)
		qsort_rec(a, i, r);
}

static int	lb_val(const int *arr, int n, int x)
{
	int	l;
	int	r;
	int	m;

	l = 0;
	r = n;
	while (l < r)
	{
		m = l + ((r - l) >> 1);
		if (arr[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return (l);
}

void	compress_in_place(t_node *a, int n)
{
	int		*sorted;
	int		i;
	t_node	*p;

	sorted = (int *)malloc(sizeof(int) * n);
	if (!sorted)
		error_exit();
	p = a;
	i = 0;
	while (p)
	{
		sorted[i] = p->value;
		p = p->next;
		i++;
	}
	qsort_rec(sorted, 0, n - 1);
	p = a;
	while (p)
	{
		p->value = lb_val(sorted, n, p->value);
		p = p->next;
	}
	free(sorted);
}
