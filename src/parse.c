
#include "push_swap.h"

static void	append_from_str(char *s, t_node **a)
{
	long	val;

	if (!is_valid_number(s))
		error_exit();
	val = ft_atol(s);
	if (val < INT_MIN || val > INT_MAX)
		error_exit();
	append_node(a, (int)val);
}

static int	has_dup(t_node *head)
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

void	parse_arguments(int ac, char **av, t_node **a)
{
	int		i;
	int		k;
	char	**tok;

	i = 1;
	while (i < ac)
	{
		tok = ft_split_ws(av[i]);
		if (!tok || !tok[0])
			return (free_split(tok), error_exit(), (void)0);
		k = 0;
		while (tok[k])
			append_from_str(tok[k++], a);
		free_split(tok);
		++i;
	}
	if (has_dup(*a))
		error_exit();
}
