#include "../inc/push_swap.h"

void move_forward(t_stack *a, int from)
{
	if((a->size - 1 >= from + 1))
		move_forward(a, from + 1);
	a->arr[from + 1] = a->arr[from];
}

void	move_backward(t_stack *a, int from)
{
	a->arr[from - 1] = a->arr[from];
	if ((a->size - 1) >= from)
		move_backward(a, from + 1);
}

void	pb_until(int to, t_stack *a, t_stack *b)
{
	int	from = 0;

	while (from++ != to)
		pick("pb", a, b);
}

void	pa_all(t_stack *a, t_stack *b)
{
	int	i = 0;

	while(i++ < b->size)
		pick("pa", a, b);
}

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

int	is_biggest(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < size)
		if (stack->arr[0] < stack->arr[i])
			return (0);
	return (1);
}

