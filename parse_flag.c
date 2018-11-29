/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:28:38 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 19:44:42 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static t_flag	*initialise_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag) * 5);
	flag[0].c = ' ';
	flag[1].c = '0';
	flag[2].c = '+';
	flag[3].c = '-';
	flag[4].c = '#';
	flag[0].f = &flag_space;
	flag[1].f = &flag_zero;
	flag[2].f = &flag_plus;
	flag[3].f = &flag_minus;
	flag[4].f = &flag_hash;
	return (flag);
}

char			*parse_flag(char *str, char *flg)
{
	int		i;
	char	*ret;
	t_flag	*flag;

	i = 0;
	flag = initialise_flag();
	printf("str in parse_flag(begin): %s\n", str);
	while(i < 5)
	{
		if (ft_strchr(flg, flag[i].c))
		{
			printf("str in parse_flag(middle - before function): %s\n", str);
/* hmm... on obtient quoi avec flg[ft_strlen(flg) - 1] ? pourquoi on s'interesse au dernier char de la chaine ???  */
			ret = flag[i].f(str, flg[ft_strlen(flg) - 1]);
			printf("ret in parse_flag(middle - after function): %s\n", ret);
		}
		i++;
	}
	printf("ret in parse_flag(end): %s\n", ret);
	return (ret);
}
