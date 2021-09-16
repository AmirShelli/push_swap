#include "../inc/push_swap.h" 

int	is_sorted(t_stack *stack)
{
	int size = stack->size;
	int i = 0;

	while (i < size - 1)
	{	
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;	
	}
	return (1);
}

void bubble_sort(t_stack *a, t_stack *b)
{
	int i;

	while (!is_sorted(a))
	{
		i = 0;
		while (i < a->size - 1)
		{	
			if (a->arr[i] > a->arr[i + 1])
			{	
				reach(i, a, b);
				pick("sa", a, b);
			}
			i++;
		}
		pa_all(a, b);
	}
}

