/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:54:00 by anleclab          #+#    #+#             */
/*   Updated: 2018/12/06 19:54:04 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int		move_right(char *str, int nbchar, char c)
{
	int		i;

	i = ft_strlen(str) - nbchar;
	while (str[i] == ' ')
		i++;
	if (str[i])
		return (0);
	i = ft_strlen(str) - 1;
	while (i - nbchar >= 0)
	{
		str[i] = str[i - nbchar];
		i--;
	}
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (1);
}

char	*suffix(char *suf, char *str)
{
	char	*ret;
	int		init_sp;
	int		end_sp;
	int		i;

	init_sp = 0;
	while (str[init_sp] == ' ')
		init_sp++;
	end_sp = 0;
	while (str[ft_strlen(str) - 1 - end_sp] == ' ')
		end_sp++;
	if (init_sp + end_sp >= (int)ft_strlen(suf))
	{
		i = ft_strlen(suf) - 1;
		while (--init_sp >= 0 && i >= 0)
		{
			str[init_sp] = suf[i];
			i--;
		}
		if (i >= 0)
		{
			move_right(str, i + 1, '0');
			while (i >= 0)
			{
				str[i] = suf[i];
				i--;
			}
		}
		return (str);
	}
	if (!(ret = ft_strnew(ft_strlen(str) + ft_strlen(suf) - init_sp - end_sp + 1)))
		exit_error("error: malloc failed\n", 1, str);
	ft_strncpy(ret, suf, ft_strlen(suf));
	ft_strncat(ret, str + init_sp, ft_strlen(str) - init_sp - end_sp);
	free(str);
	return (ret);
}
