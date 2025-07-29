/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:33:52 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/25 23:03:31 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	percent_next(const char **s, int *result, va_list ap)
{
	++*s;
	if (**s == 'd' || **s == 'i')
		ft_putnbr_res(va_arg(ap, int), result);
	else if (**s == 'c')
		ft_putchar_res((char)va_arg(ap, int), result);
	else if (**s == 's')
		ft_putstr_res(va_arg(ap, char *), result);
	else if (**s == 'p')
		ft_printf_ptr_res(va_arg(ap, void *), result);
	else if (**s == '%')
		ft_putchar_res('%', result);
	else if (**s == 'x')
		ft_puthex_res(va_arg(ap, unsigned int), result, 0);
	else if (**s == 'X')
		ft_puthex_res(va_arg(ap, unsigned int), result, 1);
	else if (**s == 'u')
		ft_putunsigned_res(va_arg(ap, unsigned int), result);
	else
		return (-1);
	++*s;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	if (!s || write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (result == -1)
			return (-1);
		if (*s == '%')
		{
			if (percent_next(&s, &result, ap) == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
			result += write(1, s++, 1);
	}
	va_end(ap);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		rev1;
// 	int		rev2;

// 	// setvbuf(stdout, NULL, _IONBF, 0);
// 	// close(1);
// 	// rev1 = printf("%d\n", 343);
// 	// 	// rev2 = ft_printf("%d\n", 343);
// 	// dprintf(2, "%d\n", rev1);
// 	// dprintf(2, "%d\n", rev2);
// 	printf("%d\n", printf(NULL));
// 	ft_printf("%d\n", ft_printf(NULL));
// 	printf("%d\n", printf(0));
// 	ft_printf("%d\n", ft_printf(0));
// 	printf("%d\n", printf("%%%"));
// 	ft_printf("%d\n", ft_printf("%%%"));
// 	ft_printf("---------%%c----------\n");
// 	printf("%d\n", printf("%c:", 'a'));
// 	ft_printf("%d\n", ft_printf("%c:", 'a'));
// 	printf("%d\n", printf("%c:", NULL));
// 	ft_printf("%d\n", ft_printf("%c:", NULL));
// 	ft_printf("---------%%s----------\n");
// 	printf("%d\n", printf("%s:", "0123456789"));
// 	ft_printf("%d\n", ft_printf("%s:", "0123456789"));
// 	printf("%d\n", printf("%s:", NULL));
// 	ft_printf("%d\n", ft_printf("%s:", NULL));
// 	ft_printf("---------%%p----------\n");
// 	printf("%d\n", printf("%p:", NULL));
// 	ft_printf("%d\n", ft_printf("%p:", NULL));
// 	printf("%d\n", printf("%p:", s1));
// 	ft_printf("%d\n", ft_printf("%p:", s1));
// 	printf("%d\n", printf("%p:", s2));
// 	ft_printf("%d\n", ft_printf("%p:", s2));
// 	ft_printf("---------%%d----------\n");
// 	printf("%d\n", printf("%d:", NULL));
// 	ft_printf("%d\n", ft_printf("%d:", NULL));
// 	printf("%d\n", printf("%d:", -45));
// 	ft_printf("%d\n", ft_printf("%d:", -45));
// 	printf("%d\n", printf("%d:", -2147483648));
// 	ft_printf("%d\n", ft_printf("%d:", -2147483648));
// 	printf("%d\n", printf("%d:", 2147483647));
// 	ft_printf("%d\n", ft_printf("%d:", 2147483647));
// 	ft_printf("---------%%i----------\n");
// 	printf("%d\n", printf("%i:", NULL));
// 	ft_printf("%d\n", ft_printf("%i:", NULL));
// 	printf("%d\n", printf("%i:", -45));
// 	ft_printf("%d\n", ft_printf("%i:", -45));
// 	printf("%d\n", printf("%i:", -2147483648));
// 	ft_printf("%d\n", ft_printf("%i:", -2147483648));
// 	printf("%d\n", printf("%i:", 2147483647));
// 	ft_printf("%d\n", ft_printf("%i:", 2147483647));
// 	ft_printf("---------%%u----------\n");
// 	printf("%d\n", printf("%u:", NULL));
// 	ft_printf("%d\n", ft_printf("%u:", NULL));
// 	printf("%d\n", printf("%u:", -1));
// 	ft_printf("%d\n", ft_printf("%u:", -1));
// 	printf("%d\n", printf("%u:", 4294967295));
// 	ft_printf("%d\n", ft_printf("%u:", 4294967295));
// 	printf("%d\n", printf(0));
// 	ft_printf("%d\n", ft_printf(0));
// 	ft_printf("---------%%x----------\n");
// 	printf("%d\n", printf("%x:", 0xfffffffffffffff));
// 	ft_printf("%d\n", ft_printf("%x:", 0xffffffffffffffff));
// 	printf("%d\n", printf("%x:", -2147483648));
// 	ft_printf("%d\n", ft_printf("%x:", -2147483648));
// 	printf("%d\n", printf("%x:", NULL));
// 	ft_printf("%d\n", ft_printf("%x:", NULL));
// 	ft_printf("---------%%X----------\n");
// 	printf("%d\n", printf("%X:", 0xffffffff));
// 	ft_printf("%d\n", ft_printf("%X:", 0xffffffff));
// 	printf("%d\n", printf("%X:", -2147483648));
// 	ft_printf("%d\n", ft_printf("%X:", -2147483648));
// 	printf("%d\n", printf("%X:", NULL));
// 	ft_printf("%d\n", ft_printf("%X:", NULL));
// }
