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

static char *selected_color(const char *format)
{

//	printf("passe dans selected\n");
	if (ft_strnequ(format, "{red}", 5))
		return ("\033[0;31m");
	if (ft_strnequ(format, "{green}", 7))
		return ("\033[0;32m");
	if (ft_strnequ(format, "{yellow}", 8))
		return ("\033[0;33m");
	if (ft_strnequ(format, "{blue}", 6))
		return ("\033[0;34m");
	if (ft_strnequ(format, "{magenta}", 9))
		return ("\033[0;35m");
	if (ft_strnequ(format, "{cyan}", 6))
		return ("\033[0;36m");
	if (ft_strnequ(format, "{bold red}", 10))
		return ("\033[1;31m");
	if (ft_strnequ(format, "{bold green}", 12))
		return ("\033[1;32m");
	if (ft_strnequ(format, "{bold yellow}", 13))
		return ("\033[1;33m");
	if (ft_strnequ(format, "{bold blue}", 11))
		return ("\033[1;34m");
	if (ft_strnequ(format, "{bold magenta}", 14))
		return ("\033[1;35m");
	if (ft_strnequ(format, "{bold cyan}", 11))
		return ("\033[1;36m");
	if (ft_strnequ(format, "{eoc}", 5))
		return ("\033[0m");
	return (NULL);
}

static int	len_to_skip(const char *format)
{

	if (ft_strnequ(format, "{red}", 5))
		return (5);
	if (ft_strnequ(format, "{green}", 7))
		return (7);
	if (ft_strnequ(format, "{yellow}", 8))
		return (8);
	if (ft_strnequ(format, "{blue}", 6))
		return (6);
	if (ft_strnequ(format, "{magenta}", 9))
		return (9);
	if (ft_strnequ(format, "{cyan}", 6))
		return (6);
	if (ft_strnequ(format, "{bold red}", 10))
		return (10);
	if (ft_strnequ(format, "{bold green}", 12))
		return (12);
	if (ft_strnequ(format, "{bold yellow}", 13))
		return (13);
	if (ft_strnequ(format, "{bold blue}", 11))
		return (11);
	if (ft_strnequ(format, "{bold magenta}", 14))
		return (14);
	if (ft_strnequ(format, "{bold cyan}", 11))
		return (11);
	if (ft_strnequ(format, "{eoc}", 5))
		return (5);
	return (0);
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
		if (format[i] == '{')
		{
			specs = selected_color(format + i);
			if (specs)
			{
				write(1, format, i);
				if (!ft_strequ(specs, "\033[0m"))
					write(1, specs, 7);
				else
					write(1, specs, 4);
				format += len_to_skip(format + i) + i;
				i = 0;
				specs = NULL;
			}
			else
				i++;
		}
		else if (format[i] == '%')
		{
			write(1, format, i);
			format += i + 1;
			i = 0;
			while (format[i] && !ft_strchr("cspdiouxXf", format[i]))
				i++;
			if (!format[i])
			{
				write(1, "error\n", 6);
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
