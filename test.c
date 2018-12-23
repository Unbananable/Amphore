#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		main(void)
{
//	int		i;
//	int		j;

//	printf("dbl = %Lf\n", ft_ldouble_power(10, 30));
	printf("   printf: %Lf\n", (long double)999999999999999999999999999999999999999225463435425.32346513214699999);
//	printf(" (%d)\n", i);
	ft_printf("ft_printf: %Lf\n", (long double)999999999999999999999999999999999999999225463435425.32346513214699999);
//	printf(" (%d)\n", j);
	return (0);
}
