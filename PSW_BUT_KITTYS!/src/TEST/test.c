#include "../../inc/push_swap.h"
#include <stdio.h>
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