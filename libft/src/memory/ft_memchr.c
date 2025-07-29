/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:51 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 19:16:53 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		++ptr;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *a = "abcdefg";

// 	printf("ft_memchr: %p\n", ft_memchr(a, 'b', 5));
// 	printf("memchr: %p\n", memchr(a, 'b', 5));

// 	printf("ft_memchr: %p\n", ft_memchr(a, 'g', 2));
// 	printf("memchr: %p\n", memchr(a, 'g', 2));

// 	printf("ft_memchr: %p\n", ft_memchr(a, 's', 100));
// 	printf("memchr: %p\n", memchr(a, 's', 100));
// }