#include "../../inc/push_swap.h"

void	smallsort(t_push_swap *stacks, int size)
{
	int	first;
	int	second;
	int	third;

	if (size == 2 && stacks->a->num > stacks->a->next->num)
		pick("sa", stacks);
	if (!is_sorted(stacks->a))
	{
		first = stacks->a->num;
		second = stacks->a->next->num;
		third = stacks->a->next->next->num;
		if (first < second && second > third && third < first)
			pick("rra", stacks);
		else if (first > second && second < third && third < first)
			pick("ra", stacks);
		else if (first > second || (second > third && third > first))
		{	
			pick("sa", stacks);
			if (first < second)
				pick("ra", stacks);
			else if (third < first)
				pick("rra", stacks);
		}
	}
}

int	biggest(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

void	fivesort(t_push_swap *stacks)
{
	int	min;
	int	max;

	min = stacks->smallest;
	max = biggest(stacks->a);
	while (stacks->size_b != 2)
	{
		if (stacks->a->num != min && stacks->a->num != max)
			pick("ra", stacks);
		else
			pick("pb", stacks);
	}
	smallsort(stacks, stacks->size_a);
	while (stacks->size_b)
	{
		pick("pa", stacks);
		if (stacks->a->num == max)
			pick("ra", stacks);
	}
}
