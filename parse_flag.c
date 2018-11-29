/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:28:38 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 17:07:18 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static t_flag	*initialise_flag(void)
{
	t_flag	*flag;

	flag[0].c = '+';
	flag[1].c = '-';
	flag[2].c = ' ';
	flag[3].c = '#';
	flag[4].c = '0';
	flag[0].f = &flag_plus;
	flag[1].f = &flag_minus;
	flag[2].f = &flag_space;
	flag[3].f = &flag_hash;
	flag[4].f = &flag_zero;
	return (flag);
}

char			*parse_flag(char *str, char *flag)
{
	une fonction qui initialise les fonctions de flags
	et ensuite l'arbre d'if
}
