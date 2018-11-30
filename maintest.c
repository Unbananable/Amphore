/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:05:33 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/30 17:14:27 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_printf_d(char *flags, char *string);

int main(void)
{
	write(1, "ft_printf_d = ", 14);
	ft_printf_d("+12.8-d", "42");
	printf("\n     printf = %+12.8-d\n", 42);
	return (0);
}

/*
typedef struct	s_conv
{
	char	c(type de conv);
	char	*f(void *)(fonctionne qui applique la conv);
}				t_conv;

typedef struct	s_flag(flag + champ + precision)
{
	char	c;
	char	*f(char *(string de l'arg), char(type de conv))
}				t_flag;

t_conv	*conv;
conv[0].c = d, conv[1].c = i, ...ouxXfspc
conv[0].f = d() i() o()...

type de flag (+etc) :  + - espace # 0
modificateur de longueur : l ll L h hh
largeur de champ + precision

>>t_conv func() : return (truc);

le ' ' est ignoré avec un '+'
'+' avant 's' undefined behavior
'#' marche devant 'o'/'x', undefined before sdc etc

une fonction par flag
une fct par conversion
un parser :quelle conversion appliquer
un parser : quel flag appliquer
un parser: precision, largeur de champ

*/
