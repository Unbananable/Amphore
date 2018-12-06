#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

static char	*converter(char *str, va_list ap)
{
	char	*res;

	res = parse_conv(ap, str);
	res = parse_accufield(res, str);
	res = parse_flag(res, str);
	return(res);
}

static int	write_and_count(const char *ft, int cnt, int i, va_list ap)
{
	char	*str;
	char	*arg;

	if (!ap)
	{
		str = parse_color(ft + i);
		write(1, ft, i);
		cnt += i;
		if (!ft_strequ(str, "\033[0m"))
			write(1, str, 7);
		else
			write(1, str, 4);
		str = NULL;
	}
	else
	{
		str = ft_strsub(ft, 0, i + 1);
		arg = converter(str, ap);
		write(1, arg, ft_strlen(arg));
		cnt += ft_strlen(arg);
		free(str);
		free(arg);
	}
	return (cnt);
}

static int	write_then_count(const char *format, int i, int count, int mode)
{
	if (mode)
	{
		write(1, format, i);
		count += i;
		return (count);
	}
	else
	{
		write(1, format, ft_strlen(format));
		count += ft_strlen(format);
		return (count);
	}
}

t_form		init_struct(t_form anc, const char *format)
{
	anc.i = 0;
	anc.cnt = 0;
	anc.fmt = format;
	return (anc);
}

t_form		set_struct(t_form anc)
{
	char *str;

	str = parse_color(anc.fmt + anc.i);
	write(1, anc.fmt, anc.i);
	anc.cnt += anc.i;
	if (!ft_strequ(str, "\033[0m"))
		write(1, str, 7);
	else
		write(1, str, 4);
	str = NULL;
	anc.fmt += param_len(anc.fmt + anc.i) + anc.i;
	anc.i = 0;
	return (anc);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_form		anc;

	va_start(ap, format);
	anc = init_struct(anc, format);
	while (anc.fmt[anc.i])
	{
		if (anc.fmt[anc.i] == '{')
		{
			if (parse_color(anc.fmt + anc.i))
				anc = set_struct(anc);
			else
				anc.i++;
		}
		else if (anc.fmt[anc.i] == '%')
		if (format[i] == '%')
		{
			anc.cnt = write_then_count(anc.fmt, anc.i, anc.cnt, 1);
			anc.fmt += anc.i + 1;
			anc.i = 0;
			while (anc.fmt[anc.i] && !ft_strchr("cspdiouxXf%", anc.fmt[anc.i]))
				anc.i++;
			if (!anc.fmt[anc.i])
				exit_error("error: invalid conversion\n", 0);
			anc.fmt += anc.i + 1;
			anc.cnt = write_and_count(anc.fmt - anc.i - 1, anc.cnt, anc.i, ap);
			anc.i = 0;
		}
		else
			anc.i++;
	}
	anc.cnt = write_then_count(anc.fmt, anc.i, anc.cnt, 0);
	va_end(ap);
	return(anc.cnt);
}
