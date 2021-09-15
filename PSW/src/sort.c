#include "../inc/push_swap.h" 

int	is_sort(t_stack *stack)
{
	int size = stack->size;
	int i = -1;

	while (i++ <= size - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}
