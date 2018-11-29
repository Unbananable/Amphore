/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:15:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 16:42:14 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_conv
{
	char	c;
	char	*(*f)(void);
}				t_conv;

typedef struct	s_flag
{
	char	c;
	char	*(*f)(char *, char);
}				t_flag;

char			*parse_flag(char *str, char *flag);

#endif
