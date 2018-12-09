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

char	*parse_accufield(char *str, char *specs)
{
	int		i;
	int		isnulc;
	char	conv;

	conv = specs[ft_strlen(specs) - 1];
	isnulc = ((conv == 'c' && ft_strstr(str, "^@")) ? 1 : 0);
	i = 0;
	while (specs[i] && specs[i] != '.')
		i++;
	if (specs[i] == '.')
	{
		i++;
		str = accuracy(str, (size_t)ft_atoi(specs + i), conv);
		while (specs[i] <= '9' && specs[i] >= '0')
			specs[i++] = '%';
	}
	i = 0;
	while (specs[i] &&
			!((i == 0 || specs[i - 1] != '.') && specs[i] > '0' && specs[i] <= '9'))
		i++;
	if (specs[i])
	{
		str = field_width(str, (size_t)ft_atoi(specs + i) + isnulc);
		while (specs[i] >= '0' && specs[i] <= '9')
			specs[i++] = '%';
	}
	return (str);
}
