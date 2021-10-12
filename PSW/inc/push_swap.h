#include "../libft/main_libft/libft.h"

typedef	struct s_stack
{
	int	*arr;
	int *boolie;
	int size;
}		t_stack;

typedef	struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	int		middle;
}		t_stacks;

void	display_stack(t_stack *stack);

void	move_backward(t_stack *a, int from);
void	move_forward(t_stack *a, int from);

void	pb_until(int to, t_stack *a, t_stack *b);
void	pa_all(t_stack *a, t_stack *b);
int		is_in(int num, t_stack *stack);
int		biggest(t_stack stack);
int		smallest(t_stack stack);

void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	reverse(t_stack *a);
void	rotate(t_stack *a);

void	pick(char *cmd, t_stack *a, t_stack *b);

int		fillable(int *arr, char **args);
t_stack	*new_stack(int alloc, int size);

// int		sort(t_stack *a, t_stack *b);
void smallsort(t_stack *a);
void fivesort(t_stacks *stacks);

/*** ^ T E S T ^ ***/
void	display_stack(t_stack *a);
void	bubble_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack stack);
