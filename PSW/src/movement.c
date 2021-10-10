#include "../inc/push_swap.h"



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
void move(char *smaller,char *bigger, int index, t_stacks *stacks)
{
	t_stack stack;

	if (smaller[1] == 'a')
		stack = stacks->a;
	else
		stack = stacks->b;
	if (index >= stack.size/2)
		while(index--)
			pick(bigger, stacks);
	else
	{
		index = stack.size - index;
		while(index--)
			pick(smaller, stacks);
	}
}

