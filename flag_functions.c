/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:43:51 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/29 19:55:31 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	*flag_hash(char	*str, char c)
{
	return (str);
}

char	*flag_space(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] < '0' && str[i] > '9')
		str[i++] = ' ';
	return (str);
}

char	*flag_zero(char	*str, char c)
{
	int		i;
		
	i = 0;
	while (str[i] && str[i] < '0' && str[i] > '9')
		str[i++] = '0';
	return (str);
}

char	*flag_plus(char	*str, char c)
{
	char	*str2;

	if (str[0] != '-')
	{
		if(!(str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (NULL);
		str2[0] = '+';
		ft_strncpy(str2 + 1, str, ft_strlen(str));
		str2[ft_strlen(str) + 1] = 0;
		free(str);
		return (str2);
	}
	return (str);
}

char	*flag_minus(char *str, char c)
{
	int		i;
	int		j;
	int		space_nb;
	char	*tmp;

	i = -1;
	j = 0;
	space_nb = 0;
	while (str[++i] == ' ')
		space_nb++;
	printf("space_nb: %d\n", space_nb);
	tmp = str;
	printf("tmp (minus, before while): %s\n", tmp);
	while (tmp[i])
	{
		str[j++] = tmp[i++];
		printf("str (minus, in while): %s\n", str);
	}
	printf("i: %d\n", i);
	free(tmp);
	while (str[i - space_nb])
	{
		printf("str (while minus): %s\n", str);
		str[i - space_nb--] = ' ';
	}
	return (str);
}
/*
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] >= '0' && str[j] <= '9')
		j++;
	while (str[j] && str[i] < '0' && str[i] > '9')
	{
		str[i] = str[j];
		str[j] = ' ';
		j++;
		i++;
	}
	return (str);
}
*/
