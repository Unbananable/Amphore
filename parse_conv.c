#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

static t_conv	*initialize_conv_functions(void)
{
	t_conv	*conv_list;

	if (!(conv_list = (t_conv *)malloc(sizeof(t_conv) * 10)))
		return;
	conv_list[0].conv = 'c';
	conv_list[1].conv = 's';
	conv_list[2].conv = 'p';
	conv_list[3].conv = 'd';
	conv_list[4].conv = 'i';
	conv_list[5].conv = 'o';
	conv_list[6].conv = 'u';
	conv_list[7].conv = 'x';
	conv_list[8].conv = 'X';
	conv_list[9].conv = 'f';
	conv_list[0].f = &conv_c;
	conv_list[1].f = &conv_s;
	conv_list[2].f = &conv_p;
	conv_list[3].f = &conv_d;
	conv_list[4].f = &conv_i;
	conv_list[5].f = &conv_o;
	conv_list[6].f = &conv_u;
	conv_list[7].f = &conv_x;
	conv_list[8].f = &conv_big_x;
	conv_list[9].f = &conv_f;
	return (conv_list);
}

char		*parse_conv(va_list *ap, char conv)
{
	char	*str;
	int		i;
	t_conv	*conv_list;

	list = initialize_conv_functions();
	i = -1;
	while (++i < 10)
		if (conv == conv_list[i].conv)
		{
			str = conv_list[i].f(ap);
			i = 10;
		}
	free(conv_list);
	return (str);
}
