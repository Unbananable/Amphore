/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:28:38 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/06 18:50:01 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static t_flag	*initialise_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag) * 5);
	flag[0].c = ' ';
	flag[3].c = '0';
	flag[2].c = '+';
	flag[4].c = '-';
	flag[1].c = '#';
	flag[0].f = &flag_space;
	flag[3].f = &flag_zero;
	flag[2].f = &flag_plus;
	flag[4].f = &flag_minus;
	flag[1].f = &flag_hash;
	return (flag);
}

char			*parse_flag(char *str, char *specs)
{
	int		i;
	t_flag	*flag;

	flag = initialise_flag();
	i = -1;
	if (ft_strchr(specs, '-'))
		while (specs[++i])
			if (specs[i] == '0')
				specs[i] = '%';
	i = -1;
	if (ft_strchr(specs, '+'))
		while (specs[++i])
			if (specs[i] == ' ')
				specs[i] = '%';
	i = 0;
	while (i < 5)
	{
		if (ft_strchr(specs, flag[i].c))
			str = flag[i].f(str, specs[ft_strlen(specs) - 1]);
		i++;
	}
	return (str);
}
