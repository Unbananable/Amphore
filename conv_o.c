#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

char	*conv_o(va_list ap, char *mod)
{
	unsigned long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		r = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		r = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		r = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		r = va_arg(ap, unsigned int) & 0xFF;
/* Pour les operateurs binaires je sais pas si tu connais,
 * un pote m'a expliqué comment faire, je t'expliquerai 
 * en face to face ce sera plus simple avec des dessins
 * mais en gros tu compares les bytes des deux resultats et 
 * tu prends que les '1' et pas les '0' */
	else if (ft_strequ(mod, "j"))
		r = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(ap, size_t);
	else if (*mod == 0)
		r = va_arg(ap, unsigned int);
	if (r == 0)
		return (ft_strdup("0"));
	return (ft_itoa_base(r, 8));
/* J'ai rajouté ft_itoa_base.c a la libft */
}
