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
