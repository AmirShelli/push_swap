#include "../inc/push_swap.h"

void push_b(t_stack *a, t_stack *b)
{
    if(a->size)
    {
        move_forward(b, 0);
        b->arr[0] = a->arr[0];
        move_forward(a, 0);
        a->size -= 1; // decrease length of a
        b->size += 1; // increase length of b
        write(1, "pb\n", 3);
    }
}

void push_a(t_stack *a, t_stack *b)
{
    if(b->size)
    {
        move_forward(a, 0);
	    a->arr[0] = b->arr[0];
        move_backward(b, 0);
        a->size += 1; // increase length of a
        b->size -= 1; // decrease length of b
        write(1, "pa\n", 3);
    }
}