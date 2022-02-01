/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:12:11 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/01 11:15:57 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_drawblank(t_vars *vars)
{
	t_pixel	a;
	int		i;
	int		j;

	i = 0;
	while (i < vars->heigth)
	{
		j = 0;
		while (j < vars->width)
		{
			a.x = j;
			a.y = i;
			pixel2buff(a, C_SB, vars);
			j++;
		}
		i++;
	}
}
