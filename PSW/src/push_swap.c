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
		return (0);
	}
	if (!is_sorted(stacks->a) && stacks->size_a > 1)
		solve(stacks);
	ultimate_free(stacks);
	return (1);
}
