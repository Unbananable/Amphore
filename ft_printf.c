#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char			*converter(char *specs, va_list ap)
{
	char	*str;

	str = parse_conv(ap, specs);
	str = parse_flag(str, specs);
	free(specs);
	return(str);
}

char			*ft_concaten(char *s1, const char *s2, size_t len1, size_t len2)
/* On cherche a concatener deux string, en prenant les len1 premier bytes de s1
 * et les len2 premier bytes de s2, on obtient res */
{
	char	*res;
	size_t	size;

	size = len1 + len2;
	res = ft_strnew(size);
	if (!res)
		return (NULL);
	if (res && len1)
	{
		ft_strncpy(res, s1, len1);
		free(s1);
	}
	ft_strncpy(res + len1, s2, len2);
	return (res);
}

void			full_length(const char *format, va_list ap, char **res)
/* On avance dans format jusqu'à trouver le % tant convoité, res devient une str
 * égale à toute la premiere partie avant le %. Ensuite, on applique la fonction
 * encore inexistante 'fct' qui va nous return la size du 'contenu' du %. Dans 
 * fct, tmp devient alors la ressource qui va stocker la string a laquelle on 
 * a appliqué les différents flags (en jouant avec les adresses ça devrait 
 * etre jouable), c'est dans fct qu'on va faire strlen de ce tmp, et obtenir la
 * size, ici stockée dans i. Ensuite on retourne dans full_length, et res 
 * devient la chaine pré-% concatenée a la chaine post-% (traitée avec les 
 * flags et tout). Ensuite, on calcule la len de la string (avant la premiere 
 * virgule des parametres de printf) a partir du %, et on donne a res une valeur
 * equivalente à la premiere string du printf (avant la premiere virgule) avec
 * un argument post-% traité et valide. Ensuite on fait total_len+1 pour le \0 
 * de fin, et on return total_len. Pfiou ! */
{
	char		*tmp;
	size_t		i;
	size_t		total_len;
	char		*specs;
	int			j;

	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			*res = ft_concaten(*res, format, total_len, i);
			total_len += i;
			format += i + 1;
			j = 0;
			while (format[j] && !ft_strchr("cspdiouxXf", format[j]))
				j++;
			specs = ft_strsub(format, 0, j + 1);
			format += j + 1;
			tmp = converter(specs, ap);
			*res = ft_concaten(*res, tmp, total_len, ft_strlen(tmp));
			total_len += ft_strlen(tmp);
			i = 0;
/* i=0: Poursuite dans la string en cas de plusieurs % (on reprend ou on s'était
 * arreté grace au (format += i+1) ligne 53 */
		}
		else
			i++;
	}
	i = ft_strlen(format);
	*res = ft_concaten(*res, format, ft_strlen(*res), i);
}

int				ft_printf(const char *format, ...)
{
	char		*res;
	va_list		ap;

	res = NULL;
	va_start(ap, format);
	full_length(format, ap, &res);
	write(1, res, ft_strlen(res));
	free(res);
	va_end(ap);
	return((int)ft_strlen(res));
}
