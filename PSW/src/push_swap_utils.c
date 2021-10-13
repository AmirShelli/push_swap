#include "../inc/push_swap.h"

int index_a(t_stacks *stacks, int num);
int movement(t_stack stack, int index);
int best_index(t_stacks *stacks);
int	find_order(t_stacks *stacks);

//push everything to b except for the ordered part
void push_to_b(t_stacks *stacks, int flag)
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
				pick("ra\n", stacks);
				i++;
			}
			pick("ra\n", stacks);
		}
		else if (stacks->a.arr[0] != order && (stacks->a.arr[0] - stacks->middle) * flag > 0) // if -1 -> arr[0] < middle, if 1 -> arr[0] > middle
			pick("pb\n", stacks);
		i++;
	}
}

//pushes everything back to a
void push_to_a(t_stacks *stacks)
{
	int		index[2];

	while (stacks->b.size)
	{
		index[0] = index_a(stacks, best_index(stacks));
		index[1] = best_index(stacks);
		if (index[0] >= stacks->a.size/2 && index[1] >= stacks->b.size/2)
			while(index[0]-- && index[1]--)
				pick("rrr\n", stacks);
		else if (index[0] < stacks->a.size/2 && index[1] < stacks->b.size/2)
		{
			index[0] = stacks->a.size - index[0];
			index[1] = stacks->b.size - index[1];
			while(index[0]-- && index[1]--)
				pick("rr\n", stacks);
		}
		if(index[0])
			move("ra\n", "rra\n", index[0], stacks);
		else if(index[1])
			move("rb\n", "rrb\n", index[1], stacks);
		pick("pa\n", stacks);
	}
}

int index_a(t_stacks *stacks, int num)
{
	int index;

	index = 0;
	while (index < stacks->a.size - 1 && num > stacks->a.arr[index])
		index++;
	return (index);
}

int movement(t_stack stack, int index)
{
		if(index < stack.size/2)
			return(index);
		else
			return ((stack.size - index));
}

int best_index(t_stacks *stacks)
{
	int index_b;
	int num_moves;
	int best_moves;
	int best_index;

	index_b = 0;
	best_index = index_b;
	best_moves = movement(stacks->b, index_b) + movement(stacks->b, index_a(stacks, index_b));
	while (index_b < stacks->b.size)
	{
		num_moves = movement(stacks->b, index_b) + movement(stacks->b, index_a(stacks, index_b));
		if(best_moves >= num_moves)
		{	
			best_moves = num_moves;
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}

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
