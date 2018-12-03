#include "libft/libft.h"
#include <stdarg.h>

char	*conv_c(va_list *ap, char *mod)
{
	char			*res;
	unsigned char	arg;

	mod += 0;
	arg = (unsigned char)va_arg(*ap, int);
	res = ft_strnew(1);
	res[0] = arg;
	return (res);
}
