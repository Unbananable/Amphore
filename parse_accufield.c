/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/07 11:06:44 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	*parse_accufield(char *str, char *flg)
{
	int		i;
	int		iscnul;

	iscnul = ((flg[ft_strlen(flg) - 1] == 'c' && ft_strstr(str, "^@")) ? 1 : 0);
	i = 0;
	while (flg[i] && flg[i] != '.')
		i++;
	if (flg[i] == '.')
	{
		i++;
		str = accuracy(str, (size_t)ft_atoi(flg + i), flg[ft_strlen(flg) - 1]);
		while (flg[i] <= '9' && flg[i] >= '0')
			flg[i++] = '%';
	}
	i = 0;
	while (flg[i] &&
			!((i == 0 || flg[i - 1] != '.') && flg[i] > '0' && flg[i] <= '9'))
		i++;
	if (flg[i])
	{
		str = field_width(str, (size_t)ft_atoi(flg + i) + iscnul);
		while (flg[i] >= '0' && flg[i] <= '9')
			flg[i++] = '%';
	}
	return (str);
}
