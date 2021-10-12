#include "../inc/push_swap.h" 

void bubble_sort(t_stack *a, t_stack *b)
{
	int i;

	while (!is_sorted(a))
	{
		i = 0;
		while (i < a->size - 1)
		{	
			if (a->arr[i] > a->arr[i + 1])
			{	
				pb_until(i, a, b);
				pick("sa", a, b);
			}
			i++;
		}
		pa_all(a, b);
	}
}

// I hate this but ok.
void smallsort(t_stack *a)
{
	int	*arr;

	
	arr = a->arr;
	if (a->size > 2)
	{
		if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
			pick("sa", a, NULL);
		else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		{
			pick("sa", a, NULL);
			pick("rra", a, NULL);
		}
		else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
			pick("ra", a, NULL);
		else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
		{
			pick("sa", a, NULL);
			pick("ra", a, NULL);
		}
		else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
			pick("rra", a, NULL);
	}
	else if (arr[0] > arr[1])
		pick("sa", a, NULL);
}

void fivesort(t_stacks *stacks)
{
	int min, max;

	min = smallest(stacks->a);
	max = biggest(stacks->a);
	printf("you max %d \n", max);
	while (!(is_in(min, stacks->b) && is_in(max, stacks->b)))
	{
		if (stacks->a->arr[0] == min || stacks->a->arr[0] == max)
			pick("pb", stacks);
		else
			pick("rra", stacks);
	}
	smallsort(stacks->a);
	while(stacks->b->size)
	{	
		pick("pa", stacks);
		if (stacks->a->arr[0] == max)
			pick("ra", stacks);
	}
}

void insertionsort(t_stack *a, t_stack *b)
{
	
}
