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
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		pick("sa", a, NULL);
	else if (arr[0] > arr[1] && arr[1] > arr[2])
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

void fivesort(t_stack a, t_stack b)
