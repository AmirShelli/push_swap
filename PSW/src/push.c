#include "push_swap.h"

void push_a(int *a, int *b)
{
    if(ft_intlen(a) && ft_intlen(b))
    {
        b[ft_intlen(b)] = a[ft_intlen(a) - 1];
        // increase length of b
        // decrease length of a
    }
    write(1, "pa\n", 3);
}

void push_b(int *a, int *b)
{
    if(ft_intlen(a) && ft_intlen(b))
    {
        a[ft_intlen(a)] = b[ft_intlen(b) - 1];
        // increase length of a
        // decrease length of b
    }
    write(1, "pb\n", 3);
}