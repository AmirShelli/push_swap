#include "../../inc/push_swap.h"

void	solve(t_push_swap *stacks)
{
	(void)stacks;
}

int markup(t_stack *stack)
{	
	int	num_in_sequence;

	num_in_sequence = 1;
	while(stack->next)
	{
		if(stack->num < stack->next->num)
		{	
			stack->keep = 1;
			stack->next->keep = 1;
			num_in_sequence++;
		}
		else
			stack->keep = 0;
		stack = stack->next;
	}
	return (num_in_sequence);
}

void push_to_b(t_push_swap *stacks)
{
	t_stack *temp;
	int size;
	
	size = stacks->size_a;
	while()
}

