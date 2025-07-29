/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:34:03 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 19:41:01 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int	main(void)
// {
// 	size_t count = 0;
// 	size_t size = sizeof(char);
// 	char *ft = (char *)ft_calloc(count, size);
// 	char *std = (char *)calloc(count, size);
// 	int i;

// 	if (!ft || !std)
// 	{
// 		printf("Allocation failed\n");
// 		free(ft);
// 		free(std);
// 		return (1);
// 	}

// 	printf("ft_calloc vs calloc (10 chars)\n");
// 	for (i = 0; i < (int)(count * size); ++i)
// 		printf("%d vs %d\n", ft[i], std[i]);

// 	free(ft);
// 	free(std);
// 	return (0);
// }