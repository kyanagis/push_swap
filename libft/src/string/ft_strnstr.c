/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:37 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/15 14:02:12 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	if (!*needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (*haystack && len >= nlen)
	{
		if (haystack[0] == needle[0] && !ft_memcmp(haystack, needle, nlen))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *big = "pasuta,ramen,yakiniku";
// 	char *little1 = "ramen";
// 	char *little2 = "notfound";
// 	char *little3 = "";

// 	printf("ft_strnstr: %s\n", ft_strnstr(big, little1, 30));

// 	printf("ft_strnstr: %s\n", ft_strnstr(big, little1, 10));

// 	printf("ft_strnstr: %s\n", ft_strnstr(big, little2, 30));

// 	printf("ft_strnstr: %s\n", ft_strnstr(big, little3, 30));

// 	printf("ft_strnstr: %s\n", ft_strnstr("libft is cool", "libft", 5));

// return (0);
// }