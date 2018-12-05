#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

void	exit_error(char *er_mess, int nbfree, ...)
{
	va_list		ap;

	write(1, er_mess, ft_strlen(er_mess));
	va_start(ap, nbfree);
	while (nbfree--)
		free(va_arg(ap, void *));
	va_end(ap);
	exit (0);
}
