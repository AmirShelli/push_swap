#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SMALLER -1
# define BIGGER 1

#include "../libft/libft.h"
typedef	struct s_stack
{
	int *arr;
	int size;
}		t_stack;

typedef	struct s_push_swap
{
	t_stack a;
	t_stack b;
	int middle;
	int smallest;
}		t_stacks;


void	move_backward(t_stack *a, int from);
void	move_forward(t_stack *a, int from);
void	pick(char *cmd, t_stacks *stacks);

void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	reverse(t_stack *a);
void	rotate(t_stack *a);

int		fillable(t_stack stack, char **args);
t_stacks	*new_stacks(int size);
void	move(char *smaller,char *bigger, int index, t_stacks *stacks);
int		find_order(t_stacks *stacks);
int 	seperate_order(t_stacks *stacks);	
void	push_to_b(t_stacks *stacks, int flag);
void	push_to_a(t_stacks *stacks);

// not needed - delete
void	pb_until(int to, t_stack *a, t_stack *b);
void	pa_all(t_stack *a, t_stack *b);
int		is_in(int num, t_stack *stack);
int		biggest(t_stack *stack);
int		smallest(t_stack *stack);
void 	smallsort(t_stack *a);
void 	fivesort(t_stacks *stacks);
void	bubble_sort(t_stack *a, t_stack *b);

/*** ^ T E S T ^ ***/
void	display_stack(t_stack a);
int		is_sorted(t_stacks *stack);

#endif