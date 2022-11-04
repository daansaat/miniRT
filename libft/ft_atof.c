#include "libft.h"

float ft_atof(char *str)
{
	float	integer;
	float	decimal;
	float	sign;
	int		i;

	integer = 0.0;
	decimal = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		integer = integer * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			decimal += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (integer + decimal));
}