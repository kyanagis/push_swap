/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:48:56 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:20:53 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	sub = (char *)malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}
// int	main(void)
// {
// 	char *s;
// 	char *ret;

// 	s = "libft success";
// 	ret = ft_substr(s, 0, 5);
// 	printf("ft_substr: %s\n", ret);
// 	free(ret);

// 	ret = ft_substr(s, 6, 7);
// 	printf("ft_substr: %s\n", ret);
// 	free(ret);

// 	ret = ft_substr(s, 20, 5);
// 	printf("start > len: \"%s\"\n", ret);
// 	free(ret);

// 	ret = ft_substr(s, 5, 100);
// 	printf("len > size: \"%s\"\n", ret);
// 	free(ret);

// 	ret = ft_substr("", 0, 5);
// 	printf("empty src: \"%s\"\n", ret);
// 	free(ret);

// 	ret = ft_substr(NULL, 0, 5);
// 	printf("NULL input: %s\n", ret); // NULLなら"(null)"になる
// 	free(ret);

// 	return (0);
// }