#include "../../inc/push_swap.h"

t_push_swap	*init(int size)
{
	t_push_swap	*stacks;

	stacks = ft_calloc(1, sizeof(t_push_swap));
	stacks->size_a = size;
	return (stacks);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	auto_move(char *which, int flag, int *movements, t_push_swap *stacks)
{
	char	*cmd;

	if (!flag)
	{	
		cmd = ft_strjoin("rr", which);
		while ((*movements)--)
			pick(cmd, stacks);
	}
	else
	{
		cmd = ft_strjoin("r", which);
		while ((*movements)--)
			pick(cmd, stacks);
	}
	free(cmd);
}

void	free_stack(t_stack *stack)
{
	t_stack	*aux;

	while (stack)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
}

int	ultimate_free(t_push_swap *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
	return (1);
}
