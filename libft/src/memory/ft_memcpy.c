/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:13:58 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/13 12:51:05 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "Hello World!";
// 	char d1[20];
// 	char d2[20];

// 	ft_memcpy(d1, src, 12);
// 	memcpy(d2, src, 12);
// 	printf("ft_memcpy: %s\n", d1);
// printf("memcpy   : %s\n", d2);

// 	return (0);
// }