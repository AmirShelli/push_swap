#include "../inc/push_swap.h"

void	run(t_stack *a, t_stack *b, char *cmd, void (*func)(t_stack *));

void pick(char *cmd, t_stack *a, t_stack *b)
{
	if (cmd[0] == 's')
		run(a, b, cmd, &swap);
	else if (cmd[0] == 'r' && !cmd[2])
		run(a, b, cmd, &rotate);
	else if (cmd[0] == 'r' && cmd[2])
		run(a, b, &cmd[1], &reverse);
	else if (cmd[0] == 'p')
	{	
		if (cmd[1] == 'a')
			push(a, b);
		else if (cmd[1] == 'b')
			push(b, a);
	}
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
}

void	run(t_stack *a, t_stack *b, char *cmd, void (*func)(t_stack *))
{
	if (cmd[1] == 'a')
		func(a);
	else if (cmd[1] == 'b')
		func(b);
	else
	{
		func(a);
		func(b);
	}
}

