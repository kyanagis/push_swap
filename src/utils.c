#include "push_swap.h"

static t_node *lstlast(t_node *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

t_node  *create_node(int value)
{
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->rank = 0;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void    append_node(t_node **stack, int value)
{
    t_node *new = create_node(value);
    t_node *last;

    if (!new)
        return ;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    last = lstlast(*stack);
    last->next = new;
    new->prev = last;
}

size_t  stack_size(t_node *stack)
{
    size_t i = 0;
    while (stack)
    {
        ++i;
        stack = stack->next;
    }
    return (i);
}

int     is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    free_stack(t_node **stack)
{
    t_node *cur;
    t_node *next;

    cur = *stack;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *stack = NULL;
}