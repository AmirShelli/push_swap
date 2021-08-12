#include "../inc/push_swap.h"

int fill(t_stack *a, char **args)
{
	int i;

	while(*args++)
	{
		if(is_nbr(*args))
			(*a).arr[i++] = ft_atoi(*args);
		else
			return (0);
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

int main(int argc, char **argv[])
{
    t_stack *a = new_stack(argc);
    t_stack *b = new_stack(0);

	// what about argc == 0 ?
	if(!fillable(a, &argv[1]))
		return(write(1, "Error", 5));
	
}