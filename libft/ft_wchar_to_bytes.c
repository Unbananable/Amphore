/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_bytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:31:43 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/10 11:39:19 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "libft.h"

static unsigned char	*ft_wchar_to_4bytes(wint_t c)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)ft_strnew(5)))
		return (NULL);
	res[0] = (((c & 1835008) >> 18) + 240);
	res[1] = (((c & 258048) >> 12) + 128);
	res[2] = (((c & 4032) >> 6) + 128);
	res[3] = ((c & 63) + 128);
	return (res);
}

static unsigned char	*ft_wchar_to_3bytes(wint_t c)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)ft_strnew(4)))
		return (NULL);
	res[0] = (((c & 61440) >> 12) + 224);
	res[1] = (((c & 4032) >> 6) + 128);
	res[2] = ((c & 63) + 128);
	return (res);
}

static unsigned char	*ft_wchar_to_2bytes(wint_t c)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)ft_strnew(3)))
		return (NULL);
	res[0] = (((c & 1984) >> 6) + 48);
	res[1] = ((c & 63) + 128);
	return (res);
}

unsigned char	*ft_wchar_to_bytes(wint_t c)
{
	unsigned char	*res;

	if (c & 2031616)
		res = ft_wchar_to_4bytes(c);
	else if (c & 63488)
		res = ft_wchar_to_3bytes(c);
	else if (c & 1920)
		res = ft_wchar_to_2bytes(c);
	else
	{
		if (!(res = (unsigned char *)ft_strnew(2)))
			return (NULL);
		res[0] = (unsigned char)c;
	}
	return (res);
}
