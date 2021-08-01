#include "../inc/push_swap.h"

void swap_a(int *arr)
{
    int aux;

    if(ft_intlen(arr) > 1)
    {
        aux = arr[ft_intlen(arr) - 1];
        arr[ft_intlen(arr) - 1] = arr[ft_intlen(arr) - 2];
        arr[ft_intlen(arr) - 2] = aux;
    }
    write(1, "sa\n", 3);
}

void swap_b(int *arr)
{
    int aux;

    if(ft_intlen(arr) > 1)
    {
        aux = arr[ft_intlen(arr) - 1];
        arr[ft_intlen(arr) - 1] = arr[ft_intlen(arr) - 2];
        arr[ft_intlen(arr) - 2] = aux;
    }
    write(1, "sb\n", 3);
}

void swap_both(int *a, int *b)
{
    int aux;

    if(ft_intlen(a) > 1)
    {
        aux = a[ft_intlen(a) - 1];
        a[ft_intlen(a) - 1] = a[ft_intlen(a) - 2];
        a[ft_intlen(a) - 2] = aux;
    }
    if(ft_intlen(b) > 1)
    {
        aux = b[ft_intlen(b) - 1];
        b[ft_intlen(b) - 1] = a[ft_intlen(b) - 2];
        b[ft_intlen(b) - 2] = aux;
    }
    write(1, "ss\n", 3);
}