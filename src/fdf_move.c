/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:05:04 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/01 12:18:16 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_updown(t_vars *vars, int keycode)
{
	int	delta;
	int	i;
	int	j;

	delta = 20;
	if (keycode == 125)
		delta = -20;
	i = 0;
	while (i < vars->obj->heigth)
	{
		j = 0;
		while (j < vars->obj->width)
		{
			vars->obj->vec[i][j].y += delta;
			j++;
		}
		i++;
	}
}

void	fdf_leftright(t_vars *vars, int keycode)
{
	int	delta;
	int	i;
	int	j;

	delta = 20;
	if (keycode == 123)
		delta = -20;
	i = 0;
	while (i < vars->obj->heigth)
	{
		j = 0;
		while (j < vars->obj->width)
		{
			vars->obj->vec[i][j].x += delta;
			j++;
		}
		i++;
	}
}
