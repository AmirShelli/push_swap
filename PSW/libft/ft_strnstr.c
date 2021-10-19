/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:29:29 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:29:29 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t		i;

	if (!*small || !small)
		return ((char *)big);
	while (*big && n--)
	{
		i = 0;
		while (big[i] && big[i] == small[i] && i <= n)
		{
			if (!small[i + 1])
				return ((char *)big);
			++i;
		}
		big++;
	}
	return (NULL);
}
