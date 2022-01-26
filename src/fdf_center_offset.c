#include "fdf.h"

t_pixel	fdf_center_offset(t_obj *obj, t_vars *buff)
{
	t_pixel	center;

	center = obj_center(obj, buff);
	center.x = (buff->width / 2.0) - center.x;
	center.y = (buff->heigth / 2.0) - center.y;
	return (center);
}

t_pixel	obj_center(t_obj *obj, t_vars *buff)
{
	t_vector	center;
	int			i;
	int			j;
			
	center = vector(0.0, 0.0, 0.0);
	i = 0;
	while (i < obj->width)
	{
		j = 0;
		while (j < obj->heigth)
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
	return (vector2img(center, obj, buff));
}
