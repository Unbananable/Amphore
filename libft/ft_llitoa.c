/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:25:53 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/07 13:09:06 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	al_nbdigit(long long int n)
{
	int					res;
	unsigned long long	tmp;

	res = 1;
	tmp = (n < 0 ? -n : n);
	while (tmp >= 10)
	{
		res++;
		tmp /= 10;
	}
	return (res);
}

char		*ft_llitoa(long long int n)
{
	char				*res;
	int					i;
	int					len;
	unsigned long long	tmp;

	len = (n < 0 ? al_nbdigit(n) + 1 : al_nbdigit(n));
	tmp = (n < 0 ? (unsigned long long)n - 2 : (unsigned long long)n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[0] = (n == 0 ? '0' : '-');
	i = len - 1;
	while (tmp)
	{
		res[i] = '0' + tmp % 10;
		tmp /= 10;
		i--;
	}
	return (res);
}
