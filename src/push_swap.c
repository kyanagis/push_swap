/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 05:51:04 by kyanagis          #+#    #+#             */
/*   Updated: 2025/07/29 23:14:43 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct  s_node
{
    int value;
    struct s_node *prev;
    struct s_node *next;
}t_node;

void error_exit()
{
    write(STDERR_FILENO,"Error\n",6);
    exit(EXIT_FAILURE);
}


t_node *create_new_node(int value)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if(!new_node)
        error_exit();
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


void append_node(t_node **stack,int num)
{
    t_node *new_node;
    t_node *last;
    new_node = create_new_node(num);
    if(!*stack)
    {
        *stack = new_node;
        return ;
    }
    last = *stack;
    while(last->next)
        last = last->next;

        last->next = new_node;
        new_node->prev = last;
}


int ft_isdigit(int c)
{
    return(c >= '0' && c <= '9');
}
int is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i])
	{
		if (s[i] != '.' && !ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (i == 0 || (i == 1 && (s[0] == '+' || s[0] == '-')))
		return (0);
	return (1);
}

void parse_arguments(int argc,char **argv,t_node **stack_a)
{
    int i;
    long num;

    if(argc == 2)
    {
        //splitを使う
    }
    i = 1;
    while(i < argc)
    {
        if(!is_valid_number(argv[i]))
            error_exit();
        num = ft_atol(argv[i]);
        if(num > INT_MAX || num < INT_MIN)
            error_exit();
            append_node(stack_a,(int)num);
            ++i;
    }

    //追加したスタックに重複がないかの処理
}

int main(int argc,char **argv)
{
t_node *stack_a = NULL;

    if(argc < 2)
        return 0;

parse_arguments(argc, argv, &stack_a);



//sort algo　追加予定

	t_node *current = stack_a;
	t_node *next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	return (EXIT_SUCCESS);
}



