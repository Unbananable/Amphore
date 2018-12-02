#include "libft/libft.h"
#include <stdarg.h>

char		*conv_p(va_list ap, char *mod)
{
	char	*str;
	char	*res;

	str = va_arg(ap, char *);
	res = ft_strdup("0x");
	ft_strcat(res, ft_itoa_base((unsigned long int)str, 16));
	return (res);
}
