#include "../inc/push_swap.h"

void push_b(t_stack *a, t_stack *b)
{
	move_forward(b, 0);
	
    write(1, "pb\n", 3);
}

void push_a(t_stack *a, t_stack *b)
{
    if(b->size)
    {
        b->arr[b->size] = a->arr[a->size - 1];
        a->size += 1; // increase length of a
        b->size -= 1; // decrease length of b
    }
    write(1, "pa\n", 3);
}