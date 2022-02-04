/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel2buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:27:12 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:56 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel2buff(t_pixel a, int color, t_vars *buff)
{
	char	*dst;

	if ((a.x >= 0 && a.x < buff->width)
		&& (a.y >= 0 && a.y < buff->heigth))
	{
		dst = buff->addr + buff_offset(a.x, a.y, buff);
		*(unsigned int *) dst = color;
	}
}

int	buff_offset(int x, int y, t_vars *buff)
{
	int	row;
	int	column;

	row = y * buff->line_length;
	column = x * (buff->bits_per_pixel / 8);
	return (row + column);
}
