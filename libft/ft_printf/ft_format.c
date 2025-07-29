/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:44:11 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/21 18:51:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_res(unsigned long n, int *result, int uppercase)
{
	const char	*hex;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_res(n / 16, result, uppercase);
	*result += write(1, &hex[n % 16], 1);
}

void	ft_printf_ptr_res(void *ptr, int *result)
{
	if (ptr == NULL)
		*result += write(1, "(nil)", 5);
	else
	{
		*result += write(1, "0x", 2);
		ft_puthex_res((unsigned long)ptr, result, 0);
	}
}

void	ft_putunsigned_res(unsigned int n, int *result)
{
	char	c;

	if (n >= 10)
		ft_putunsigned_res(n / 10, result);
	c = (n % 10) + '0';
	*result += write(1, &c, 1);
}

void	ft_putnbr_res(int n, int *result)
{
	char	c;
	long	nm;

	nm = (long)n;
	if (nm < 0)
	{
		*result += write(1, "-", 1);
		nm = -nm;
	}
	if (nm >= 10)
		ft_putnbr_res(nm / 10, result);
	c = (nm % 10) + '0';
	*result += write(1, &c, 1);
}
