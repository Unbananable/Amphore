/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:18:49 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 09:18:56 by anleclab         ###   ########.fr       */
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
