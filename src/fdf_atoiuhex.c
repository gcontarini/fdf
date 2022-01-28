#include "fdf.h"

int	fdf_atoiuhex(const char *str)
{
	double		n;
	int		nbr;
	const char	*p;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	n = 0.0;
	p = str + 1;
	while (*p && ft_strchr(UPHEX_BASE, *p))
	{
		p++;
		n += 1.0;
	}
	nbr = 0;;
	while (*str && ft_strchr(UPHEX_BASE, *str))
	{
		if (*str >= '0' && *str <= '9')
			nbr += (*str++ - '0') * (int) pow(16.0, n--);
		else
			nbr += (*str++ - 55) * (int) pow(16.0, n--);
	}
	return (nbr);
}
