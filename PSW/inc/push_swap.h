#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	int				keep;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
	int		middle;
	int		smallest;
}	t_push_swap;

t_push_swap	*init(int size);
int			is_valid(t_push_swap *stacks, char **argv, int argc);

void		solve(t_push_swap *stacks);

int			is_sorted(t_stack *stack);
int			ultimate_free(t_push_swap *stacks);

t_stack		*new_stack(int num);
void		stack_push_front(t_stack **stack, t_stack *new_element);
t_stack		*stack_last_element(t_stack *stack);
t_stack		*get_value(t_stack *stack, int index);
int			get_index(t_stack *stack, int value);
void		free_stack(t_stack *stack);

void		pick(char *cmd, t_push_swap *stacks);

void		push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse(t_stack **stack);

void		smallsort(t_push_swap *stacks, int size);
void		fivesort(t_push_swap *stacks);

void		auto_move(char *which, int flag, int *index,
				t_push_swap *stacks);
int			best_seq(t_stack *stack);
int			markup(t_stack *stack);
void		push_to_b(t_push_swap *stacks);
int			index_a(t_push_swap *stacks, int index_b);
int			moves(int size, int index, int *flag);
int			best_index(t_push_swap *stacks);
void		push_to_a(t_push_swap *stacks);
int			run(t_push_swap *stacks, char *cmd, void (*func)(t_stack **));

void		print_stack(t_stack *stack, char st);

#endif