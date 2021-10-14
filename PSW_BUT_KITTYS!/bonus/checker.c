#include "push_swap.h"

int get_next_line(char **line)
{
	int rd;
	int i;
	char ch;
	char *buffer;
	
	rd = 0;
	i = 0;
	buffer = malloc(10);
	*line = buffer;
	while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
		buffer[i++] = ch;
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	return(rd);
}

int main(int argc, char *argv[])
{
	t_push_swap	*stacks;
	char 		*line;

	if (argc == 1)
		return (1);
	stacks = init(--argc);
	if (!parse_and_validate(&stacks->a, ++argv, argc))
	{
		ultimate_free(stacks);
		write(1, "Error\n", 6);
		return (1);
	}
	while (get_next_line(&line) > 0)
	{
		pick(line, stacks);
		free(line);
	}
	if (check_sorted(stacks->a) && !stacks->b)
		return (write(1, "OK\n", 4));
	return (write(1, "KO\n", 4));
}
