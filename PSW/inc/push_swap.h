#include "../libft/main_libft/libft.h"

typedef struct s_stack
{
    int* arr;
    int size;
}   t_stack;

void	move_backward(t_stack *a, int from);
void	move_forward(t_stack *a, int from);

void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	reverse(t_stack *a);
void	rotate(t_stack *a);