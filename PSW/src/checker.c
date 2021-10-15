#include "../inc/push_swap.h"

void display_stack(t_stack stack)
{
	int size = stack.size;
	int i = 0;

	while (i < size)
	{
		printf("%d element: %d\n", i + 1, stack.arr[i]);
		i++;
	}
}

int	is_sorted(t_stacks *stacks)
{
	int size = stacks->a.size;
	int i = 0;

	if (!stacks->b.size)
		return (0);
	while (i < size - 1)
	{	
		if (stacks->a.arr[i] > stacks->a.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*** ^ T E S T ^ ***/

// int get_next_line(char **line)
// {
// 	int rd;
// 	int i;
// 	char ch;
// 	char *buffer;
	
// 	rd = 0;
// 	i = 0;
// 	buffer = malloc(5);
// 	*line = buffer;
// 	while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
// 		buffer[i++] = ch;
// 	buffer[i] = '\0';
// 	return(rd);
// }

// int main(int argc, char *argv[])
// {
//     t_stacks *stacks;
// 	char 	*line;

// 	--argc;	
// 	stacks = new_stacks(argc);
// 	if(!fillable(stacks->a, &argv[1]) && argc != 0)
// 		return(write(1, "Error\n", 6));
// 	else
// 	{
// 		while (get_next_line(0, &line) > 0)
// 		{
// 			pick(line, stacks);
// 			free(line);
// 		}
// 		if(is_sorted(stacks))
// 			return(write(1, "OK", 3));
// 		return(write(1, "KO", 3));
// 	}
// }
// don't forget to MAKEFILE