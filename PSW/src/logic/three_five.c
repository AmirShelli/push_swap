/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:30:10 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:30:10 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	smallsort(t_push_swap *stacks, int size)
{
	int	first;
	int	second;
	int	third;

	if (size == 2 && stacks->a->num > stacks->a->next->num)
		pick("sa\n", stacks);
	if (!is_sorted(stacks->a))
	{
		first = stacks->a->num;
		second = stacks->a->next->num;
		third = stacks->a->next->next->num;
		if (first < second && second > third && third < first)
			pick("rra\n", stacks);
		else if (first > second && second < third && third < first)
			pick("ra\n", stacks);
		else if (first > second || (second > third && third > first))
		{	
			pick("sa\n", stacks);
			if (first < second)
				pick("ra\n", stacks);
			else if (third < first)
				pick("rra\n", stacks);
		}
	}
}

int	biggest(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

void	fivesort(t_push_swap *stacks)
{
	int	min;
	int	max;

	min = stacks->smallest;
	max = biggest(stacks->a);
	while (stacks->size_b != 2)
	{
		if (stacks->a->num != min && stacks->a->num != max)
			pick("ra\n", stacks);
		else
			pick("pb\n", stacks);
	}
	smallsort(stacks, stacks->size_a);
	while (stacks->size_b)
	{
		pick("pa\n", stacks);
		if (stacks->a->num == max)
			pick("ra\n", stacks);
	}
}
