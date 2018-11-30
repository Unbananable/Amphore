/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:20:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/30 16:11:38 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_printf_d(char *flags, char *string)
{
	char *str = "Reloue";
	char *str2;
	char *str3;

	str3 = ft_strdup(string);
	str2 = parse_accufield(str3, flags);
	str2 = parse_flag(str2, flags);
	ft_putstr(str2);
}
