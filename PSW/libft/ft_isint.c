#include "libft.h"

static int	numlen(int n)
{
	int	result;

	result = 0 + n < 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

int	ft_isint(char *number)
{
	int		i_number;
	int		negative;
	int		len;

	i_number = ft_atoi(number);
	negative = 0;
	len = 0;
	if (number[len] == '-')
	{
		negative = 1;
		len++;
	}
	while (ft_isdigit(number[len]))
		len++;
	if ((negative && i_number > 0) || (!negative && i_number < 0)
		|| numlen(i_number) != len)
		return (0);
	return (1);
}
