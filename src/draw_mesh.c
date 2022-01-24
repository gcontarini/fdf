#include "fdf.h"

void	draw_mesh(t_obj *obj, t_vars *buff)
{
	t_vector	a;
	t_vector	b;
	int		i;
	int		j;

	draw_outline(obj, buff);
	i = 1;
	while (i < obj->width)
	{
		j = 1;
		while (j < obj->heigth)
		{
			a = vector((double) i, (double) j, obj->z[i][j]);
			b = vector((double) i, (double) j - 1, obj->z[i][j - 1]);
			draw_conlines(a, b, -10, obj, buff);
			b = vector((double) i - 1, (double) j, obj->z[i - 1][j]);
			draw_conlines(a, b, -10, obj, buff);
			j++;
		}
		i++;
	}
}

void	draw_conlines(t_vector a, t_vector b, double zoom, t_obj *obj, t_vars *buff)
{
	t_vector	a_hat;
	t_vector	b_hat;

	a_hat = orto_projection(a, zoom);
	b_hat = orto_projection(b, zoom);
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
		a = vector((double) i, (double) j, obj->z[i][j]);
		b = vector((double) i - 1, (double) j, obj->z[i - 1][j]);
		draw_conlines(a, b, -10, obj, buff);
		i++;
	}
	i = 0;
	j = 1;
	while (j < obj->heigth)
	{
		a = vector((double) i, (double) j - 1, obj->z[i][j - 1]);
		b = vector((double) i, (double) j, obj->z[i][j]);
		draw_conlines(a, b, -10, obj, buff);
		j++;
	}
}
