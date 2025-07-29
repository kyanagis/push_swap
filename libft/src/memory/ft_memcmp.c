/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:56 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/08 04:33:56 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1 = (const unsigned char *)s1;
	const unsigned char	*ptr2 = (const unsigned char *)s2;

	while (n--)
	{
		if (*ptr1 != *ptr2)
			return ((int)(*ptr1 - *ptr2));
		++ptr1;
		++ptr2;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "abc123defg456";
// 	s2 = "abc123456defg";
// 	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 6));
// 	printf("memcmp: %d\n", memcmp(s1, s2, 6));
// 	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 7));
// 	printf("memcmp: %d\n", memcmp(s1, s2, 7));
// 	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 0));
// 	printf("memcmp: %d\n", memcmp(s1, s2, 0));
// 	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, SIZE_MAX));
// 	printf("memcmp: %d\n", memcmp(s1, s2, SIZE_MAX));
// }
