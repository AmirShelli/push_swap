#include "../inc/push_swap.h"

int index_a(t_stacks stacks, int num);
int index_b(t_stacks stacks, int index_b);
int best_index(t_stacks stacks);

//push everything to b except for the ordered part
void push_to_b(t_stacks stacks)
{
	int order;
	int i;

	i = 0;
	order = find_order(stacks);
	while (i < stacks->a.size)
	{
		if(stacks->a.arr[0] == order && order != 1)
		{	
			while(stacks->a.arr[0] < stacks->a.arr[1])
			{	
				pick("ra", stacks);
				i++;
			}
			pick("ra", stacks);
		}
		else if (stacks->a.arr[0] != order)
			pick("pb", stacks);
		i++;
	}
}

//pushes everything back to a
void push_to_a(t_stacks *stacks)
{
	int		*index;

	while (stacks->b.size)
	{
		index[0] = index_a(stacks, best_index(stacks));
		index[1] = index_b(stacks, best_index(stacks));
		if (index[0] >= a.size/2 && index[1] >= b.size/2)
			while(index[0]-- && index[1]--)
				pick("rrr", stacks);
		else if (index[0] < a.size/2 && index[1] < b.size/2)
		{
			index_a = a.size - index_a;
			index_b = b.size - index_b;
			while(index[0]-- && index[1]--)
				pick("rr", stacks);
		}
		if(index[0])
			move("ra", "rra", index[0], stacks)
		else
			move("rb", "rrb", index[1], stacks)
		pick("pa", stacks);
	}
}

int index_a(t_stacks stacks, int num)
{
	int index_a;

	index_a = 0;
	while (index_a < stacks->a.size)
	{
		if (num < stacks->a.arr[index_a])
			if(index_b < stacks->a.size/2)
				return(index_a);
			else
				return(size - index_a);
	}
}

int index_b(t_stacks stacks, int index_b)
{
		if(index_b < stacks->b.size/2)
			return(index_b + index_a(stacks, stacks->b.arr[index_b]));
		else
			return ((size - index_b) + index_a(stacks, stacks->b.arr[index_b]));
}

int best_index(t_stacks stacks)
{
	int index_b;
	int best_moves;
	int best_index;

	index_b = 0;
	best_index = index_b;
	best_moves = index_b(stacks, index_b) + index_a(stacks, index_a);
	while (index_b < stacks->b.size)
	{
		if(best_moves >= index_b(stacks, index_b) + index_a(stacks, index_a))
		{	
			best_moves = index_b(stacks, index_b) + index_a(stacks, index_a);
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}