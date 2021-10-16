#include "../inc/push_swap.h"

void	print_stack(t_stack *stack, char st) //todo remove
{
	int index = 0;
	printf("%c: ", st);
	if (!stack)
	{
		printf("\n");
		return ;
	}
	while (stack->next)
	{
		printf("[%d]{ %d }| ", index, stack->num);
		stack = stack->next;
		index++;
	}
	printf("[%d]{ %d }|\n", index, stack->num);
}

int	get_min_max(t_stack *stack, int min_max)
{
	int		comp;

	if (!min_max)
		comp = INT_MAX;
	else
		comp = INT_MIN;
	while (stack)
	{
		if ((!min_max && stack->num <= comp) || (min_max && stack->num >= comp))
			comp = stack->num;
		stack = stack->next;
	}
	return (comp);
}
