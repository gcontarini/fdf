/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:03:45 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:19:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_zoom(t_vars *vars, int x, int y, double dz)
{
	int			i;
	int			j;

	dz += 1;
	i = 0;
	while (i < vars->obj->heigth)
	{
		j = 0;
		while (j < vars->obj->width)
		{	
			vars->obj->vec[i][j].x -= x - vars->obj->center_offset.x;
			vars->obj->vec[i][j].y -= y - vars->obj->center_offset.y;
			vars->obj->vec[i][j] = scalar_vector(dz, vars->obj->vec[i][j]);
			vars->obj->vec[i][j].x += x - vars->obj->center_offset.x;
			vars->obj->vec[i][j].y += y - vars->obj->center_offset.y;
			j++;
		}
		i++;
	}
}

void	fdf_gammazoom(t_vars *vars, int keycode)
{
	double	delta_y;
	double	delta;
	int		i;
	int		j;

	delta = -0.6;
	if (keycode == 13)
		delta = 0.6;
	i = 0;
	while (i < vars->obj->heigth)
	{
		j = 0;
		while (j < vars->obj->width)
		{	
			delta_y = (sqrt(6.0) * vars->obj->vec[i][j].og_z) / 3.0;
			vars->obj->vec[i][j].y += delta_y * delta;
			j++;
		}
		i++;
	}
}

void	fdf_rotate(t_vars *vars, int keycode)
{
	double	delta;
	int		i;
	int		j;

	delta = .1;
	if (keycode == 14)
		delta = -.1;
	i = 0;
	while (i < vars->obj->heigth)
	{
		j = 0;
		while (j < vars->obj->width)
		{	
			vars->obj->vec[i][j] = rotate(vars->obj->vec[i][j], delta);
			j++;
		}
		i++;
	}
}
