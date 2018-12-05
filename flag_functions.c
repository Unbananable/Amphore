/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:51 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/05 14:00:25 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	*flag_hash(char	*str, char c)
{
	char	*res;

	if (c != 'x' && c != 'X' && c != 'o')
		return (str);
	if (c == 'x' || c == 'X')
	{
		if (!(res = ft_strnew(ft_strlen(str) + 3)))
			return (NULL);
		res[0] = '0';
		res[1] = (c == 'x' ? 'x' : 'X');
		ft_strncpy(res + 2, str, ft_strlen(str));	
	}
	else
	{
		if (!(res = ft_strnew(ft_strlen(str) + 2)))
			return (NULL);
		res[0] = '0';
		ft_strncpy(res + 1, str, ft_strlen(str));
	}
	free(str);
	return (res);
}

char	*flag_space(char *str, char c)
{
	int		i;
	char	*res;

	if (c != 'd' && c != 'i' && c != 'f')
		return (str);
	i = 0;
	while (str[i] && str[i] < '0' && str[i] > '9')
		str[i++] = ' ';
	if (i != 0)
		return (str);
	if (!(res = ft_strnew(ft_strlen(str) + 2)))
		return (NULL);
	res[0] = ' ';
	ft_strncpy(res + 1, str, ft_strlen(str));
	free(str);
	return (res);
}

char	*flag_zero(char	*str, char c)
{
	int		i;

	if (c == 'p')
	{
		i = 0;
		while (str[i] && str[i] == ' ')
		{
			str[i] = (i == 1 ? 'x' : '0');
			i++;
		}
		if (i)
			str[i + 1] = '0';
		return (str);
	}
	i = 0;
	while (str[i] && str[i] == ' ')
		str[i++] = '0';
	return (str);
}

char	*flag_plus(char	*str, char c)
{
	char	*str2;
	int		i;

	if (c != 'd' && c != 'i' && c != 'f')
		return (str);
	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '-')
		i++;
	if (!i && str[i] != '-')
	{
		if(!(str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (NULL);
		str2[0] = '+';
		ft_strncpy(str2 + 1, str, ft_strlen(str));
		str2[ft_strlen(str) + 1] = 0;
		free(str);
		return (str2);
	}
	if (i && str[i] != '-')
		*(str + i - 1) = '+';
	return (str);
}

char	*flag_minus(char *str, char c)
{
	int		i;
	int		j;
	int		space_nb;
	char	*tmp;

	c += 0;
	i = -1;
	j = 0;
	space_nb = 0;
	while (str[++i] == ' ')
		space_nb++;
	tmp = str;
	while (tmp[i])
	{
		str[j++] = tmp[i++];
	}
	free(tmp);
	while (str[i - space_nb])
	{
		str[i - space_nb--] = ' ';
	}
	return (str);
}
