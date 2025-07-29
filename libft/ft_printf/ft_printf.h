/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:44:30 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/21 15:29:13 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_res(char c, int *result);
void	ft_putstr_res(char *s, int *result);
void	ft_putnbr_res(int n, int *result);
void	ft_putunsigned_res(unsigned int n, int *result);
void	ft_puthex_res(unsigned long n, int *result, int uppercase);
void	ft_printf_ptr_res(void *ptr, int *result);

#endif
