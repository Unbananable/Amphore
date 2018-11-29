/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accufield_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:41:20 by anleclab          #+#    #+#             */
/*   Updated: 2018/11/29 19:05:14 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

char	*accuracy(char *str, int len)
{
	char	*ret;
	int		i;

	if (ft_strlen(str) < len)
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
		printf("passing by accu: %s\n", ret);
		return (ret);
	}
	return (str);
}

char	*field_width(char *str, int len)
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
		printf("passing by width: %s\n", ret);
		return (ret);
	}
	return (str);
}
