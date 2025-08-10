/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 02:11:10 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/11 06:11:55 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (i == 0 || (i == 1 && (s[0] == '+' || s[0] == '-')))
		return (0);
	return (1);
}

static int	append_from_str(char *s, t_node **a)
{
	long	val;

	if (!is_valid_number(s))
		return (0);
	val = ft_atol(s);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	append_node(a, (int)val);
	return (1);
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

static void	free_error_exit(char **tok, t_node **a)
{
	free_split(tok);
	free_stack(a);
	error_exit();
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
			free_error_exit(tok, a);
		k = 0;
		while (tok[k])
		{
			if (!append_from_str(tok[k], a))
				free_error_exit(tok, a);
			++k;
		}
		free_split(tok);
		++i;
	}
	if (has_dup(*a))
	{
		free_stack(a);
		error_exit();
	}
}
