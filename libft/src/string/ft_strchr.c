/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:24 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:20:31 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		++s;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char *s = "abcdefg";

// 	printf("ft_strchr: %p\n", ft_strchr(s, 'd'));
// 	printf("strchr: %p\n", strchr(s, 'd'));

// 	printf("ft_strchr: %p\n", ft_strchr(s, 'g'));
// 	printf("strchr: %p\n", strchr(s, 'g'));

// 	printf("ft_strchr: %p\n", ft_strchr(s, '\0'));
// 	printf("strchr: %p\n", strchr(s, '\0'));

// 	return (0);
// }