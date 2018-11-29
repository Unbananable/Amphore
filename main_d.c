/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:20:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 18:11:39 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	char *str = "Reloue";
	char *str2;
	char *str3;

	if (ac != 3)
	{
		ft_putstr("error");
		return (0);
	}
	str3 = ft_strdup(av[2]);
	str2 = parse_accufield(str3, av[1]);
	str2 = parse_flag(str2, av[1]);
	ft_putstr(str2);
	return (0);
}
