
#include "push_swap.h"

static size_t	count_tokens(const char *s)
{
	size_t	i;
	size_t	tok;

	i = 0;
	tok = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			++i;
		if (s[i])
			++tok;
		while (s[i] && !ft_isspace(s[i]))
			++i;
	}
	return (tok);
}
static int	fill_tokens(char **arr, const char *s)
{
	size_t	i;
	size_t	start;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			++i;
		start = i;
		while (s[i] && !ft_isspace(s[i]))
			++i;
		if (i > start)
		{
			arr[idx] = ft_substr(s, start, i - start);
			if (!arr[idx++])
				return (0);
		}
	}
	return (1);
}

char	**ft_split_ws(const char *s)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_tokens(s) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_tokens(arr, s))
		return (free_split(arr), NULL);
	return (arr);
}
