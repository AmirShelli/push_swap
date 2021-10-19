#include "../../inc/push_swap.h"

/*
 * finds the optimal number to push to a first
 * does the magic to push it back to a
 */
int	index_a(t_push_swap *stacks, int index_b)
{
	int	value;
	int	sup_val;
	int	index;
	int	flag;

	value = get_value(stacks->b, index_b)->num;
	flag = 0;
	sup_val = get_value(stacks->a, 0)->num;
	index = 0;
	while (index < stacks->size_a)
	{
		if (value > get_value(stacks->a, index)->num)
		{
			if (!flag)
				sup_val = get_value(stacks->a, index)->num;
			flag = 1;
			if (sup_val < get_value(stacks->a, index)->num)
				sup_val = get_value(stacks->a, index)->num;
		}
		if (!flag)
			if (sup_val > get_value(stacks->a, index)->num)
				sup_val = get_value(stacks->a, index)->num;
		index++;
	}
	return (get_index(stacks->a, sup_val) + flag);
}

int	moves(int size, int index, int *flag)
{
	if (index <= size / 2)
	{	
		*flag = 1;
		return (index);
	}
	else
	{
		*flag = 0;
		return (size - index);
	}
}

int	best_index(t_push_swap *stacks)
{
	int	index_b;
	int	num_moves;
	int	best_moves;
	int	best_index;
	int	flag;

	index_b = 0;
	best_index = index_b;
	best_moves = moves(stacks->size_b, index_b, &flag)
		+ moves(stacks->size_a, index_a(stacks, index_b), &flag);
	while (index_b < stacks->size_b)
	{
		num_moves = moves(stacks->size_b, index_b, &flag)
			+ moves(stacks->size_a, index_a(stacks, index_b), &flag);
		if (best_moves >= num_moves)
		{
			best_moves = num_moves;
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}

int	change_index(int *a, int *b)
{
	int	movements;

	movements = 0;
	if (*a <= *b)
	{	
		movements = *a;
		*b = *b - *a;
		*a = 0;
		return (movements);
	}
	else if (*a > *b)
	{	
		movements = *b;
		*a = *a - *b;
		*b = 0;
		return (movements);
	}
	return (movements);
}

void	push_to_a(t_push_swap *stacks)
{
	int		index[2];
	int		flag[2];
	int		both;

	while (stacks->size_b)
	{
		index[0] = moves(stacks->size_a,
				index_a(stacks, best_index(stacks)), &flag[0]);
		index[1] = moves(stacks->size_b, (best_index(stacks)), &flag[1]);
		if (index[0] && index[1] && !(flag[0] ^ flag[1]))
		{
			both = change_index(&index[0], &index[1]);
			auto_move("r\n", flag[0], &both, stacks);
		}
		if (index[0])
			auto_move("a\n", flag[0], &index[0], stacks);
		if (index[1])
			auto_move("b\n", flag[1], &index[1], stacks);
		pick("pa\n", stacks);
	}
}
