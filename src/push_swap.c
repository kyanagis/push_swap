/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:51:04 by kyanagis          #+#    #+#             */
/*   Updated: 2025/08/02 05:01:10 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	is_valid_number(char *s)
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*current;
	t_node	*next;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	parse_arguments(argc, argv, &stack_a);
	// sort algo　追加予
	current = stack_a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (EXIT_SUCCESS);
}
