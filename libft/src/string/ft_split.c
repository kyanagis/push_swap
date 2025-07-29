/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:41:53 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 20:01:08 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **split, size_t i)
{
	while (i-- > 0)
		free(split[i]);
	free(split);
	return (NULL);
}

static size_t	count_word(const char *str, char sep)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == sep)
			++str;
		if (*str && *str != sep)
		{
			++count;
			while (*str && *str != sep)
				++str;
		}
	}
	return (count);
}

static char	*make_word(const char **s, char c)
{
	size_t	len;
	char	*word;

	while (**s && **s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		++len;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, *s, len);
	word[len] = '\0';
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = make_word(&s, c);
		if (!split[i])
			return (free_all(split, i));
		++i;
	}
	split[i] = NULL;
	return (split);
}

// void	print_split_result(char **result)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!result)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	while (result[i])
// 	{
// 		printf("[%s]\n", result[i]);
// 		free(result[i]);
// 		++i;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	char	**result;

// 	printf("=== Normal Case ===\n");
// 	result = ft_split("hello world this is 42", ' ');
// 	print_split_result(result);
// 	printf("=== Multiple Delimiters ===\n");
// 	result = ft_split("  hello   world 42  ", ' ');
// 	print_split_result(result);
// 	printf("=== Empty String ===\n");
// 	result = ft_split("", ' ');
// 	print_split_result(result);
// 	printf("=== Only Delimiters ===\n");
// 	result = ft_split("     ", ' ');
// 	print_split_result(result);
// 	printf("=== No Delimiters ===\n");
// 	result = ft_split("hello", ' ');
// 	print_split_result(result);
// 	printf("=== Delimiter at Ends ===\n");
// 	result = ft_split(",42Tokyo,Network,", ',');
// 	print_split_result(result);
// 	printf("=== Null Input ===\n");
// 	result = ft_split(NULL, ',');
// 	print_split_result(result);
// 	return (0);
// }
