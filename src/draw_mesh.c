#include "fdf.h"

void	draw_mesh(t_obj *obj, t_vars *buff)
{
	t_vector	a;
	t_vector	b;
	int		i;
	int		j;

	i = 1;
	while (i < obj->width)
	{
		j = 1;
		while (j < obj->heigth)
		{
			a = obj->vec[i][j];
			b = obj->vec[i][j - 1];
			draw_conlines(a, b, obj, buff);
			b = obj->vec[i - 1][j];
			draw_conlines(a, b, obj, buff);
			j++;
		}
		i++;
	}
	draw_outline(obj, buff);
}

void	draw_conlines(t_vector a, t_vector b, t_obj *obj, t_vars *buff)
{
	t_pixel	a_hat;
	t_pixel	b_hat;

	a_hat = vector2img(a, obj, buff);
	b_hat = vector2img(b, obj, buff);
	a_hat.x = a_hat.x + obj->center_offset.x;
	a_hat.y = a_hat.y + obj->center_offset.y;
	b_hat.x = b_hat.x + obj->center_offset.x;
	b_hat.x = b_hat.y + obj->center_offset.y;
	draw_line(a_hat, b_hat, C_SW, buff);
}

void	draw_outline(t_obj *obj, t_vars *buff)
{
	t_vector	a;
	t_vector	b;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < obj->width)
	{
		a = obj->vec[i][j];
		b = obj->vec[i - 1][j];
		draw_conlines(a, b, obj, buff);
		i++;
	}
	i = 0;
	j = 1;
	while (j < obj->heigth)
	{
		a = obj->vec[i][j - 1];
		b = obj->vec[i][j];
		draw_conlines(a, b, obj, buff);
		j++;
	}
}
