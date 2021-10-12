#include "../inc/push_swap.h"

//move!
void move(char *smaller,char *bigger, int index, t_stacks *stacks)
{
	t_stack stack;

	if (smaller[1] == 'a')
		stack = stacks->a;
	else
		stack = stacks->b;
	if (index >= stack.size/2)
		while(index--)
			pick(bigger, stacks);
	else
	{
		index = stack.size - index;
		while(index--)
			pick(smaller, stacks);
	}
}

int fillable(t_stack stack, char **argv)
{
	int i = 0;

	while (*argv)
	{
		if(!ft_isnbr(*argv))
			return (0);
		stack.arr[i++] = ft_atoi(*argv++);
	}
	i = 1;
	while (stack.size-- > 1)
		if (*(stack.arr)++ == stack.arr[i++])
			return (0);
	return (1);
}

void	init_stack(t_stack *stack, int alloc, int size)
{
	stack->arr = malloc(sizeof(int) * alloc);
	stack->size = size;
}

t_stacks *new_stacks(int size)
{
	t_stacks *stacks = malloc(sizeof(t_stacks));
	init_stack(&stacks->a, size, size);
    init_stack(&stacks->b, size, 0);
	return(stacks);
}

int main(int argc, char *argv[])
{
	--argc;

	t_stacks *stacks = new_stacks(argc);
	// what about argc == 0 ? later.
	if(!fillable(stacks->a, &argv[1]))
		return(write(1, "Error", 5));
	
	/*** ^ T E S T ^ ***/
	fivesort(stacks);
	display_stack(stacks->a);
	printf("is stack_a sorted? %d\n", is_sorted(stacks));
}