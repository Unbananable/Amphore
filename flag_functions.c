/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:11:40 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/21 15:03:55 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*flag_hash(char *str, char conv)
{
	if (conv == 'o')
		return (suffix("0", str));
	if (conv == 'x' && ft_atoi(str))
		return (suffix("0x", str));
	if (conv == 'X' && ft_atoi(str))
		return (suffix("0X", str));
	return (str);
}

char	*flag_space(char *str, char conv)
{
	if ((conv == 'd' || conv == 'i' || conv == 'f') && str[0] != '-')
		return (suffix(" ", str));
	return (str);
}

char	*flag_plus(char *str, char conv)
{
	if ((conv == 'd' || conv == 'i' || conv == 'f') && !ft_strchr(str, '-'))
	{
		return (suffix("+", str));
	}
	return (str);
}

char	*flag_minus(char *str, char conv)
{
	int		i;
	int		j;

	conv += 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = ' ';
	return (str);
}

char	*flag_zero(char *str, char conv)
{
	int		i;

	if (conv == 'c' || conv == 's' || conv == 'p')
		return (str);
	if (!(i = 0) && (conv == 'd' || conv == 'i'))
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '0')
			return (str);
	}
	i = -1;
	while (str[++i] == ' ')
		str[i] = '0';
	if (i && (str[i] == '-' || str[i] == '+'))
	{
		str[0] = (str[i] == '-' ? '-' : '+');
		str[i] = '0';
	}
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		str[1] = (str[i + 1] == 'x' ? 'x' : 'X');
		str[i + 1] = '0';
	}
	return (str);
}
