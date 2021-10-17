#include "../inc/push_swap.h"

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
	if (!is_sorted(stacks->a) && stacks->size_a > 1)
		solve(stacks);
	// ultimate_free(stacks);
	#include <stdio.h>
	// print_stack(stacks->a, 'a');
	// print_stack(stacks->b, 'b');
	// printf("- best sequence number: %d\n *** \n", best_seq(stacks->a));
	// printf("- sequence length: %d\n *** \n", markup(stacks->a));
	// push_to_b(stacks);
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
	// push_to_a(stacks);
	// print_stack(stacks->a, 'a');
	// print_stack(stacks->b, 'b');
	// auto_move("ra", "rra", get_index(stacks->a, stacks->smallest), stacks);
	// print_stack(stacks->a, 'a');
	// printf("%s", is_sorted(stacks->a) ? "sorted!\n" : "uh-oh.");
	//gotta test it and fix the remaining norme errors check checker, check error management, otherwise works
}
