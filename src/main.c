#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars		v;
	t_obj		obj;

	if (ac != 2)
		return (-1);
	v.obj = &obj;
	v.width = 900;
	v.heigth = 800;
	if (!fdf_open_objfile(av[1], &obj, &v))
		return (-1);
	v.mlx = mlx_init();
	// Error must free obj
	if (!v.mlx)
		return (-1);
	v.win = mlx_new_window(v.mlx, v.width, v.heigth, "fdf");
	v.img = mlx_new_image(v.mlx, v.width, v.heigth);
	// Error must free obj and mlx
	if (!v.win || !v.img)
		return (-1);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length, &v.endian);
	fdf_registerhooks(&v);
	fdf_drawmesh(&obj, &v);
	mlx_loop(v.mlx);
	return (0);
}
