#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

#include <stdio.h>
static char	*bytes_to_string(int x)
{
	char	*str;
	int		z;

	z = 1073741824;
	if (!(str = ft_strnew(32)))
		return (NULL);
	while (z > 0)
	{
		ft_strcat(str, ((x & z) == (z + 1) ? "1" : "0"));
		z >>= 1;
	}
	return (str);
}

char	*conv_binary(va_list ap, char *mod)
{
	char	*res;

	if (!(res = ft_strdup(bytes_to_string(va_arg(ap, int)))))
		exit_error("error: malloc failed\n", 0);
	return (res);
}
