/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:42:17 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:21:07 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, len + 1);
	return (copy);
}

// int	main(void)
// {
// 	const char *s = "kanojo_ni_hurareta!";
// 	char *std = strdup(s);
// 	char *ft = ft_strdup(s);

// 	if (!std || !ft)
// 	{
// 		printf("Allocation failed\n");
// 		free(std);
// 		free(ft);
// 		return (1);
// 	}
// 	printf("ft_strdup: %s\n", ft);
// 	printf("std_strdup: %s\n", std);

// 	if (strcmp(ft, std) == 0)
// 		printf("ft_strdup matches strdup\n");
// 	else
// 		printf("Mismatch: %s vs %s\n", ft, std);

// 	free(std);
// 	free(ft);
// 	return (0);
// }