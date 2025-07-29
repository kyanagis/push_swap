/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:30:48 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/13 12:52:25 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*orignal;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	orignal = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!orignal)
		return (NULL);
	ft_memcpy(orignal, s1, s1_len);
	ft_memcpy(orignal + s1_len, s2, s2_len);
	orignal[s1_len + s2_len] = '\0';
	return (orignal);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strjoin("42", "Tokyo");
// 	if (result)
// 	{
// 		printf("%s\n", result);
// 		free(result);
// 	}
// }
