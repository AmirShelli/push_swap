/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:27:51 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:27:51 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s_st, const void *s_nd, size_t n)
{
	unsigned char	*aux_st;
	unsigned char	*aux_nd;

	aux_st = (unsigned char *)s_st;
	aux_nd = (unsigned char *)s_nd;
	while (n--)
	{
		if (*aux_st != *aux_nd)
			return ((unsigned char)*aux_st - (unsigned char)*aux_nd);
		aux_st++;
		aux_nd++;
	}
	return (0);
}
