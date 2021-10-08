#include "../inc/push_swap.h"

void push_to_b(t_stacks stacks)
{
	int order;
	int i;

	i = 0;
	order = find_order(stacks);
	while (i < stacks->a.size - 1)
	{
		if(stacks->a.arr[0] == order)
		{	
			while(stacks->a.arr[0] < stacks->a.arr[1])
			{	
				pick("rra", stacks);
				i++;
			}
			pick("rra", stacks);
		}
		else
			pick("pb", stacks);
		i++;
	}
}

int index_a

int find_best_index(t_stacks stacks)
{
	while (index_b < stacks->b.size)
	{
		if(index_b < stacks->b.size/2)
			move = index_b + index_a(stacks, stacks->b.arr[index_b])
		else
			move = (size - index_b) + index_a(index_b)
		if(best_move > move)
			best_move = move;
		index_b++;
	}
}