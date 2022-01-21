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

	w_lim = (int) (a.x + 1);
	h_lim = (int) (a.y + 1);
	n_h = orto_projection(vector(a.x + 1, a.y, a.z), zoom);
	n_v = orto_projection(vector(a.x, a.y + 1, a.z), zoom);
	a = orto_projection(a, zoom);
	if (w_lim <= obj->width)
		draw_line(vector2img(a, obj, buff), vector2img(n_h, obj, buff), C_SW, buff);
	if (h_lim <= obj->heigth)
		draw_line(vector2img(a, obj, buff), vector2img(n_v, obj, buff), C_SW, buff);
}
