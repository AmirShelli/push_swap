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

void fivesort(t_stack *a, t_stack *b)
{
	int min, max;

	min = smallest(a);
	max = biggest(a);
	printf("you max %d \n", max);
	while (!(is_in(min, b) && is_in(max, b)))
	{
		while (a->arr[0] == min || a->arr[0] == max)
			pick("pb", a, b);
		pick("rra", a, b);
	}
	smallsort(a);
	while(b->size)
	{	
		pick("pa", a, b);
		if (a->arr[0] == max)
			pick("ra", a, b);
	}
}
