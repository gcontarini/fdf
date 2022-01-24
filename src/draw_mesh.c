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
			a = vector((double) i, (double) j, obj->z[i][j]);
			b = vector((double) i, (double) j - 1, obj->z[i][j - 1]);
			draw_conlines(a, b, -10, obj, buff);
			b = vector((double) i - 1, (double) j, obj->z[i - 1][j]);
			draw_conlines(a, b, -10, obj, buff);
			j++;
		}
		i++;
	}
	draw_outline(obj, buff);
}

void	draw_conlines(t_vector a, t_vector b, double zoom, t_obj *obj, t_vars *buff)
{
	t_vector	a_hat;
	t_vector	b_hat;

	zoom++;
	a_hat = orto_projection(a);
	b_hat = orto_projection(b);
	// Before here has to pass all projected values to
	// obj to find the heigth and width values
	// And translate to make things in the middle
	printf("%f %f %f\n", a_hat.x, a_hat.y, a_hat.z);
	printf("%f %f %f\n", b_hat.x, b_hat.y, b_hat.z);
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
