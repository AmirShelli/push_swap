#include "../inc/push_swap.h"

void rotate_a(t_stack *a)
{
    int before = a.a.arr[0];
    int after;
    int i = 0;

    if(a.size > 1)
    {
        aux = a.arr[a.size - 1];
        a.arr[a.size - 1] = a.arr[0];
        a.arr[0] = aux;
    }
    write(1, "ra\n", 3);
}

void rotate_b(t_stack *a)
{
    int before = a.arr[0];
    int after;
    int i = 0;

    if(a.size > 1)
    {
        aux = a.arr[a.size - 1];
        a.arr[a.size - 1] = a.arr[0];
        a.arr[0] = aux;
    }
    write(1, "rb\n", 3);
}

void rotate_both(t_stack *a, t_stack *b)
{
    int before = a.arr[0];
    int after;
    int i;

    i = 0;
    if(a.size > 1)
    {
        while (i++ < a.size)
        {
            after = a.arr[i + 1];
            a.arr[i + 1] = before;
            before = after; 
        }
        a.arr[0] = before;
    }
    i = 0;
    if(a.size > 1)
    {
        while (i++ < b.size)
        {
            after = b.arr[i + 1];
            b.arr[i + 1] = before;
            before = after; 
        }
        b.arr[0] = before;
    }
    write(1, "rr\n", 3);
}