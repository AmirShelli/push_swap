#include "../inc/push_swap.h"

int fill_a(t_stack *a, char **args)
{
	while(*args++)
	{
		if(is_nbr(*args))
		{
			
		}
		else
		{
			write(1, "Error", 5);
			return(0);
		}

	}
}

int main(argc, argv[])
{
    t_stack *a;
    t_stack *b;

	set(a, b, argc);
    fill(a, &argv[1]);

	
}