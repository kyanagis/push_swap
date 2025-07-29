/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:14 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/08 08:51:49 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

// int	main(void)
// {
// 	char s1[20] = "123456789";
// 	char s2[20] = "123456789";

// 	ft_memset(s1 + 7, '@', 5);
// 	memset(s2 + 7, '@', 5);
// 	printf("ft_memset: %s\nmemset: %s\n", s1, s2);

// 	ft_memset(s1, '@', 0);
// 	memset(s2, '@', 0);
// 	printf("0byte\nft_memset: %s\nmemst %s\n", s1, s2);
// }