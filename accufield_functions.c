/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accufield_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:41:20 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/12 18:48:12 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char	*accuracy_p(char *str, size_t len)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(len + 2)))
		return (NULL);
	i = -1;
	while (++i < (int)len + 4 - (int)ft_strlen(str))
		ret[i] = (i == 1 ? 'x' : '0');
	ft_strncpy(ret + i, str + 2, ft_strlen(str) - 2);
	return (str);
}

static char	*accuracy_s(char *str, size_t len)
{
	char			*ret;
	int				i;
	int				j;
	unsigned char	byte;

	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(ret, str, len);
	i = 0;
	while (i < (int)len)
	{
		j = 0;
		byte = 128;
		while (byte & ret[i])
		{
			byte = byte >> 1;
			j++;
		}
		if (i + j > (int)len)
			while (ret[i])
				ret[i++] = 0;
		i++;
	}
	return (ret);
}

char		*accuracy(char *str, size_t len, char *specs)
{
	char	*ret;
	int		isneg;
	char	conv;

	conv = specs[ft_strlen(specs) - 1];
	if (conv == 'p' && len >= ft_strlen(str))
		ret = accuracy_p(str, len);
	else if (conv == 's')
		ret = accuracy_s(str, len);
	else if ((conv == 'x' || conv == 'X' || conv == 'd' || conv == 'o') &&
			len == 0 && ft_atoi(str) == 0)
		ret = ft_strdup("");
	else if (conv != 'c' && conv != 'p' && conv != 'f' && ft_strlen(str) <= len)
	{
		isneg = (*str == '-' ? 1 : 0);
		if (!(ret = (char *)malloc(sizeof(char) * (len + isneg + 1))))
			exit_error("error: malloc failed\n", 2, str, specs);
		ret[len + isneg] = 0;
		ft_memset(ret, '0', len + 2 * isneg - ft_strlen(str));
		ft_strncat(ret, str + isneg, ft_strlen(str) - isneg);
		if (isneg)
			*ret = '-';
	}
	else
		ret = ft_strdup(str);
	free(str);
	if (!ret)
		exit_error("error: malloc failed\n", 1, specs);
	return (ret);
}

char		*field_width(char *str, size_t len)
{
	char	*ret;
	int		i;

	if (ft_strlen(str) < len)
	{
		if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ret[len] = 0;
		ft_memset(ret, ' ', len);
		i = ft_strlen(str);
		while (--i >= 0)
		{
			ret[len-- - 1] = str[i];
		}
		free(str);
		return (ret);
	}
	return (str);
}
