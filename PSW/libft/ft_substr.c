/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:29:38 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:29:38 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char	*str;
	char	*aux_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < size)
		size = ft_strlen(s + start);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	aux_str = str;
	if (str)
	{
		if (start < ft_strlen(s))
			while (*(s + start) && size--)
				*str++ = *(s++ + start);
	}
	return (aux_str);
}
