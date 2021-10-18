#include "../inc/push_swap.h"

#include <stdio.h>
void	print_stack(t_stack *stack, char st) //todo remove
{
	int index = 0;
	printf("%c: ", st);
	if (!stack)
	{
		printf("\n");
		return ;
	}
	while (stack->next)
	{
		printf("[%d]{ %d }| ", index, stack->num);
		stack = stack->next;
		index++;
	}
	printf("[%d]{ %d }|\n", index, stack->num);
}

int	check(char *cmd, t_push_swap *stacks)
{
	if (cmd[0] == 's')
		return (run(stacks, cmd, &swap));
	else if (cmd[0] == 'r' && !cmd[3])
		return (run(stacks, cmd, &rotate));
	else if (cmd[0] == 'r' && cmd[3])
		return (run(stacks, &cmd[1], &reverse));
	else if (cmd[0] == 'p')
	{
		if (cmd[1] == 'b')
		{
			push(&stacks->a, &stacks->b);
			stacks->size_a--;
			stacks->size_b++;
			return (1);
		}
		else if (cmd[1] == 'a')
		{
			push(&stacks->b, &stacks->a);
			stacks->size_a++;
			stacks->size_b--;
			return (1);
		}
	}
	return (0);
}

int	get_next_line_ps(char **line)
{
	int		i;
	char	ch;
	char	*buffer;
	int		rd;

	i = 0;
	buffer = malloc(10);
	*line = buffer;
	rd = 1;
	ch = '0';
	while (rd > 0 && ch != '\n')
	{
		rd = read(0, &ch, 1);
		buffer[i++] = ch;
	}
	buffer[i + 1] = '\0';
	return (rd);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*stacks;
	char		*line;

	if (argc == 1)
		return (1);
	stacks = init(--argc);
	if (!is_valid(stacks, ++argv, argc))
		return (ultimate_free(stacks) && write(1, "Error\n", 6));
	while (get_next_line_ps(&line) > 0)
	{
		
		if (check(line, stacks))
			return (ultimate_free(stacks) && write(1, "Error\n", 6));
		free(line);
	}
	free(line);
	if (is_sorted(stacks->a) && !stacks->b)
		return (ultimate_free(stacks) && write(1, "OK\n", 6));
	return (ultimate_free(stacks) && write(1, "KO\n", 6));
}
