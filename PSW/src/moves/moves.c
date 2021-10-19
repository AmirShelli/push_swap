/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:30:14 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:30:14 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack)->next;
	second = (*stack);
	third = (*stack)->next->next;
	first->next = second;
	first->previous = NULL;
	second->next = third;
	second->previous = first;
	if (third)
		third->previous = second;
	(*stack) = first;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack);
	second = first->next;
	last = stack_last_element(*stack);
	first->next = NULL;
	first->previous = last;
	second->previous = NULL;
	last->next = first;
	(*stack) = second;
}

void	reverse(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack);
	last = stack_last_element(*stack);
	second_last = last->previous;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	second_last->next = NULL;
	(*stack) = last;
}
