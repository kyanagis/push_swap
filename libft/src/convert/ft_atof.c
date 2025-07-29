/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:30:55 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/13 19:31:50 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_space_sign(const char *s, int *idx)
{
	int	sign;

	sign = 1;
	while (s[*idx] == ' ' || (s[*idx] >= 9 && s[*idx] <= 13))
		++(*idx);
	if (s[*idx] == '-' || s[*idx] == '+')
	{
		if (s[*idx] == '-')
			sign = -1;
		++(*idx);
	}
	return (sign);
}

static double	parse_int(const char *s, int *idx)
{
	double	val;

	val = 0.0;
	while (s[*idx] >= '0' && s[*idx] <= '9')
	{
		val = val * 10.0 + (s[*idx] - '0');
		++(*idx);
	}
	return (val);
}

static double	parse_frac(const char *s, int *idx)
{
	double	val;
	double	div;

	val = 0.0;
	div = 1.0;
	if (s[*idx] == '.')
	{
		++(*idx);
		while (s[*idx] >= '0' && s[*idx] <= '9')
		{
			val = val * 10.0 + (s[*idx] - '0');
			div *= 10.0;
			++(*idx);
		}
	}
	return (val / div);
}

double	ft_atof(const char *s)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = skip_space_sign(s, &i);
	res = parse_int(s, &i);
	res += parse_frac(s, &i);
	return (res * sign);
}
