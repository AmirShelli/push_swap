#include "../../inc/push_swap.h"

void	solve(t_push_swap *stacks)
{
	(void)stacks;
	auto_move("ra\n", "rra\n",get_index(stacks->a, stacks->smallest), stacks);
}

/*
 * separates the ordered sequence locking it down
 * pushes what's bigger than the mediane to b
 * then pushes the rest to b
 */
int	best_seq(t_stack *stack)
{
	int seq;
	int longest_seq;
	int	seq_number;

	seq = 0;
	longest_seq = seq;
	seq_number = stack->num;
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			seq++;
		else
		{	
			if (longest_seq < seq)
			{	
				longest_seq = seq;
				seq_number = stack->num;
			}
			seq = 0;
		}
	}
	return (seq_number);
}

int markup(t_stack *stack)
{	
	int	amount;
	int best;

	amount = 1;
	best = best_seq(stack);
	while(stack->next)
	{
		if(stack->num == best)
		{
			while(stack->next && stack->num < stack->next->num)
			{	
				stack->keep = 1;
				stack = stack->next;
				amount++;
			}
			stack->keep = 1;
		}
		else
			stack->keep = 0;
		stack = stack->next;
	}
	return (amount);
}

void push_to_b(t_push_swap *stacks)
{
	int size;
	int seq_length;
	
	seq_length = markup(stacks->a);
	size = stacks->size_a - seq_length;
	while(size--)
	{
		if(stacks->a->num > stacks->middle && !stacks->a->keep)
			pick("pb\n", stacks);
		else if (stacks->a->keep)
			pick("rra\n", stacks);
	}
	size = stacks->size_a - seq_length;
	while(size--)
		if(stacks->a->num < stacks->middle && !stacks->a->keep)
			pick("pb\n", stacks);
}

/*
 * finds the optimal number to push to a first
 * does the magic to push it back to a
 */
int index_a(t_push_swap *stacks, int index_b)
{
	int index;
	int num;

	index = 0;
	num = get_value(stacks->b, index_b)->num;
	while (index < stacks->size_a - 1 && num > get_value(stacks->a, index)->num)
		index++;
	return (index);
}

int moves(int size, int index)
{
		if(index < size/2)
			return(index);
		else
			return ((size - index));
}

int best_index(t_push_swap *stacks)
{
	int index_b;
	int num_moves;
	int best_moves;
	int best_index;

	index_b = 0;
	best_index = index_b;
	best_moves = moves(stacks->size_b, index_b) + moves(stacks->size_a, index_a(stacks, index_b));
	while (index_b < stacks->size_b)
	{
		num_moves = moves(stacks->size_b, index_b) + moves(stacks->size_a, index_a(stacks, index_b));
		if(best_moves >= num_moves)
		{	
			best_moves = num_moves;
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}

void push_to_a(t_push_swap *stacks)
{
	int		index[2];

	while (stacks->size_b)
	{
		index[0] = index_a(stacks, best_index(stacks));
		index[1] = best_index(stacks);
		if (index[0] >= stacks->size_b/2 && index[1] >= stacks->size_b/2)
			while(index[0]-- && index[1]--)
				pick("rrr\n", stacks);
		else if (index[0] < stacks->size_a/2 && index[1] < stacks->size_b/2)
		{
			index[0] = stacks->size_a - index[0];
			index[1] = stacks->size_b - index[1];
			while(index[0]-- && index[1]--)
				pick("rr\n", stacks);
		}
		if(index[0])
			auto_move("ra\n", "rra\n", index[0], stacks);
		if(index[1])
			auto_move("rb\n", "rrb\n", index[1], stacks);
		pick("pa\n", stacks);
	}
}