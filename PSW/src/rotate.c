#include "push_swap.h"

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