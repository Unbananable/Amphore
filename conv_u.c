#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

char	*conv_u(va_list *ap, char *mod)
{
	long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		r = va_arg(*ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		r = va_arg(*ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		r = va_arg(*ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		r = va_arg(*ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		r = va_arg(*ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(*ap, size_t);
	else if (*mod == 0)
		r = va_arg(*ap, unsigned int);
	return (ft_itoa_base(r, 10));
}
