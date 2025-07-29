/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:37:52 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 20:24:48 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < dstsize && dst[dst_len])
		++dst_len;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (dst_len + i + 1 < dstsize && src[i])
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	buf1[50] = "Hello, ";
// 	char	*src;
// 	char	buf3[10] = "Hello";
// 	char	buf5[10] = "Hi";

// 	src = NULL;
// 	printf("ft_strlcat: %zu, result: %s\n", ft_strlcat(buf1, src, 50), buf1);
// 	printf("ft_strlcat: %zu, result: %s\n", ft_strlcat(buf3, src, 10), buf3);
// 	printf("ft_strlcat: %zu\n", ft_strlcat(buf5, src, 0));
// 	return (0);
// }
