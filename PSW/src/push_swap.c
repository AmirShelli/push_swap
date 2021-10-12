#include "../inc/push_swap.h"
#include "../libft/main_libft/libft.h"

// Make a structure of stacks, 
// 'cause this looks bad tho.

void display_stack(t_stack stack)
{
	int size = stack.size;
	int i = 0;

	while (i < size)
	{
		printf("%d element: %d\n", i + 1, stack.arr[i]);
		i++;
	}
}
/*** ^ T E S T ^ ***/

int fillable(int *arr, char **args)
{
	int i = 0;

	while(*args)
	{
		if(!ft_isnbr(*args))
			return (0);
		arr[i++] = ft_atoi(*args++);
	}
	return (1);
}

void	init_stack(t_stack *stack, int alloc, int size)
{
	stack->arr = malloc(sizeof(int) * alloc);
	stack->size = size;
	return (stack);
}

t_stacks *new_stacks(int size, char *argv[])
{
	t_stacks *stacks = malloc(sizeof(t_stacks));
	init_stack(&stacks->a, size, size);
    init_stack(&stacks->b, size, 0);
}

int main(int argc, char *argv[])
{
	--argc;

	t_stacks *stacks = new_stacks(argc);
	// what about argc == 0 ? later.
	if(!fillable(stacks->a.arr, &argv[1]))
		return(write(1, "Error", 5));
	
	/*** ^ T E S T ^ ***/
	fivesort(stacks);
	display_stack(stacks->a);
	printf("is stack_a sorted? %d\n", is_sorted(stacks->a));
}