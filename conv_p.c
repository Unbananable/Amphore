#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char		*conv_p(va_list ap, char *mod)
{
	void	*str;
	char	*res;
	char	*conv;

	mod += 0;
	str = va_arg(ap, void *);
	if (!(res = ft_strnew(19)))
		return (NULL);
	ft_strncpy(res, "0x", 2);
	conv = ft_itoa_base((unsigned long int)str, 16);
	ft_strncat(res, conv, 16);
	free(conv);
	return (res);
}
