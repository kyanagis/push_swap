/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:39:13 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/13 12:50:36 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		++start;
	while (end > start && is_in_set(s1[end - 1], set))
		--end;
	len = end - start;
	trimmed = (char *)malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*set;
// 	char	*trimmed;

// 	s = " \t\n42Tokyo!\n\t ";
// 	set = " \n\t";
// 	trimmed = ft_strtrim(s, set);
// 	if (trimmed)
// 	{
// 		printf("Result: \"%s\"\n", trimmed);
// 		free(trimmed);
// 	}
// }
