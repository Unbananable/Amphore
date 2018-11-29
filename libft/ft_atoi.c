/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:36:50 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/14 17:52:25 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (ft_isdigit((int)*str))
	{
		nbr = 10 * nbr + *str - 48;
		str++;
	}
	return (nbr * sign);
}
