#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

char	*conv_d(va_list *ap, char *mod)
{
	long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		r = va_arg(*ap, long);
	else if (ft_strequ(mod, "ll"))
		r = va_arg(*ap, long long);
	else if (ft_strequ(mod, "h"))
		r = (short int)va_arg(*ap, int);
	else if (ft_strequ(mod, "hh"))
		r = (char)va_arg(*ap, int);
	else if (ft_strequ(mod, "j"))
		r = va_arg(*ap, intmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(*ap, long long int);
	else if (*mod == 0)
		r = va_arg(*ap, int);
	return (ft_itoa(r));
}
