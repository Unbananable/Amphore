/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:56:58 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 09:57:02 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

int		get_accuracy(char *specs)
{
	int		i;

	i = -1;
	while (specs[++i])
	{
		if (specs[i] == '.')
			return (ft_atoi(specs + i + 1));
	}
	return (6);
}

char	*conv_f(va_list ap, char *specs)
{
	int		accu;
	double	d;
	char	*ret;

	accu = get_accuracy(specs);
	d = va_arg(ap, double);
	ret = ft_doubletoa(d, accu);
	return (ret);
}
