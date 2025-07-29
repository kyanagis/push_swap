/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:43:52 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/21 15:24:59 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_res(char c, int *result)
{
	*result += write(1, &c, 1);
}

void	ft_putstr_res(char *s, int *result)
{
	if (!s)
	{
		*result += write(1, "(null)", 6);
		return ;
	}
	while (*s)
		*result += write(1, s++, 1);
}
