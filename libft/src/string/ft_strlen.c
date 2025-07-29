/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:28 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 19:50:55 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		++s;
	return ((size_t)(s - start));
}

// int	main(void)
// {
// 	char *s = NULL;
// 	printf("%zu\n", ft_strlen(s));
// }
