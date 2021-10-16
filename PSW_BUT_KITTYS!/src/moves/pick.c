#include "../../inc/push_swap.h"

static void	run(t_push_swap *stacks, char *cmd, void (*func)(t_stack **))
{
	if (cmd[1] == 'a')
		func(&stacks->a);
	else if (cmd[1] == 'b')
		func(&stacks->b);
	else
	{
		func(&stacks->a);
		func(&stacks->b);
	}
}

void	pick(char *cmd, t_push_swap *stacks)
{
	if (cmd[0] == 's')
		run(stacks, cmd, &swap);
	else if (cmd[0] == 'r' && !cmd[2])
		run(stacks, cmd, &rotate);
	else if (cmd[0] == 'r' && cmd[2])
		run(stacks, &cmd[1], &reverse);
	else if (cmd[0] == 'p')
	{
		if (cmd[1] == 'b')
		{
			push(&stacks->a, &stacks->b);
			stacks->size_a--;
			stacks->size_b++;
		}
		else if (cmd[1] == 'a')
		{
			push(&stacks->b, &stacks->a);
			stacks->size_a++;
			stacks->size_b--;
		}
	}
	if (cmd[ft_strlen(cmd) - 1] != '\n')
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
	}
}
