#include "push_swap.h"

static size_t	count_ws_words(const char *s)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			++i;
		if (s[i])
			++w;
		while (s[i] && !ft_isspace(s[i]))
			++i;
	}
	return (w);
}

static char	**ft_split_ws(const char *s)
{
	size_t	i;
	size_t	start;
	size_t	idx;
	char	**arr;

	i = 0;
	idx = 0;
	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_ws_words(s) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			++i;
		start = i;
		while (s[i] && !ft_isspace(s[i]))
			++i;
		if (i > start)
		{
			arr[idx] = ft_substr(s, start, i - start);
			if (!arr[idx++])
				return (free_split(arr), NULL);
		}
	}
	arr[idx] = NULL;
	return (arr);
}
// static char	**ft_split_ws(const char *s)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	t;
// 	char	**arr;

// 	i = 0;
// 	t = 0;
// 	if (!s)
// 		return (NULL);
// 	arr = malloc(sizeof(char *) * (ft_strlen(s) + 1));
// 	if (!arr)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		while (s[i] && ft_isspace(s[i]))
// 			++i;
// 		j = i;
// 		while (s[i] && !ft_isspace(s[i]))
// 			++i;
// 		if (i > j)
// 		{
// 			arr[t] = ft_substr(s, j, i - j);
// 			if (!arr[t++])
// 				return (free_split(arr), NULL);
// 		}
// 	}
// 	arr[t] = NULL;
// 	return (arr);
// }

static void	append_from_str(char *s, t_node **a)
{
	long	val;

	if (!is_valid_number(s))
		error_exit();
	val = ft_atol(s);
	if (val > INT_MAX || val < INT_MIN)
		error_exit();
	append_node(a, (int)val);
}

static int	has_duplicates(t_node *head)
{
	t_node	*cur;
	t_node	*cmp;

	cur = head;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cmp->value == cur->value)
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	parse_arguments(int argc, char **argv, t_node **a)
{
	int		i;
	int		k;
	char	**tok;

	i = 1;
	while (i < argc)
	{
		tok = ft_split_ws(argv[i]);
		if (!tok || !tok[0])
		{
			free_split(tok);
			error_exit();
		}
		k = 0;
		while (tok[k])
			append_from_str(tok[k++], a);
		free_split(tok);
		++i;
	}
	if (has_duplicates(*a))
		error_exit();
}
