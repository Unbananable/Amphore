/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_functions_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:46:45 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/12 15:07:30 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static char	*deci_part(double dbl, int accu)
{
	char	*res;
	int		i;
	double	tmp;

	if (!(res = ft_strnew(accu + 1)))
		exit_error("error: malloc failed\n", 0);
	i = -1;
	while (++i < accu)
		dbl *= 10;
	i = 0;
	while (--accu >= 0)
	{
		tmp = dbl / ft_double_power(10.0, accu);
		res[i] = '0' + (int)tmp;
		dbl -= (double)((int)tmp * ft_double_power(10.0, accu));
		i++;
	}
	return (res);
}

static char	*concat(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_strnew(len1 + len2 + 1)))
		exit_error("error: malloc failed\n", 2, s1, s2);
	ft_strncpy(res, s1, len1);
	ft_strncat(res, s2, len2);
	return (res);
}

static char	*integ_part(double *dbl)
{
	int		pow_max;
	int		i;
	double	tmp;
	char	*res;

	tmp = *dbl;
	pow_max = 0;
	while (tmp > 10.0)
	{
		pow_max++;
		tmp /= 10;
	}
	if (!(res = ft_strnew(pow_max + 1)))
		exit_error("error: malloc failed\n", 0);
	i = 0;
	while (pow_max >= 0)
	{
		tmp = *dbl / ft_double_power(10, pow_max);
		res[i] = '0' + (int)tmp;
		*dbl -= (double)((int)tmp * ft_double_power(10, pow_max));
		pow_max --;
		i++;
	}
	return (res);
}

char		*conv_f(va_list ap, char *specs)
{
	int		accu;
	int		i;
	char	*res;
	double	dbl;
	char	*tmp;

	accu = 6;
	i = 0;
	while (specs[i] && specs[i] != '.')
		i++;
	if (specs[i] == '.')
		accu = ft_atoi(specs + i + 1);
	dbl = va_arg(ap, double);
	res = integ_part(&dbl);
	if (accu)
	{
		if(!(tmp = ft_strnew(ft_strlen(res) + 2)))
			exit_error("error: malloc failed\n", 0);
		ft_strncpy(tmp, res, ft_strlen(res));
		tmp[ft_strlen(res)] = '.';
		free(res);
		res = tmp;
		tmp = deci_part(dbl, accu);
		res = concat(res, tmp);
	}
	return (res);
}
