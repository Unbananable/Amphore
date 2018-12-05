#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char			*converter(char *specs, va_list ap)
{
	char	*str;

	str = parse_conv(ap, specs);
	str = parse_accufield(str, specs);
	str = parse_flag(str, specs);
	return(str);
}
/* On peut add les bold colors */
static int	color_change_counter(const char *format)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (format[++i])
	{
		if (format[i] == '{')
		{
			if (ft_strstr(format, "{red}"))
			{
				cnt++;
				i += 5;
			}
			else if (ft_strstr(format, "{green}"))
			{
				cnt++;
				i += 7;
			}
			else if (ft_strstr(format, "{yellow}"))
			{
				cnt++;
				i += 8;
			}
			else if (ft_strstr(format, "{blue}"))
			{
				cnt++;
				i += 6;
			}
			else if (ft_strstr(format, "{magenta}"))
			{
				cnt++;
				i += 9;
			}
			else if (ft_strstr(format, "{cyan}"))
			{
				cnt++;
				i += 6;
			}
		}
	}
	return (cnt);
}

static char *selected_color(const char *format)
{

	if (ft_strnequ(format, "{red}", 5))
		return ("\033[0;31m");
	if (ft_strnequ(format, "{green}", 7))
		return ("\033[0;32m");
	if (ft_strnequ(format, "{yellow}", 8))
		return ("\033[0;33m");
	if (ft_strnequ(format, "{blue}", 6))
		return ("\033[0;34m");
	if (ft_strnequ(format, "{magenta}", 9))
		return ("\033[0;35m");
	if (ft_strnequ(format, "{cyan}", 6))
		return ("\033[0;36m");
	return (NULL);
}

static int	len_to_skip(const char *format)
{

//	printf("format in len_to_skip: %s\n", format);
	if (ft_strnequ(format, "{red}", 5))
		return (5);
	if (ft_strnequ(format, "{green}", 7))
		return (7);
	if (ft_strnequ(format, "{yellow}", 8))
		return (8);
	if (ft_strnequ(format, "{blue}", 6))
		return (6);
	if (ft_strnequ(format, "{magenta}", 9))
		return (9);
	if (ft_strnequ(format, "{cyan}", 6))
		return (6);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char		*arg;
	char		*specs;
	int color_change_cnt;
	char *sel_col;
	int len;
	int c = 0;

	va_start(ap, format);
	i = 0;
	color_change_cnt = color_change_counter(format);//Nom à chier, mais j'ai pas l'esprit créatif là, ça attendra
	while (format[i])
	{
//		printf("i..: %d\n", i);
//		printf("format..: %s\n", format + i);
		if (format[i] == '{')
		{
			sel_col = selected_color(format + i);
			len = len_to_skip(format + i);
//			printf("len : %d\n", len);
			if (sel_col)
			{
//				printf("indicateur: %d\n", c++);
				write(1, format, i);
				write(1, sel_col, 7);
				format += len + i;
				i = 0;
				sel_col = NULL;
				len = 0;
			}
			else if (ft_strnequ(format + i, "{eoc}", 5))
			{
				write(1, "\033[0m", 3);
				format += 3;
				i = 0;
			}
		}
		else if(format[i] == '%')
		{
//			printf("!FORMAT! : (%s)\n et !!i!! : (%d)\n", format, i);
			write(1, format, i);
			format += i + 1;
//			printf("!!FORMAT APRES MOD!! : (%s)\n", format);
			i = 0;
			while (format[i] && !ft_strchr("cspdiouxXf", format[i]))
				i++;
//			printf("i value: %d\n", i);
			if (!format[i])
			{
				write(1, "error\n", 6);
				return (0);
			}
			specs = ft_strsub(format, 0, i + 1);
//			printf("!!!!SPECS!!!! : (%s)\n", specs);
//			printf("!!!!FORMAT!!!! : (%s)\n et !!!!i!!!! : (%d)\n", format, i);
			format += i + 1;
//			printf("!!!!FORMAT APRES MOD!!!! : (%s)\n", format);
			arg = converter(specs, ap);
			write(1, arg, ft_strlen(arg));
			free(specs);
			i = 0;
		}
		else
			i++;
	}
	write(1, format, ft_strlen(format));
	va_end(ap);
	return(26);
}
