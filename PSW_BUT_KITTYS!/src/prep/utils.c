#include "../../inc/push_swap.h"

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

void auto_move(char *smaller,char *bigger, int index, t_push_swap *stacks)
{
	t_stack *stack;
	int		size;

	if (smaller[1] == 'a')
	{	
		stack = stacks->a;
		size = stacks->size_a;
	}
	else
	{	
		stack = stacks->b;
		size = stacks->size_b;
	}	
	if (index >= size/2)
		while(index--)
			pick(bigger, stacks);
	else
	{
		index = size - index;
		while(index--)
			pick(smaller, stacks);
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

void	ultimate_free(t_push_swap *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
