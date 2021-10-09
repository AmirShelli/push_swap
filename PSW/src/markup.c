#include "../inc/push_swap.h"

//push_to_be

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

//best_index
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

//move!

void push_to_a(t_stacks stacks)
{
	int		*index;
	char	*cmd;

	while (stacks->b.size)
	{
		index[0] = index_a(stacks, best_index(stacks));
		index[1] = index_b(stacks, best_index(stacks));
		while(index_a || index_b)
		{
			if(index[0] && index[1])
			{	
				if (index >= stack.size/2)
					cmd = bigger
				else
				{
					cmd = smaller;
					index = stack.size - index
				}
				while(index--)
					pick(cmd, stacks);
			}
			else if(index[0])
				move("ra", "rra", index[0], stacks)
			else
				move("rb", "rrb", index[1], stacks)
		}
		pick("pa", stacks);
	}
}

void move(char *smaller,char *bigger, int *index, t_stacks *stacks)
{
	t_stack stack;
	char	*cmd;

	if (index[0]) //careful!!! rra or ra??
		stack = stacks->a;
	else if (index)
		stack = stacks->b;
	if (index >= stack.size/2)
		cmd = bigger
	else
	{
		cmd = smaller;
		index = stack.size - index
	}
	while(index--)
		pick(cmd, stacks);
	
}