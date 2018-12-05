/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accufield_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:41:20 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/05 12:50:04 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

char	*accuracy(char *str, size_t len, char c)
{
	char	*ret;
	int		i;

	if (c == 'c' || c == 'f' || (c == 'p' && len < ft_strlen(str)))
		return (str);
	if (c == 'p')
	{
		if (!(ret = ft_strnew(len + 2)))
			return (NULL);
		i = 0;
		while (i < (int)len + 4 - (int)ft_strlen(str))
		{
			ret[i] = (i == 1 ? 'x' : '0');
			i++;
		}
		ft_strncpy(ret + i, str + 2, ft_strlen(str) - 2);
		free(str);
		return (ret);
	}
	if (c == 's')
	{
		if (!(ret = ft_strnew(len + 1)))
			return (NULL);
		ft_strncpy(ret, str, len);
		free(str);
		return (ret);
	}
	if (c != 'f' && ft_strlen(str) < len)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ret[len] = 0;
		ft_memset(ret, '0', len);
		i = ft_strlen(str) - 1;
		while (i >= 0)
		{
			ret[len - 1] = str[i];
			i--;
			len--;
		}
		free(str);
		return (ret);
	}
	return (str);
}

char	*field_width(char *str, size_t len)
{
	char	*ret;
	int		i;

	if (ft_strlen(str) < len)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ret[len] = 0;
		ft_memset(ret, ' ', len);
		i = ft_strlen(str) - 1;
		while (i >= 0)
		{
			ret[len - 1] = str[i];
			i--;
			len--;
		}
		free(str);
		return (ret);
	}
	return (str);
}
