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
	
	// print_stack(stacks->a, 'a');
	// print_stack(stacks->b, 'b');
	// printf("- best sequence number: %d\n *** \n", best_seq(stacks->a));
	// printf("- sequence length: %d\n *** \n", markup(stacks->a));
	push_to_b(stacks);
	// print_stack(stacks->a, 'a');
	// print_stack(stacks->b, 'b');
	// printf("- middle is: %d\n *** \n", stacks->middle);
	// int index_b = 1;
	// int index = index_a(stacks, index_b);
	// printf("- index_a when index_b is %d: %d\n *** \n",index_b, index);
	// printf("- moves for index_b: %d\n *** \n", moves(stacks->size_b, index_b));
	// printf("- moves in both stacks: %d\n *** \n", 
	// moves(stacks->size_b, index_b) + 
	// moves(stacks->size_a, index));
	// printf("- best index: %d\n *** \n", best_index(stacks));
	push_to_a(stacks);
	// print_stack(stacks->a, 'a');
	// print_stack(stacks->b, 'b');
	auto_move("ra", "rra", get_index(stacks->a, stacks->smallest), stacks);
	// print_stack(stacks->a, 'a');
	if(is_sorted(stacks->a))
		puts("congrats, it's sorted!\n");
	else
		puts("F");
	//duplicates and is_int needed to finish (any error handling in general in is_valid)
	//isnbr has to check for negative numbers
	//in solve has to include smolsort and fivesort (I have them in the old ver)
}
