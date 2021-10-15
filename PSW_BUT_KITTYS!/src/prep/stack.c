#include "../../inc/push_swap.h"

t_stack	*new_stack(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->num = num;
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}

void	stack_push_front(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	new->next = *stack;
	new->previous = NULL;
	if (*stack)
		(*stack)->previous = new;
	*stack = new;
}

t_stack	*stack_last_element(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*get_value(t_stack *stack, int index)
{
	int count;

	count = 0;
	while (count++ != index)
		stack = stack->next;
	return (stack);
}

int get_index(t_stack *stack, int value)
{
	int index;

	index = 0;
	while(stack->num != value)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}
