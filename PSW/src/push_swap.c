#include "../inc/push_swap.h"
#include "../libft/main_libft/libft.h"

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
		if(!ft_isnbr(*args))
			return (0);
		stack->arr[i++] = ft_atoi(*args++);
	}
	i = 1;
	while (stack.size-- > 1)
		if (*(stack.arr)++ == stacks.arr[i++])
			return (0);
	return (1);
}

t_stack *new_stacks(int size)
{
	t_stacks *stacks = malloc(sizeof(t_stacks));
	stacks->a.size = size;
	stacks->b.size = 0;
	return (stacks);
}

int main(int argc, char *argv[])
{
	--argc;
    t_stack *stacks = new_stack(argc);
	// what about argc == 0 ? later.
	if(!fillable(stacks->a, &argv[1]))
		return(write(1, "Error", 5));
	
	/*** ^ T E S T ^ ***/
	printf("is stack_a sorted? %d\n", is_sorted(a));
}