#include "libft/libft.h"

static char	*double_to_binary(double dbl)
{
	char	binary[65];
	double	byte;
	int		i;

	binary[64] = 0;
	byte = -0;
	i = -1;
	while (++i < 65)
	{
		binary[i] = (byte & dbl) ? '1' : '0';
		byte >>= 1;
	}
	return (binary);
}

static int	binary_to_int(char *binary)
{
	int		i;
	int		res;
	int		pow;

	res = 0;
	pow = 1;
	i = ft_strlen(binary);
	while (--i >= 0)
	{
		res += str[i] * pow;
		pow *= 2;
	}
	return (res);
}

static char	*add_exp(char *mant, int exp)
{
	char	*res;

	if (exp =< 0)
	{
		if (!(res = ft_strnew(55 + exp)))
			exit_error("error: malloc failed\n", 0);
		ft_strncpy(res, "0.", 2);
		i = 2;
		while (i < exp + 2)
			res[i++] = '0';
		ft_strncat(res, mant, 52);
	}
	else if (exp < 52)
	{
		if (!(res = ft_strnew(54)))
			exit_error("error: malloc failed\n", 0);
		ft_strncpy(res, mant, exp);
		res[exp] = '.';
		ft_strncat(res, mant + exp, 52 - exp);
	}
	else
	{
		if (!(res = ft_strnew(exp - 51)))
			exit_error("error: malloc failed\n", 0);
		ft_strncpy(res, mant, 52);
		i = 52;
		while (i < exp - 52)
			res[i++] = '0';
	}
	free(mant);
	return (res);
}

static char	*add_str(char *str, int nb, int len)
{
	int		add;
	int		rm;
	char	temp;

	if (!nb)
		return (str);
	if (len < 0)
	{
		if (!(temp = ft_strnew(ft_strlen(str) + 2)))
			exit_error("error: malloc failed\n", 1, str);
		temp[0] = '0';
		ft_strncpy(temp + 1, str, ft_strlen(str));
		free(str);
		str = temp;
		len = 0;
	}
	add = nb + str[len];
	str[len] = '0' + add % 10;
	return (add_str(str, add / 10, len--));
}

static char	*binary_to_dec(char *binary)
{
	char	*res;
	int		i;
	int		pow;

	if (!(res = ft_strnew(2)))
		exit_error("malloc_failed\n", 0);
	res[0] = '0';
	i = ft_strlen(binary);
	pow = 1;
	while (--i >= 0)
	{
		add_str(res, pow * binary[i], ft_strlen(res) - 1);
		pow *= 2;
	}
	return (res);
}

static char	*binary_to_arg(char *binary, int accu)
{
	char	*tmp;
	int		exp;
	char	*mant;
	int		i;
	char	*res;

	tmp = ft_strsub(binary, 1, 11);
	exp = binary_to_int(tmp) - 1023;
	free(tmp);
	mant = ft_strsub(binary, 12, 52);
	mant = add_exp(mant, exp);
	i = 0;
	while (mant[i] && mant[i] != '.')
		i++;
	mant[i] = 0;
	res = binary_to_dec(mant);
//recuperer la partie decimale
	if (accu)
	{
		if (!(tmp = ft_strnew(ft_strlen(res) + 2 + accu)))
			exit_error("error: malloc failed\n", 3, binary, mant, res);
		ft_strncpy(tmp, res, ft_strlen(res));
		tmp[ft_strlen(res)] = '.';
//ajouter la partie decimale	
	}
}

char		*conv_f(va_list ap, char *specs)
{
	double	dbl;
	char	*binary;
	char	*arg;
	int		accu;
	int		i;

	dbl = va_arg(ap, double);
	binary = double_to_binary(dbl);
	accu = 6;
	i = -1;
	while (str[++i])
		if (str[i] == '.')
			accu = ft_atoi(str + i + 1);
	arg = binary_to_arg(binary, accu);
	return (arg);
}
