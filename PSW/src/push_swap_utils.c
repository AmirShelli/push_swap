#include "../inc/push_swap.h"

void move_forward(t_stack *a, int from)
{
	if((a->size - 1 >= from + 1))
		move_forward(a, from + 1);
	a->arr[from + 1] = a->arr[from];
}

void move_backward(t_stack *a, int from)
{
		a->arr[from - 1] = a->arr[from];
		if((a->size - 1) >= from)
			move_backward(a, from + 1);
}
