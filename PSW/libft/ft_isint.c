/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:27:10 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:27:10 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	result;

	result = 0 + n < 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

int	ft_isint(char *number)
{
	int		i_number;
	int		negative;
	int		len;

	i_number = ft_atoi(number);
	negative = 0;
	len = 0;
	if (number[len] == '-')
	{
		negative = 1;
		len++;
	}
	while (ft_isdigit(number[len]))
		len++;
	if ((negative && i_number > 0) || (!negative && i_number < 0)
		|| numlen(i_number) != len)
		return (0);
	return (1);
}
