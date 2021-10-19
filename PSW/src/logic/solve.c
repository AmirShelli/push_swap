/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:30:08 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:30:08 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	solve(t_push_swap *stacks)
{
	int	flag;
	int	smallest;

	if (stacks->size_a <= 3)
		smallsort(stacks, stacks->size_a);
	else if (stacks->size_a <= 5)
		fivesort(stacks);
	else
	{
		push_to_b(stacks);
		push_to_a(stacks);
		smallest = moves(stacks->size_a,
				get_index(stacks->a, stacks->smallest), &flag);
		auto_move("a\n", flag, &smallest, stacks);
	}
}
