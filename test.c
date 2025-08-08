
#include <limits.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

int	index_of_min(t_node *stack_a)
{
	int	res;

	res = INT_MAX;
	while (stack_a->value)
	{
		if (res < stack_a->value)
			res = stack_a->value;
		stack_a = stack_a->next;
	}
	return (res);
}
