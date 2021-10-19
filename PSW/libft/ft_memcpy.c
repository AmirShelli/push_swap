/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:27:53 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:27:53 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*aux_dest;
	unsigned const char	*aux_src;

	aux_dest = dest;
	aux_src = src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*aux_dest++ = *aux_src++;
	return (dest);
}
