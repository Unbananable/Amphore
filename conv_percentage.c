#include "libft/libft.h"
#include <stdarg.h>

char	*conv_percentage(va_list *ap, char *mod)
{
	*ap += 2;
	mod++;
	return (ft_strdup("%"));
}
