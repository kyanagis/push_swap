/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:33 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:20:41 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "abcdef";
// 	char *s2 = "abcxyz";

// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 3));
// 	printf("strncmp:    %d\n", strncmp(s1, s2, 3));

// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 4));
// 	printf("strncmp:    %d\n", strncmp(s1, s2, 4));

// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, "zzz", 3));
// 	printf("strncmp:    %d\n", strncmp(s1, "zzz", 3));

// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 0));
// 	printf("strncmp:    %d\n", strncmp(s1, s2, 0));

// 	printf("ft_strncmp: %d\n", ft_strncmp("abc", "abc\0def", 10));
// 	printf("strncmp:    %d\n", strncmp("abc", "abc\0def", 10));

// 	printf("ft_strncmp: %d\n", ft_strncmp("same", "same", 10));
// 	printf("strncmp:    %d\n", strncmp("same", "same", 10));

// 	return (0);
// }