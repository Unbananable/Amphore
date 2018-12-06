/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:47:15 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/06 19:47:52 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*converter(char *str, va_list ap)
{
	char	*res;

	res = parse_conv(ap, str);
	res = parse_accufield(res, str);
	res = parse_flag(res, str);
	return (res);
}

t_form		init_struct(t_form anc, const char *format)
{
	anc.i = 0;
	anc.cnt = 0;
	anc.fmt = format;
	return (anc);
}

t_form		set_struct1(t_form anc)
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

t_form		set_struct2(t_form anc, va_list ap)
{
	char	*str;
	char	*arg;

	write(1, anc.fmt, anc.i);
	anc.cnt += ft_strlen(anc.fmt);
	anc.fmt += anc.i + 1;
	anc.i = 0;
	while (anc.fmt[anc.i] && !ft_strchr("cspdiouxXf%", anc.fmt[anc.i]))
		anc.i++;
	if (!anc.fmt[anc.i])
		exit_error("error: invalid conversion\n", 0);
	anc.fmt += anc.i + 1;
	str = ft_strsub(anc.fmt - anc.i - 1, 0, anc.i + 1);
	arg = converter(str, ap);
	write(1, arg, ft_strlen(arg));
	anc.cnt += ft_strlen(arg);
	free(str);
	free(arg);
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
				anc = set_struct1(anc);
			else
				anc.i++;
		}
		else if (anc.fmt[anc.i] == '%')
		{
			anc = set_struct2(anc, ap);
		}
		else
			anc.i++;
	}
	write(1, anc.fmt, ft_strlen(anc.fmt));
	anc.cnt += ft_strlen(anc.fmt);
	va_end(ap);
	return (anc.cnt);
}
