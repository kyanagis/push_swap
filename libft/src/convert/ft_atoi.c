/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 08:20:47 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 20:26:00 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return ((sign * result));
}

// int	main(void)
// {
// 	const char *tests[] = {"42", "   -42", " +42", "4193 with words",
// 		"words and 987", "-91283472332", "91283472332", "", "00000123",
// 		"2147483647", "2147483648", "-2147483648", "-2147483649", NULL};

// 	int i = 0;
// 	while (tests[i])
// 	{
// 		printf("Test %d: \"%s\"\n", i + 1, tests[i]);
// 		printf("ft_atoi: %d\n", ft_atoi(tests[i]));
// 		printf("atoi:    %d\n\n", atoi(tests[i]));
// 		i++;
// 	}
// 	return (0);
// }