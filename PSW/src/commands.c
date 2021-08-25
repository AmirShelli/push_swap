#include "../inc/push_swap.h"

void push(t_stack *a, t_stack *b)
{
    if(a->size)
    {
        move_forward(b, 0);
        b->arr[0] = a->arr[0];
        move_backward(a, 0);
        a->size -= 1;
        b->size += 1;
	}
    // write(1, "pb\n", 3);
}
void swap(t_stack *a)
{
    int aux;
	
    if(a->size > 1)
    {
        aux = a->arr[0];
        a->arr[0] = a->arr[1];
        a->arr[1] = aux;
    }
    // write(1, "sa\n", 3);
}
void rotate(t_stack *a)
{
    int aux = a->arr[0];

    if(a->size > 1)
    {
        move_backward(a, 0);
        a->arr[a->size - 1] = aux;
    }
    // write(1, "ra\n", 3);
}
void reverse(t_stack *a)
{
    int aux = a->arr[a->size - 1];
    
    if(a->size > 1)
    {
        move_forward(a, 0);
        a->arr[0] = aux;
    }
    // write(1, "rra\n", 4);
}
