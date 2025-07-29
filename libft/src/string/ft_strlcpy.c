/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:37:59 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:18:21 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	char src[] = "1234567890";
// 	char dst1[50];

// 	ft_strlcpy(dst1, src, 50);
// 	printf("ft_strlcpy: %s\n", dst1);

// 	ft_strlcpy(dst1, src, 5);
// 	printf("ft_strlcpy: %s\n", dst1);

// 	size_t r1 = ft_strlcpy(dst1, src, 0);
// 	printf("ft_strlcpy return: %zu\n", r1);

// 	ft_strlcpy(dst1, "", 10);
// 	printf("ft_strlcpy: %s\n", dst1);

// 	ft_strlcpy(dst1, src, 1);
// 	printf("ft_strlcpy: %s\n", dst1);

// 	return (0);
// }
