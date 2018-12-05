/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/05 14:32:53 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	*parse_accufield(char *str, char *flg)
{
	int		i;
	int		j;
	size_t	accu;
	size_t	field;

	i = -1;
	accu = 0;
	field = 0;
	while(flg[++i])
	{
		if (flg[i] == '.')
		{
			accu = (size_t)ft_atoi(flg + (i + 1));
			j = i + 1;
			while (flg[j] <= '9' && flg[j] >= '0')
				flg[j++] = '%';
			str = accuracy(str, accu, flg[ft_strlen(flg) - 1]);
		}
	}
	i = -1;
	while (flg[++i])
	{
		if ((i == 0 || flg[i - 1] != '.') && flg[i] > '0' && flg[i] <= '9')
		{
			field = (size_t)ft_atoi(flg + i);
			j = i;
			while (flg[j] >= '0' && flg[j] <= '9')
				flg[j++] = '%';
			str = field_width(str, field);
		}
	}
	return (str);
}
