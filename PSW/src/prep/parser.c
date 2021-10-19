#include "../../inc/push_swap.h"

static void	swap_numbers(int *first, int *second)
{
	int	aux;

	aux = *first;
	*first = *second;
	*second = aux;
}

static void	sort(int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
				swap_numbers(&sorted[j], &sorted[j + 1]);
			j++;
		}
		i++;
	}
}

static void	set_values(t_push_swap *stacks)
{
	int		i;
	t_stack	*a;
	int		sorted[stacks->size_a];

	i = -1;
	a = stacks->a;
	while (a)
	{
		sorted[++i] = a->num;
		a = a->next;
	}
	sort(sorted, stacks->size_a);
	stacks->middle = sorted[stacks->size_a / 2];
	stacks->smallest = sorted[0];
}

int	duplicates(t_stack *stack)
{
	t_stack	*aux;

	while (stack->next)
	{
		aux = stack->next;
		while (aux)
		{
			if (stack->num == aux->num)
				return (1);
			aux = aux->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	is_valid(t_push_swap *stacks, char **argv, int argc)
{
	t_stack	*aux;

	while (argc-- > 0)
	{
		if (!ft_isnbr(argv[argc]) || !ft_isint(argv[argc]))
			return (0);
		aux = new_stack(atoi(argv[argc]));
		if (!aux)
			return (0);
		stack_push_front(&stacks->a, aux);
	}
	if (duplicates(stacks->a))
		return (0);
	set_values(stacks);
	return (1);
}
