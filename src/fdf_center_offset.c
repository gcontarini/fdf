/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center_offset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:08:15 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:22:09 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	fdf_center_offset(t_obj *obj, t_vars *buff)
{
	t_vector	midpoint;
	t_vector	offset;
	t_pixel		a;

	midpoint = obj_center(obj);
	a.x = (buff->width / 2);
	a.y = (buff->heigth / 2);
	offset = img2vector(a);
	offset.x -= midpoint.x;
	offset.y -= midpoint.y;
	offset.z -= midpoint.z;
	return (offset);
}

t_vector	obj_center(t_obj *obj)
{
	t_vector	center;
	int			i;
	int			j;

	center = vector(0.0, 0.0, 0.0);
	i = 0;
	while (i < obj->heigth)
	{
		j = 0;
		while (j < obj->width)
		{
			center.x += obj->vec[i][j].x;
			center.y += obj->vec[i][j].y;
			center.z += obj->vec[i][j].z;
			j++;
		}
		i++;
	}
	center.x = center.x / (obj->width * obj->heigth);
	center.y = center.y / (obj->width * obj->heigth);
	center.z = center.z / (obj->width * obj->heigth);
	return (center);
}

t_vector	vec_offset(t_vector a, t_vector offset)
{
	t_vector	vec;

	vec.x = a.x + offset.x;
	vec.y = a.y + offset.y;
	return (vec);
}
