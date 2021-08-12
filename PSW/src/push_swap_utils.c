#include "../inc/push_swap.h"

void move_forward(t_stack *a, int from)
{
	if((a->size - 1) != from)
		move_forward(a, from + 1);
	a->arr[from + 1] = a->arr[from];
}

void move_backward(t_stack *a, int from)
{
	if(from > 0)
	{
		a->arr[from - 1] = a->arr[from];
		if((a->size - 1) != from)
			move_backward(a, from + 1);
	}
}
