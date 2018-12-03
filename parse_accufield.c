/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/03 16:30:16 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*parse_accufield(char *str, char *flg)
{
	int		i;
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
			str = accuracy(str, accu, flg[ft_strlen(flg) - 1]);
		}
	}
	i = -1;
	while (flg[++i])
	{
		if (flg[i] > '0' && flg[i] <= '9')
		{
			field = (size_t)ft_atoi(flg + i);
			str = field_width(str, field);
		}
	}
	return (str);
}
