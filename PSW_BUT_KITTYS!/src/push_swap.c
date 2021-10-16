#include "../inc/push_swap.h"

t_push_swap	*init(int size)
{
	t_push_swap	*stacks;

	stacks = ft_calloc(1, sizeof(t_push_swap));
	stacks->size_a = size;
	return (stacks);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*stacks;

	if (argc == 1)
		return (1);
	stacks = init(--argc);
	if (!is_valid(stacks, ++argv, argc))
	{
		ultimate_free(stacks);
		write(1, "Error\n", 6);
		return (1);
	}
	// if (is_sorted(stacks->a))
	// {
	// 	ultimate_free(stacks);
	// 	return (0);
	// }
	// else
	// 	solve(stacks);
	int index_b;
	int index;
	print_stack(stacks->a, 'a');
	print_stack(stacks->b, 'b');
	printf("- best sequence number: %d\n *** \n", best_seq(stacks->a));
	printf("- sequence length: %d\n *** \n", markup(stacks->a));
	push_to_b(stacks);
	print_stack(stacks->a, 'a');
	print_stack(stacks->b, 'b');
	printf("- middle is: %d\n *** \n", stacks->middle);
	index_b = 0;
	index = index_a(stacks, index_b);
	printf("- index_a: %d\n *** \n", index);
	printf("- moves for index_b: %d\n *** \n", moves(stacks->size_b, index_b));
	printf("- moves in both stacks: %d\n *** \n", 
	moves(stacks->size_b, index_b) + 
	moves(stacks->size_a, index));
	printf("- best index: %d\n *** \n", best_index(stacks));
	push_to_a(stacks); //index_a() is returning the wrong value
	//duplicates and is_int needed to finish (any error handling in general in is_valid)
}
