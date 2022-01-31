#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars		v;
	t_obj		obj;

	if (ac != 2)
		return (-1);
	fdf_winsize(&v, &obj, 900, 800);
	if (!fdf_open_objfile(av[1], &obj, &v))
		return (-1);
	v.mlx = mlx_init();
	if (!v.mlx)
		return (fdf_xerror(&obj, NULL));
	v.win = mlx_new_window(v.mlx, v.width, v.heigth, "fdf");
	v.img = mlx_new_image(v.mlx, v.width, v.heigth);
	if (!v.win || !v.img)
		return (fdf_xerror(&obj, &v));
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length, &v.endian);
	fdf_registerhooks(&v);
	fdf_drawmesh(&obj, &v);
	mlx_loop(v.mlx);
	return (0);
}

void	fdf_winsize(t_vars *vars, t_obj *obj, int width, int heigth)
{
	vars->width = width;
	vars->heigth = heigth;
	vars->obj = obj;
}
