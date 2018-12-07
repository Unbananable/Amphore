/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:57:10 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/07 12:16:39 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

char	*conv_d(va_list ap, char *mod)
{
	long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		return(ft_litoa(va_arg(ap, long)));
	else if (ft_strequ(mod, "ll"))
		return (ft_llitoa(va_arg(ap, long long)));
	else if (ft_strequ(mod, "h"))
		r = (short int)va_arg(ap, int);
	else if (ft_strequ(mod, "hh"))
		r = (char)va_arg(ap, int);
	else if (ft_strequ(mod, "j"))
		return(ft_llitoa(va_arg(ap, intmax_t)));
	else if (ft_strequ(mod, "z"))
		return(ft_llitoa(va_arg(ap, long long int)));
	else if (*mod == 0)
		r = va_arg(ap, int);
	return (ft_itoa(r));
}

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
	else if (ft_strequ(mod, "j"))
		r = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(ap, size_t);
	else if (*mod == 0)
		r = va_arg(ap, unsigned int);
	if (r == 0)
		return (ft_strdup("0"));
	return (ft_itoa_base(r, 8));
}

char	*conv_u(va_list ap, char *mod)
{
	long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		r = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		r = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		r = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		r = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		r = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(ap, size_t);
	else if (*mod == 0)
		r = va_arg(ap, unsigned int);
	return (ft_itoa_base(r, 10));
}

char	*conv_x(va_list ap, char *mod)
{
	long long int	r;

	r = 0;
	if (ft_strequ(mod, "l"))
		r = va_arg(ap, unsigned long);
	else if (ft_strequ(mod, "ll"))
		r = va_arg(ap, unsigned long long);
	else if (ft_strequ(mod, "h"))
		r = va_arg(ap, unsigned int) & 0xFFFF;
	else if (ft_strequ(mod, "hh"))
		r = va_arg(ap, unsigned int) & 0xFF;
	else if (ft_strequ(mod, "j"))
		r = va_arg(ap, uintmax_t);
	else if (ft_strequ(mod, "z"))
		r = va_arg(ap, size_t);
	else if (*mod == 0)
		r = va_arg(ap, unsigned int);
	return (ft_itoa_base(r, 16));
}

char	*conv_big_x(va_list ap, char *mod)
{
	int		i;
	char	*r;

	i = -1;
	r = conv_x(ap, mod);
	while (r[++i])
		r[i] = ft_toupper(r[i]);
	return (r);
}
