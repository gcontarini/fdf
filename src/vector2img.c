#include "fdf.h"

t_pixel	vector2img(t_vector a, t_obj *obj, t_vars *buff)
{
	t_pixel	pixel;
	int	x_margin;
	int	y_margin;

	x_margin = (int) nearbyint((double) buff->width * MARGIN_PERC);
	y_margin = (int) nearbyint((double) buff->width * MARGIN_PERC);
	pixel.x = x_margin + (int) nearbyint(a.x * width_transform(obj->width, buff));
	pixel.y =  buff->heigth - y_margin - (int) nearbyint(a.y * heigth_transform(obj->heigth, buff));
	//printf("X: %i Y: %i\n", pixel.x, pixel.y);
	return (pixel);
}

double	width_transform(int img_width, t_vars *buff)
{
	double	x_margin;

	x_margin = ((double) buff->width * MARGIN_PERC * 2);
	return ((buff->width - x_margin) / (double) (img_width - 1));
}

double	heigth_transform(int img_heigth, t_vars *buff)
{
	double	y_margin;

	y_margin = ((double) buff->heigth * MARGIN_PERC * 2);
	return ((buff->heigth - y_margin) / (double) (img_heigth - 1));
}
