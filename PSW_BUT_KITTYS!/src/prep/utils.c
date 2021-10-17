#include "../../inc/push_swap.h"

t_push_swap	*init(int size)
{
	t_push_swap	*stacks;

	stacks = ft_calloc(1, sizeof(t_push_swap));
	stacks->size_a = size;
	return (stacks);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	auto_move(char *smaller, char *bigger, int index, t_push_swap *stacks)
{
	int		size;

	if (smaller[1] == 'a')
		size = stacks->size_a;
	else
		size = stacks->size_b;
	if (index <= size / 2)
		while (index--)
			pick(smaller, stacks);
	else
	{
		index = size - index;
		while (index--)
			pick(bigger, stacks);
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
}

int	ultimate_free(t_push_swap *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
	return (1);
}
