#include "../inc/push_swap.h"

int	find_order(t_stacks *stacks)
{
	int	i;
	int order;
	int biggest_order;
	int	order_number;

	i = 0;
	biggest_order = 0;
	order = 0;
	while (i < stacks->a.size - 1)
	{
		if (stacks->a.arr[i] < stacks->a.arr[i + 1])
			order++;
		else
		{	
			if (biggest_order < order)
			{	
				biggest_order = order;
				order_number = stacks->a.arr[i - order];
			}
			order = 0;
		}
		i++;
	}
	return (order_number);
}
