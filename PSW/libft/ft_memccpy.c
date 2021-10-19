/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:27:47 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:27:47 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*aux_src;
	unsigned char		*aux_dest;
	size_t				i;

	i = 0;
	aux_src = (unsigned char *)src;
	aux_dest = (unsigned char *)dest;
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		if (aux_dest[i] == (unsigned char)c)
			return (&aux_dest[i + 1]);
		i++;
	}
	return (NULL);
}
