#include "../libft/main_libft/libft.h"

typedef struct s_stack
{
    int* arr;
    int size;
}   t_stack;

void	move_backward(t_stack *a, int from);
void	move_forward(t_stack *a, int from);

void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	swap_a(t_stack *a);
void	swap_b(t_stack *a);
void	swap_both(t_stack *a, t_stack *b);
void	reverse_a(t_stack *a);
void	reverse_b(t_stack *a);
void	reverse_both(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *a);
void	rotate_both(t_stack *a, t_stack *b);