/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:00 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 19:38:40 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (len == 0 || dst == src)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

// int	main(void)
// {
// 	char s1[20] = "123456789";
// 	char s2[20] = "12345678900";

// 	ft_memmove(s1 + 7, s1, 5);
// 	memmove(s2 + 7, s2, 5);
// 	printf("ft_memmove: %s\nmemmove:   %s\n", s1, s2);

// 	ft_memmove(s1, s1, 0);
// 	memmove(s2, s2, 0);
// 	printf("0byte\nft_memmove: %s\nmemmove:   %s\n", s1, s2);

// 	return (0);
// }