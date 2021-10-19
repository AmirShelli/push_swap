/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharghaz <bharghaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:29:16 by bharghaz          #+#    #+#             */
/*   Updated: 2021/10/19 22:29:17 by bharghaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*start_dest;
	unsigned int	i;

	i = 0;
	start_dest = dest;
	while (*dest)
		dest++;
	while ((src[i]) && (i < nb))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (start_dest);
}
