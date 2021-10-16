#include "push_swap.h"

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
	buffer[i] = '\n';
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
	{
		ultimate_free(stacks);
		write(1, "Error\n", 6);
		return (1);
	}
	while (get_next_line_ps(&line) > 0)
	{
		pick(line, stacks);
		free(line);
	}
	free(line);
	if (is_sorted(stacks->a) && !stacks->b)
	{
		ultimate_free(stacks);
		return (write(1, "OK\n", 4));
	}
	ultimate_free(stacks);
	return (write(1, "KO\n", 4));
}
