#include "fdf.h"

//int	key_hook(int keycode, void  

int	main(int ac, char *av[])
{
	t_vars		v;
	t_obj		obj;

	if (ac != 2)
		return (-1);
	if (!fdf_open_objfile(av[1], &obj, &v))
		return (-1);
	v.width = 900;
	v.heigth = 800;
	v.mlx = mlx_init();
	if (!v.mlx)
		return (-1);
	v.win = mlx_new_window(v.mlx, v.width, v.heigth, "fdf");
	if (!v.win)
		return (-1);
	v.img = mlx_new_image(v.mlx, v.width, v.heigth);
	// Implement xerror for error here
	if (!v.img)
		return (-1);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length, &v.endian);
	//mlx_key_hook(v.win, key_hook, &v);
	draw_mesh(&obj, &v);
	// No test anymore
	mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
	mlx_loop(v.mlx);
	// Destroy image and window
	fdf_cleanobj(&obj);
	mlx_destroy_image(v.mlx, v.img);
	mlx_destroy_window(v.mlx, v.win);
	return (0);
}
