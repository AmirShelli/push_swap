#include "../../inc/push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*new_first;

	if (!*from)
		return ;
	new_first = (*from)->next;
	(*from)->next = *to;
	(*from)->previous = NULL;
	*to = *from; 
	if (*to && (*to)->next)
		(*to)->next->previous = *from;
	*from = new_first;
	if (*from)
		(*from)->previous = NULL;
}

void	swap(t_stack **stack)
{
	int	aux;

	if (!*stack || !(*stack)->next)
		return ;
	aux = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = aux;
}

void	rotate(t_stack **stack)
{
	t_stack	*aux;
	int		first;

	if (!*stack || !(*stack)->next)
		return ;
	aux = (*stack);
	first = (*stack)->num;
	while (aux->next)
	{
		aux->num = aux->next->num;
		aux = aux->next;
	}
	aux->num = first;
}

void	reverse(t_stack **stack)
{
	t_stack	*aux;
	int		last;

	if (!*stack || !(*stack)->next)
		return ;
	aux = stack_last_element(*stack);
	last = aux->num;
	while (aux->previous)
	{
		aux->num = aux->previous->num;
		aux = aux->previous;
	}
	aux->num = last;
}
