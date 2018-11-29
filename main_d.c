/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:20:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 16:28:29 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	char *str = "Reloue";
	char *str2;

	str2 = parse_flag(av[2], av[1]);
	ft_putstr(str2);
	return (0);
}
