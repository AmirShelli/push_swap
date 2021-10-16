#include "../../inc/push_swap.h"
#include <stdio.h>

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
	int best;

	seq = 0;
	longest_seq = seq;
	seq_number = stack->num;
	while (stack)
	{
		if (stack->next && stack->num < stack->next->num)
		{	
			if(!seq++)
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

int markup(t_stack *stack)
{	
	int	amount;
	int best;

	amount = 1;
	best = best_seq(stack);
	while(stack)
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

void push_to_b(t_push_swap *stacks)
{
	int size;
	int aux;
	char *bigger;
	char *smaller;

	size = markup(stacks->a);
	if(size > stacks->size_a/2)
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
	while(aux--)
	{
		if(stacks->a->num >= stacks->middle && !stacks->a->keep)
			pick("pb", stacks);
		else
		{	
			if(!is_sorted(stacks->a))
				pick(bigger, stacks);
		}
	} 
	while(stacks->size_a - size)
	{	
		if(!stacks->a->keep)
			pick("pb", stacks);
		else
		{	
			if(!is_sorted(stacks->a))
				pick(smaller, stacks);
		}
	}
}

/*
 * finds the optimal number to push to a first
 * does the magic to push it back to a
 */
int index_a(t_push_swap *stacks, int index_b)
{
	int value;
	int sup_val;
	int index;
	int flag;

	value = get_value(stacks->b, index_b)->num; //put outside of func
	flag = 0;
	sup_val = get_value(stacks->a, 0)->num;
	index = 0;
	while(index < stacks->size_a)
	{
		if(value > get_value(stacks->a, index)->num)
		{
			if(!flag)
				sup_val = get_value(stacks->a, index)->num;
			flag = 1;
			if(sup_val < get_value(stacks->a, index)->num)
				sup_val = get_value(stacks->a, index)->num;
		}
		if(!flag)
			if(sup_val > get_value(stacks->a, index)->num)
				sup_val = get_value(stacks->a, index)->num;
		index++;
	}
	return (get_index(stacks->a,sup_val) + flag);
}

int moves(int size, int index)
{
		if(index <= size/2)
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
	int		aux[2];

	while (stacks->size_b)
	{
		// print_stack(stacks->a, 'a');
		// print_stack(stacks->b, 'b');
		index[0] = index_a(stacks, best_index(stacks));
		index[1] = best_index(stacks);
		// printf("a: [%d] b: [%d]\n", index[0], index[1]);
		if (index[0] <= stacks->size_a/2 && index[1] <= stacks->size_b/2)
			while(index[0] && index[1])
			{	
				pick("rr", stacks);
				index[0]--;
				index[1]--;
			}
		else if (index[0] > stacks->size_a/2 && index[1] > stacks->size_b/2)
		{
			aux[0] = stacks->size_a - index[0];
			aux[1] = stacks->size_b - index[1];
			while(aux[0] && aux[1])
			{	
				pick("rrr", stacks);
				--aux[0];
				index[0]++;
				if (index[0] == stacks->size_a)
					index[0] = 0;
				--aux[1];
				index[1]++;
				if (index[1] == stacks->size_b)
					index[1] = 0;
			}
		}
		if(index[0])
			auto_move("ra", "rra", index[0], stacks);
		if(index[1])
			auto_move("rb", "rrb", index[1], stacks);
		pick("pa", stacks);
	}
}
