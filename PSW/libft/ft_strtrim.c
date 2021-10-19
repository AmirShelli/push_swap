/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:29:36 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:29:36 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char c, const char *set)
{
	while (*set && c != *set)
		set++;
	return (c == *set);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t		size;
	char		*result;

	if (!s)
		return (NULL);
	while (*s && ft_isin(*s, set))
		s++;
	size = ft_strlen(s);
	while (size && ft_isin(s[size - 1], set))
		size--;
	result = ft_substr(s, 0, size);
	return (result);
}
