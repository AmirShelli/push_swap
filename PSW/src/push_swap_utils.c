#include "../inc/push_swap.h"

//needed for pa/pb
void move_forward(t_stack *a, int from)
{
	if((a->size - 1 >= from + 1))
		move_forward(a, from + 1);
	a->arr[from + 1] = a->arr[from];
}

void	move_backward(t_stack *a, int from)
{
	a->arr[from - 1] = a->arr[from];
	if ((a->size - 1) >= from)
		move_backward(a, from + 1);
}

//push everything to b except for the ordered part
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
