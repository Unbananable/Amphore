/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:28:38 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/06 10:24:43 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static t_flag	*initialise_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag) * 5);
	flag[3].c = ' ';
	flag[0].c = '0';
	flag[1].c = '+';
	flag[2].c = '-';
	flag[4].c = '#';
	flag[3].f = &flag_space;
	flag[0].f = &flag_zero;
	flag[1].f = &flag_plus;
	flag[2].f = &flag_minus;
	flag[4].f = &flag_hash;
	return (flag);
}

char			*parse_flag(char *str, char *flg)
{
	int		i;
	t_flag	*flag;

	i = 0;
	flag = initialise_flag();
	while (i < 5)
	{
		if (ft_strchr(flg, flag[i].c))
			str = flag[i].f(str, flg[ft_strlen(flg) - 1]);
		i++;
	}
	return (str);
}
