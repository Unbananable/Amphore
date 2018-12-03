/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accufield_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:41:20 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/03 16:30:58 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	*accuracy(char *str, size_t len, char c)
{
	char	*ret;
	int		i;

	if (c == 'c' || c == 'p')
		return (str);
	if (c == 's' && len > ft_strlen(str))
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
	i = 0;
	while (str[i] != '.')
		i++;
	if (!(ret = ft_strnew(i + len + 1)))
		return (NULL);
	if (i + len > ft_strlen(str))
	{
		ft_strncpy(ret, str, ft_strlen(str));
		ft_memset(ret + ft_strlen(str), i + len - ft_strlen(str), '0');
		free(str);
		return (ret);
	}
	ft_strncpy(ret, str, i + len);
	return (ret);
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
