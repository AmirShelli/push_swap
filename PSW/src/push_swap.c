#include "../inc/push_swap.h"

int fillable(t_stack *a, char **args)
{
	int i = 0;

	while(*args)
	{
		if(!ft_isnbr(*args))
			return (0);
		puts(*args);
		a->arr[i++] = ft_atoi(*args++);
	}
	return (1);
}

t_stack *new_stack(int argc)
{
	t_stack *a = malloc(sizeof(t_stack));
	a->arr = malloc(sizeof(int) * argc);
	a->size = argc;
	return (a);
}

void display_stack(t_stack *a) // TEST
{
	int size = a->size;
	int i = 0;

	while (i < size)
	{
		printf("%d element: %d\n", i, a->arr[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
    t_stack *a = new_stack(--argc);
    // t_stack *b = new_stack(0);

	// what about argc == 0 ?
	if(!fillable(a, &argv[1]))
		return(write(1, "Error", 5));
	display_stack(a);
	
}