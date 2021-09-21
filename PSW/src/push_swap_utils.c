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

int	biggest(t_stack *stack)
{
	int	i;
	int max;

	i = 1;
	max = stack->arr[0];
	while (i < stack->size)
	{	
		if ( max < stack->arr[i])
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	smallest(t_stack *stack)
{
	int	i;
	int min;

	i = 1;
	min = stack->arr[0];
	while (i < stack->size)
	{	
		if ( min > stack->arr[i])
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int is_in(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
		if (num == stack->arr[i++])
			return (1);
	return (0);
}
