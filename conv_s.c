#include "libft/libft.h"
#include <stdarg.h>

char	*conv_s(va_list ap, char *mod)
{
	char	*res;

	mod += 0;
	res = ft_strdup(va_arg(ap, const char *));
	return (res);
}
