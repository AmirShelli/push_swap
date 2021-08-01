#include "../inc/push_swap.h"

void rotate_a(int *arr)
{
    int before = arr [0];
    int after;
    int size = ft_intlen(arr);
    int i = 0;

    if(size > 1)
    {
        while (i++ < size)
        {
            after = arr[i + 1];
            arr[i + 1] = before;
            before = after; 
        }
        arr[0] = before;
    }
    write(1, "ra\n", 3);
}

void rotate_b(int *arr)
{
    int before = arr [0];
    int after;
    int size = ft_intlen(arr);
    int i = 0;

    if(size > 1)
    {
        while (i++ < size)
        {
            after = arr[i + 1];
            arr[i + 1] = before;
            before = after; 
        }
        arr[0] = before;
    }
    write(1, "rb\n", 3);
}

void rotate_both(int *a, int *b)
{
    int before = arr [0];
    int after;
    int size = ft_intlen(a;
    int i;

    i = 0;
    if(size > 1)
    {
        while (i++ < size)
        {
            after = a[i + 1];
            a[i + 1] = before;
            before = after; 
        }
        a[0] = before;
    }
    size = ft_intlen(b);
    i = 0;
    if(size > 1)
    {
        while (i++ < size)
        {
            after = b[i + 1];
            b[i + 1] = before;
            before = after; 
        }
        b[0] = before;
    }
    write(1, "rr\n", 3);
}