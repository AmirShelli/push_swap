#include "../inc/push_swap.h"
#include "../libft/main_libft/libft.h"

// Make a structure of stacks, 
// 'cause this looks bad tho.

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
/*** ^ T E S T ^ ***/

int fillable(t_stack *stack, char **args)
{
	int i = 0;

	while(*args)
	{
		if(!ft_isnbr(*args))
			return (0);
		stack->arr[i++] = ft_atoi(*args++);
	}
	return (1);
}

t_stack *new_stack(int alloc, int size)
{
	t_stack *stack = malloc(sizeof(t_stack));
	stack->arr = malloc(sizeof(int) * alloc);
	stack->size = size;
	return (stack);
}

int main(int argc, char *argv[])
{
	--argc;
    t_stack *a = new_stack(argc, argc);
    // t_stack *b = new_stack(argc, 0);

	// what about argc == 0 ? later.
	if(!fillable(a, &argv[1]))
		return(write(1, "Error", 5));


	/*** ^ T E S T ^ ***/
	fivesort(a);
	display_stack(a);
	printf("is stack_a sorted? %d\n", is_sorted(a));
}