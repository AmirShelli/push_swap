#include "../inc/push_swap.h"

void swap_a(t_stack *a)
{
    int aux;

    if((*a).size > 1)
    {
        aux = (*a).arr[(*a).size - 1];
        (*a).arr[(*a).size - 1] = (*a).arr[(*a).size - 2];
        (*a).arr[(*a).size - 2] = aux;
    }
    write(1, "sa\n", 3);
}

void swap_b(t_stack *a)
{
    int aux;

    if((*a).size > 1)
    {
        aux = (*a).arr[(*a).size - 1];
        (*a).arr[(*a).size - 1] = (*a).arr[(*a).size - 2];
        (*a).arr[(*a).size - 2] = aux;
    }
    write(1, "sb\n", 3);
}

void swap_both(t_stack *a, t_stack *b)
{
    int aux;

    if((*a).size > 1)
    {
        aux = (*a).arr[(*a).size - 1];
        (*a).arr[(*a).size - 1] = (*a).arr[(*a).size - 2];
        (*a).arr[(*a).size - 2] = aux;
    }
    if((*b).size > 1)
    {
        aux = (*b).arr[(*b).size - 1];
        (*b).arr[(*b).size - 1] = (*b).arr[(*b).size - 2];
        (*b).arr[(*b).size - 2] = aux;
    }
    write(1, "ss\n", 3);
}