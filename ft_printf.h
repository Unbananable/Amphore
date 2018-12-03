/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:15:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/03 15:48:48 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_conv
{
	char	conv;
	char	*(*f)(va_list, char *);
}				t_conv;

typedef struct	s_flag
{
	char	c;
	char	*(*f)(char *, char);
}				t_flag;

char			*parse_flag(char *str, char *flag);
char			*parse_accufield(char *str, char *flag);
char			*parse_conv(va_list ap, char conv);
char			*conv_d(va_list ap, char *mod);
char			*conv_i(va_list ap, char *mod);
char			*conv_o(va_list ap, char *mod);
char			*conv_u(va_list ap, char *mod);
char			*conv_x(va_list ap, char *mod);
char			*conv_big_x(va_list ap, char *mod);
char			*conv_f(va_list ap, char *mod);
char			*conv_c(va_list ap, char *mod);
char			*conv_s(va_list ap, char *mod);
char			*conv_p(va_list ap, char *mod);
char			*conv_percentage(va_list ap, char *mod);
char			*flag_plus(char *str, char c);
char			*flag_minus(char *str, char c);
char			*flag_space(char *str, char c);
char			*flag_hash(char *str, char c);
char			*flag_zero(char *str, char c);
char			*accuracy(char *str, int n, char c);
char			*field_width(char *str, int n);

#endif
