/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:15:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/06 19:11:32 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

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

typedef struct	s_form
{
	int			i;
	int			cnt;
	const char	*fmt;
}				t_form;

int				ft_printf(const char *format, ...);
int				param_len(const char *format);
char			*parse_color(const char *format);
char			*parse_flag(char *str, char *flag);
char			*parse_accufield(char *str, char *flag);
char			*parse_conv(va_list ap, char *specs);
char			*conv_d(va_list ap, char *mod);
char			*conv_i(va_list ap, char *mod);
char			*conv_o(va_list ap, char *mod);
char			*conv_u(va_list ap, char *mod);
char			*conv_x(va_list ap, char *mod);
char			*conv_big_x(va_list ap, char *mod);
char			*conv_f(va_list ap, char *specs);
char			*conv_c(va_list ap, char *mod);
char			*conv_s(va_list ap, char *mod);
char			*conv_p(va_list ap, char *mod);
char			*conv_percentage(va_list ap, char *mod);
char			*flag_plus(char *str, char c);
char			*flag_minus(char *str, char c);
char			*flag_space(char *str, char c);
char			*flag_hash(char *str, char c);
char			*flag_zero(char *str, char c);
char			*accuracy(char *str, size_t len, char c);
char			*field_width(char *str, size_t len);
void			exit_error(char *er_mess, int nbfree, ...);
int				move_right(char *str, int nbchar, char c);
char			*suffix(char *suf, char *str);

#endif
