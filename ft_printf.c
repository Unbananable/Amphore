#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char		*converter(char *specs, va_list ap)
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
	int			count;

	count = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '{')
		{
			specs = parse_color(format + i);
			if (specs)
			{
				write(1, format, i);
				count += i;
				if (!ft_strequ(specs, "\033[0m"))
					write(1, specs, 7);
				else
					write(1, specs, 4);
				format += param_len(format + i) + i;
				i = 0;
				specs = NULL;
			}
			else
				i++;
		}
		else if (format[i] == '%')
		{
			write(1, format, i);
			count += i;
			format += i + 1;
			i = 0;
			while (format[i] && !ft_strchr("cspdiouxXf%", format[i]))
				i++;
			if (!format[i])
				exit_error("error: invalid conversion\n", 0);
			specs = ft_strsub(format, 0, i + 1);
			format += i + 1;
			arg = converter(specs, ap);
			write(1, arg, ft_strlen(arg));
			count += ft_strlen(arg);
			free(specs);
			i = 0;
		}
		else
			i++;
	}
	write(1, format, ft_strlen(format));
	count += ft_strlen(format);
	va_end(ap);
	return(count);
}
