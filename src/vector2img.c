#include "fdf.h"

t_pixel	vector2img(t_vector a, t_obj *obj, t_vars *buff)
{
	t_pixel	pixel;

	pixel.x = (int) nearbyint(a.x);
	pixel.y =  (int) nearbyint(a.y);
	return (pixel);
}

t_vector	img2vector(t_pixel a, t_obj *obj, t_vars *buff)
{
	t_vector	vec;

	vec.x = (double) a.x;
	vec.y = (double) a.y;
	return (vec);
}
