#include "libft/libft.h"

char	*double_to_binary(double dbl)
{
	char	binary[65];
	double	byte;
	int		i;

	binary[64] = 0;
	byte = -0;
	i = -1;
	while (++i < 65)
	{
		binary[i] = (byte & dbl) ? '1' : '0';
		byte = byte >> 1;
	}
	return (binary);
}

char	*conv_f(va_list ap, char *specs)
{
	double	dbl;
	char	*binary;
	char	*arg;
	int		accu;
	int		i;

	dbl = va_arg(ap, double);
	binary = double_to_binary(dbl);
	accu = 6;
	i = -1;
	while (str[++i])
		if (str[i] == '.')
			accu = ft_atoi(str + i + 1);
	arg = binary_to_arg(binary, accu);
	return (arg);
}
