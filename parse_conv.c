/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:17:35 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 18:35:30 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

static t_conv	*initialize_conv_functions(void)
{
	t_conv	*conv_list;

	if (!(conv_list = (t_conv *)malloc(sizeof(t_conv) * 11)))
		exit_error("error: malloc failed\n", 0);
	conv_list[0].conv = 'c';
	conv_list[1].conv = 's';
	conv_list[2].conv = 'p';
	conv_list[3].conv = 'd';
	conv_list[4].conv = 'i';
	conv_list[5].conv = 'o';
	conv_list[6].conv = 'u';
	conv_list[7].conv = 'x';
	conv_list[8].conv = 'X';
	conv_list[10].conv = '%';
	conv_list[9].conv = 'b';
	conv_list[0].f = &conv_c;
	conv_list[1].f = &conv_s;
	conv_list[2].f = &conv_p;
	conv_list[3].f = &conv_d;
	conv_list[4].f = &conv_d;
	conv_list[5].f = &conv_o;
	conv_list[6].f = &conv_u;
	conv_list[7].f = &conv_x;
	conv_list[8].f = &conv_big_x;
	conv_list[10].f = &conv_percentage;
	conv_list[9].f = &conv_binary;
	return (conv_list);
}

static char		*get_mod(char *specs)
{
	if (ft_strstr(specs, "hh"))
		return ("hh");
	else if (ft_strstr(specs, "ll"))
		return ("l");
	else if (ft_strchr(specs, 'h'))
		return ("h");
	else if (ft_strchr(specs, 'l'))
		return ("l");
	else if (ft_strchr(specs, 'j'))
		return ("j");
	else if (ft_strchr(specs, 'z'))
		return ("z");
	else
		return (ft_strdup(""));
}

char			*parse_conv(va_list ap, char *specs)
{
	char	*str;
	int		i;
	t_conv	*conv_list;
	char	*mod;
	char	conv;

	mod = get_mod(specs);
	conv = specs[ft_strlen(specs) - 1];
	conv_list = initialize_conv_functions();
	i = -1;
	if (conv == 'f')
		str = conv_f(ap, specs);
	else
		while (++i < 11)
			if (conv == conv_list[i].conv)
			{
				str = conv_list[i].f(ap, mod);
				i = 11;
			}
	free(conv_list);
	return (str);
}
