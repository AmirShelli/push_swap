#include "../../inc/push_swap.h"

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
			if (!seq++)
				seq_number = stack->num;
		if (!stack->next || stack->num > stack->next->num)
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

static void	chose_cmd(char **bigger,
		char **smaller, int size, t_push_swap *stacks)
{
	if (size > stacks->size_a / 2)
	{
		*bigger = "rra\n";
		*smaller = "ra\n";
	}
	else
	{
		*bigger = "ra\n";
		*smaller = "rra\n";
	}
}

void	push_to_b(t_push_swap *stacks)
{
	int		size;
	int		aux;
	char	*bigger;
	char	*smaller;

	size = markup(stacks->a);
	chose_cmd(&bigger, &smaller, size, stacks);
	aux = stacks->size_a;
	while (aux--)
	{
		if (stacks->a->num >= stacks->middle && !stacks->a->keep)
			pick("pb\n", stacks);
		else
			if (!is_sorted(stacks->a))
				pick(bigger, stacks);
	}
	while (stacks->size_a - size)
	{
		if (!stacks->a->keep)
			pick("pb\n", stacks);
		else
			if (!is_sorted(stacks->a))
				pick(smaller, stacks);
	}
}
