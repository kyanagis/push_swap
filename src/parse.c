#include "push_swap.h"

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
	}
	return (0);
}

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

static void	fill_from_split(char *arg, t_node **a)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(arg, ' ');
	if (!nums || !nums[0])
		error_exit();
	while (nums[i])
		append_from_str(nums[i++], a);
	free_split(nums);
}

static void	fill_from_argv(int argc, char **argv, t_node **a)
{
	int	i;

	i = 1;
	while (i < argc)
		append_from_str(argv[i++], a);
}

void	parse_arguments(int argc, char **argv, t_node **stack_a)
{
	if (argc == 2)
		fill_from_split(argv[1], stack_a);
	else
		fill_from_argv(argc, argv, stack_a);
	if (has_duplicates(*stack_a))
		error_exit();
}
