/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:53:07 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/10 14:56:20 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

int		main(void)
{
	int		i;
	int		j;

	setlocale(LC_ALL, "");
	i = ft_printf("\nft_printf: %.2ls ", L"\u26a2");
	printf("(%d)\n", i - 1);
	j = printf("   printf: %.2ls ", L"\u26a2");
	printf("(%d)\n", j);
}
