/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:28:05 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:28:05 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*aux_src;
	unsigned char		*aux_dest;

	aux_src = (unsigned char *)src;
	aux_dest = (unsigned char *)dest;
	if (!(dest) && !(src))
		return (NULL);
	if (aux_src > aux_dest)
		while (n--)
			*aux_dest++ = *aux_src++;
	else
		while (n--)
			aux_dest[n] = aux_src[n];
	return (dest);
}
