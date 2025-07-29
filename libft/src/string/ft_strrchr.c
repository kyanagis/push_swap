/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:42 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/15 07:40:19 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	const char		*last = NULL;

	ch = (unsigned)c;
	while (*s)
	{
		if (*s == ch)
			last = s;
		++s;
	}
	if (ch == '\0')
		return ((char *)s);
	return ((char *)last);
}

// int	main(void)
// {
// 	char *s = "abcdefg";

// 	printf("ft_strrchr: %p\n", ft_strrchr(s, 'd'));
// 	printf("strrchr: %p\n", strrchr(s, 'd'));

// 	printf("ft_strrchr: %p\n", ft_strrchr(s, 'h'));
// 	printf("strrchr: %p\n", strrchr(s, 'h'));

// 	printf("ft_strrchr: %p\n", ft_strrchr(s, '\0'));
// 	printf("strrchr: %p\n", strrchr(s, '\0'));

// 	return (0);
// }
