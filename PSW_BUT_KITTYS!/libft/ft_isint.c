#include "libft.h"

int ft_isint(char *number)
{
	if(ft_strcmp(number, ft_itoa(ft_atoi(number))))
		return (1);
	return (0);
}