void display_stack(t_stack *stack)
{
	int size = stack->size;
	int i = 0;

	while (i < size)
	{
		printf("%d element: %d\n", i + 1, stack->arr[i]);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	int size = stack->size;
	int i = 0;

	while (i < size - 1)
	{	
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*** ^ T E S T ^ ***/