#include "../inc/push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		move_forward(b, 0);
		b->arr[0] = a->arr[0];
		move_backward(a, 0);
		a->size -= 1;
		b->size += 1;
	}
}

void	swap(t_stack *stack)
{
	int	aux;

	if (stack->size > 1)
	{
		aux = stack->arr[0];
		stack->arr[0] = stack->arr[1];
		stack->arr[1] = aux;
	}
}

void	rotate(t_stack *stack)
{
	int	aux;

	aux = stack->arr[0];
	if (stack->size > 1)
	{
		move_backward(stack, 0);
		stack->arr[stack->size - 1] = aux;
	}
}

void	reverse(t_stack *stack)
{
	int	aux;

	aux = stack->arr[stack->size - 1];
	if (stack->size > 1)
	{
		move_forward(stack, 0);
		stack->arr[0] = aux;
	}
}
