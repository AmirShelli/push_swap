#include "../inc/push_swap.h"

void reverse_a(t_stack *a)
{
    int aux;
    int i = 0;

    if(a.size > 1)
    {
        aux = a.arr[a.size - 1];
        a.arr[a.size - 1] = a.arr[0];
        a.arr[a.size - 1] = aux;
    }
    write(1, "ra\n", 3);
}

void reverse_b(t_stack *a)
{
    int aux;
    int i = 0;

    if(a.size > 1)
    {
        aux = a.arr[];
        a.arr[a.size - 1] = a.arr[0];
        a.arr[a.size - 1] = aux;
    }
    write(1, "rb\n", 3);
}

void reverse_both(t_stack *a, t_stack *b)
{
	int aux;
    int i;

    i = 0;
    if(a.size > 1)
    {
        aux = a.arr[a.size - 1];
        a.arr[a.size - 1] = a.arr[0];
        a.arr[a.size - 1] = aux;
    }
    i = 0;
    if(b.size > 1)
    {
        aux = b.arr[b.size - 1];
        b.arr[b.size - 1] = b.arr[0];
        b.arr[a.size - 1] = aux;
    }
    write(1, "rr\n", 3);
}