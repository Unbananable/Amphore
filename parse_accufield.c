/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 19:14:06 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*parse_accufield(char *str, char *flg)
{
	int		i;
	int		accu;
	int		field;

	i = -1;
	accu = 0;
	field = 0;
	while(flg[++i])
	{
		if (flg[i] == '.')
		{
			accu = ft_atoi(flg + (i + 1));
			str = accuracy(str, accu);
		}
	}
	i = -1;
	while (flg[++i])
	{
		if (flg[i] > '0' && flg[i] <= '9')
		{
			field = ft_atoi(flg + i);
			str = field_width(str, field);
		}
	}
	printf("str from parse_accufield: %s\n", str);
	return (str);
}
