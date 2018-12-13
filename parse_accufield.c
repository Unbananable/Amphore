/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_accufield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:35:36 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/13 16:07:50 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	specs_check(char *specs)
{
	int		i;

	i = 0;
	while (specs[i] &&
			!((i == 0 || specs[i - 1] != '.') &&
				specs[i] > '0' && specs[i] <= '9'))
		i++;
	return (i);
}

char		*parse_accufield(char *str, char *specs)
{
	int		i;
	int		isnulc;
	char	conv;
	int		accu;

	conv = specs[ft_strlen(specs) - 1];
	isnulc = ((conv == 'c' && ft_strstr(str, "^@")) ? 1 : 0);
	i = 0;
	while (specs[i] && specs[i] != '.')
		i++;
	if (specs[i] == '.')
	{
		i++;
		accu = ft_atoi(specs + i);
		accu = (accu < 0 ? 0 : accu);
		if (!(str = accuracy(str, (size_t)accu, specs)))
			exit_error("error: malloc failed\n", 1, specs);
		while (specs[i] <= '9' && specs[i] >= '0')
		specs[i++] = '%';
	}
	i = specs_check(specs);
	if (specs[i])
	{
		if (!(str = field_width(str, (size_t)ft_atoi(specs + i) + isnulc)))
			exit_error("error: malloc failed\n", 2, str, specs);
		while (specs[i] >= '0' && specs[i] <= '9')
			specs[i++] = '%';
	}
	return (str);
}
