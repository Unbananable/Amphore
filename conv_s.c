#include "libft/libft.h"
#include <stdarg.h>

char	*conv_c(va_list *ap, char *mod)
{
	char	*res;

	res = ft_strdup(va_arg(*ap, const char *));
	return (res);
}
