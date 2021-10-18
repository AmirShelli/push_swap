#include "../../inc/push_swap.h"

void	solve(t_push_swap *stacks)
{
	int	flag;
	int	smallest;

	if (stacks->size_a <= 3)
		smallsort(stacks, stacks->size_a);
	else if (stacks->size_a <= 5)
		fivesort(stacks);
	else
	{
		push_to_b(stacks);
		push_to_a(stacks);
		smallest = moves(stacks->size_a,
							get_index(stacks->a, stacks->smallest), &flag);
		auto_move("a", flag, &smallest, stacks);
	}
	printf("%s", is_sorted(stacks->a) ? "sorted!\n" : "F\n");
	print_stack(stacks->a, 'a');
	print_stack(stacks->b, 'b');
}

/*
 * separates the ordered sequence locking it down
 * pushes what's bigger than the mediane to b
 * then pushes the rest to b
 */
int	best_seq(t_stack *stack)
{
	int	seq;
	int	longest_seq;
	int	seq_number;
	int	best;

	seq = 0;
	longest_seq = seq;
	seq_number = stack->num;
	while (stack)
	{
		if (stack->next && stack->num < stack->next->num)
		{
			if (!seq++)
				seq_number = stack->num;
		}
		else
		{
			if (longest_seq < seq)
			{
				best = seq_number;
				longest_seq = seq;
			}
			seq = 0;
		}
		stack = stack->next;
	}
	return (best);
}

int	markup(t_stack *stack)
{
	int	amount;
	int	best;

	amount = 1;
	best = best_seq(stack);
	while (stack)
	{
		if (stack->num == best)
		{
			while (stack->next && stack->num < stack->next->num)
			{
				stack->keep = 1;
				stack = stack->next;
				amount++;
			}
			stack->keep = 1;
			stack = stack->next;
		}
		else
		{
			stack->keep = 0;
			stack = stack->next;
		}
	}
	return (amount);
}

void	push_to_b(t_push_swap *stacks)
{
	int		size;
	int		aux;
	char	*bigger;
	char	*smaller;

	size = markup(stacks->a);
	if (size > stacks->size_a / 2)
	{
		bigger = "rra";
		smaller = "ra";
	}
	else
	{
		bigger = "ra";
		smaller = "rra";
	}
	aux = stacks->size_a;
	while (aux--)
	{
		if (stacks->a->num >= stacks->middle && !stacks->a->keep)
			pick("pb", stacks);
		else
			if (!is_sorted(stacks->a))
				pick(bigger, stacks);
	}
	while (stacks->size_a - size)
	{
		if (!stacks->a->keep)
			pick("pb", stacks);
		else
			if (!is_sorted(stacks->a))
				pick(smaller, stacks);
	}
}

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


void	push_to_a(t_push_swap *stacks)
{
	int		index[2];
	int		flag[2];

	while (stacks->size_b)
	{
		index[0] = moves(stacks->size_a, index_a(stacks, best_index(stacks)), &flag[0]);
		index[1] = moves(stacks->size_b, (best_index(stacks)), &flag[1]);
		if (flag[0] && flag[1])
		{
			while (index[0] && index[1])
			{
				pick("rr", stacks);
				index[0]--;
				index[1]--;
			}
		}
		else if (!flag[0] && !flag[1])
		{
			while (index[0] && index[1])
			{	
				pick("rrr", stacks);
				index[0]--;
				index[1]--;
			}
		}
		if (index[0])
			auto_move("a", flag[0], &index[0], stacks);
		if (index[1])
			auto_move("b", flag[1], &index[1], stacks);
		pick("pa", stacks);
	}
}
