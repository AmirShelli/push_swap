#include "../inc/push_swap.h"

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

// int	get_min_max(t_stack *stack, int min_max)
// {
// 	int		comp;

// 	if (!min_max)
// 		comp = INT_MAX;
// 	else
// 		comp = INT_MIN;
// 	while (stack)
// 	{
// 		if ((!min_max && stack->num <= comp) || (min_max && stack->num >= comp))
// 			comp = stack->num;
// 		stack = stack->next;
// 	}
// 	return (comp);
// }

