/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:42:25 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/18 10:36:00 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strappend(char *src, char c)
{
	char	*str;
	char	*str2;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2))))
		return (NULL);
	str2 = ft_stpcpy(str, src);
	*str2++ = c;
	*str2++ = '\0';
	return (str);
}

static void		ft_recursive_append_dig(char **str, int n)
{
	if ((n / 10) > 0)
		ft_recursive_append_dig(str, (n / 10));
	*str = ft_strappend(*str, ((n % 10) + 48));
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(1)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str = ft_strappend(str, '-');
	}
	ft_recursive_append_dig(&str, n);
	str[ft_strlen(str)] = '\0';
	return (str);
}
