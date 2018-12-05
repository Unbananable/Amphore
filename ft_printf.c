#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char			*converter(char *specs, va_list ap)
{
	char	*str;

	str = parse_conv(ap, specs);
	str = parse_accufield(str, specs);
	str = parse_flag(str, specs);
	return(str);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char		*arg;
	char		*specs;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			write(1, format, i);
			format += i + 1;
			i = 0;
			while (format[i] && !ft_strchr("cspdiouxXf", format[i]))
				i++;
			if (!format[i])
			{
				write(1, "error", 1);
				return (0);
			}
			specs = ft_strsub(format, 0, i + 1);
			format += i + 1;
			arg = converter(specs, ap);
			write(1, arg, ft_strlen(arg));
			free(specs);
			i = 0;
		}
		else
			i++;
	}
	write(1, format, ft_strlen(format));
	va_end(ap);
	return(26);
}
