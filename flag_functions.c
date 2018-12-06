/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:51 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 10:24:01 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

char	*flag_hash(char *str, char c)
{
	char	*res;
	int		i;
	int		isx;

	if ((c != 'x' && c != 'X' && c != 'o') || (c == 'o' && str[0] == '0'))
		return (str);
	else if (c == 'o' && str[0] == ' ')
	{
		i = 0;
		while (str[i] == ' ')
			i++;
		str[i - 1] = '0';
		return (str);
	}
	isx = ((c == 'x' || c == 'X') ? 1 : 0);
	if (!(res = ft_strnew(ft_strlen(str) + 2 + isx)))
		exit_error("error: malloc failed\n", 1, str);
	res[0] = '0';
	if (isx)
		res[1] = (c == 'x' ? 'x' : 'X');
	ft_strncpy(res + 1 + isx, str, ft_strlen(str));
	free(str);
	return (res);
}

char	*flag_space(char *str, char c)
{
	int		i;
	char	*res;
	int		hasendspace;

	if (c != 'd' && c != 'i' && c != 'f')
		return (str);
	i = 0;
	while (str[i] && str[i] != '-' && str[i] != '+'
			&& (str[i] < '0' || str[i] > '9'))
		str[i++] = ' ';
	if (i != 0 || str[i] == '-' || str[i] == '+')
		return (str);
	hasendspace = (str[ft_strlen(str) - 1] == ' ' ? 1 : 0);
	if (!(res = ft_strnew(ft_strlen(str) + 2 - hasendspace)))
		return (NULL);
	res[0] = ' ';
	ft_strncpy(res + 1, str, ft_strlen(str) - hasendspace);
	free(str);
	return (res);
}

char	*flag_zero(char *str, char c)
{
	int		i;
	int		isneg;

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
	isneg = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '-'))
	{
		if (str[i] == '-')
			isneg = 1;
		str[i++] = '0';
	}
	str[0] = (isneg ? '-' : str[0]);
	return (str);
}

char	*flag_plus(char *str, char c)
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
		if (!(str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
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
	while (str[i - space_nb])
	{
		str[i - space_nb--] = ' ';
	}
	return (str);
}
