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
	t_vector	a_hat;
	t_vector	b_hat;

	a_hat = vec_offset(a, obj->center_offset);
	b_hat = vec_offset(b, obj->center_offset);
	draw_line(vector2img(a_hat, obj, buff), vector2img(b_hat, obj, buff), C_SW, buff);
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
