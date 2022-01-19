#include "fdf.h"

void	draw_mesh(t_obj *obj, t_vars *buff)
{
	t_vector	curr;
	int		i;
	int		j;

	i = 0;
	while (i < obj->width)
	{
		j = 0;
		while (j < obj->heigth)
		{
			curr = vector((double) i, (double) j, obj->z[i][j]);
			draw_conlines(curr, -10, obj, buff);
			j++;
		}
		i++;
	}
}

void	draw_conlines(t_vector a, double zoom, t_obj *obj, t_vars *buff)
{
	t_vector	n_h;
	t_vector	n_v;
	int		w_lim;
	int		h_lim;

	n_h = vector(a.x + 1, a.y, a.z);
	n_v = vector(a.x, a.y + 1, a.z);
	w_lim = (int) n_h.x;
	h_lim = (int) n_v.y;
	a = orto_projection(a, zoom, buff);
	n_h = orto_projection(n_h, zoom, buff);
	n_v = orto_projection(n_v, zoom, buff);
	if (w_lim <= obj->width)
		draw_line(vector2img(a, obj, buff), vector2img(n_h, obj, buff), C_SW, buff);
	if (h_lim <= obj->heigth)
		draw_line(vector2img(a, obj, buff), vector2img(n_v, obj, buff), C_SW, buff);
}
