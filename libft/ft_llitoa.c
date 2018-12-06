/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:25:53 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 18:59:27 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	al_nbdigit(long long int n)
{
	int		res;

	res = 1;
	n = (n < 0 ? -n : n);
	while (n >= 10)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char		*ft_llitoa(long long int n)
{
	char	*res;
	int		i;
	int		len;

	len = (n < 0 ? al_nbdigit(n) + 1 : al_nbdigit(n));
	n = (n < 0 ? -n : n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[0] = (n == 0 ? '0' : '-');
	i = len - 1;
	while (n)
	{
		res[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (res);
}
