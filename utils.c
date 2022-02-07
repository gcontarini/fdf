/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:12:17 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:28:49 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	fdf_itof(int integer, int frac)
{
	double	n;
	double	f;

	n = (double) integer;
	f = (double) frac;
	while (f >= 1.0)
		f /= 10.0;
	if (n >= 0.0)
		n += f;
	else
		n -= f;
	return (n);
}

int	fdf_atoiuhex(const char *str)
{
	const char	*p;
	double		n;
	int			nbr;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	n = 0.0;
	p = str + 1;
	while (*p && ft_strchr(UPHEX_BASE, *p))
	{
		p++;
		n += 1.0;
	}
	nbr = 0;
	while (*str && ft_strchr(UPHEX_BASE, *str))
	{
		if (*str >= '0' && *str <= '9')
			nbr += (*str++ - '0') * (int) pow(16.0, n--);
		else
			nbr += (*str++ - 55) * (int) pow(16.0, n--);
	}
	return (nbr);
}
