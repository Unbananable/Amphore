#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*conv_big_x(va_list ap, char *mod)
{
	int		i;
	char	*r;

	i = -1;
	r = conv_x(ap, mod);
	while (r[++i])
		r[i] = ft_toupper(r[i]);
	return (r);
}
