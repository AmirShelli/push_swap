#include "../inc/push_swap.h"

int index_a(t_stacks *stacks, int num);
int movement(t_stack stack, int index);
int best_index(t_stacks *stacks);
int seperate_order(t_stacks *stacks);

void ultimate_sort(t_stacks *stacks)
{
	if(is_sorted(stacks))
	{
		seperate_order(stacks);
		push_to_b(stacks, BIGGER);
		push_to_b(stacks, SMALLER);
		push_to_a(stacks);
		move("ra\n", "rra\n", stacks->smallest, stacks);
	}
}

//push everything to b except for the ordered part // need to call separate order before this!
void push_to_b(t_stacks *stacks, int flag) 
{
	int order;
	int i;
	int size;

	order = find_order(stacks);
	size = stacks->a.size;
	if (order <= size/2)
		i = movement(stacks->a, order);
	else
		size = size - movement(stacks->a, order);
	while (i < size - 1)
	{
		if (stacks->a.arr[0] != order && (stacks->a.arr[0] > stacks->middle) * flag < 0)
			pick("pb\n", stacks);
		i++;
	}
}

int	find_order(t_stacks *stacks)
{
	int	i;
	int order;
	int biggest_order;
	int	order_number;

	i = 0;
	biggest_order = 0;
	order_number= stacks->a.arr[0];
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

int seperate_order(t_stacks *stacks) //put away the ordered part, devide on ra and rra, returns amount of movements
{
	int order;

	order = find_order(stacks);
	move("ra\n", "rra\n", order, stacks);
	return (find_order(stacks));
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