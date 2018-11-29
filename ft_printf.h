/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:15:45 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/11/29 18:11:37 by dtrigalo         ###   ########.fr       */
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
char			*parse_accufield(char *str, char *flag);
char			*flag_plus(char *str, char c);
char			*flag_minus(char *str, char c);
char			*flag_space(char *str, char c);
char			*flag_hash(char *str, char c);
char			*flag_zero(char *str, char c);
char			*accuracy(char *str, int n);
char			*field_width(char *str, int n);

#endif
