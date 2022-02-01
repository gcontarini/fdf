/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:03:45 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/01 11:56:16 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_zoom(t_obj *obj, t_vars *vars, double dz)
{
	int			i;
	int			j;

	dz += 1;
	i = 0;
	while (i < obj->heigth)
	{
		j = 0;
		while (j < obj->width)
		{
			obj->vec[i][j] = scalar_vector(dz, obj->vec[i][j]);
			j++;
		}
		i++;
	}
}
