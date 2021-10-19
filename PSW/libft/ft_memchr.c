/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:27:49 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:27:49 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*aux_src;

	aux_src = (unsigned char *)src;
	while (n--)
	{
		if (*aux_src == (unsigned char)c)
			return (aux_src);
		aux_src++;
	}
	return (NULL);
}
