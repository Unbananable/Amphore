/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:56:09 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 15:36:01 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*conv_p(va_list ap, char *mod)
{
	void	*str;
	char	*res;
	char	*conv;

	mod += 0;
	str = va_arg(ap, void *);
	if (!(res = ft_strnew(19)))
		exit_error("error: malloc failed\n", 1, str);
	ft_strncpy(res, "0x", 2);
	conv = ft_itoa_base((unsigned long int)str, 16);
	ft_strncat(res, conv, 16);
	free(conv);
	return (res);
}

char	*conv_c(va_list ap, char *mod)
{
	char			*res;
	unsigned char	arg;

	mod += 0;
	arg = (unsigned char)va_arg(ap, int);
	res = ft_strnew(1);
	res[0] = arg;
	return (res);
}

char	*conv_s(va_list ap, char *mod)
{
	char	*res;

	mod += 0;
	res = (char *)va_arg(ap, const char *);
	if (!res)
	{
		if (!(res = ft_strdup("(null)")))
			exit_error("error: malloc failed\n", 0);
		return (res);
	}
	if(!(res = ft_strdup(res)))
		exit_error("error: malloc failed\n", 0);
	return (res);
}
