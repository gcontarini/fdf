#include "fdf.h"

//int	key_hook(int keycode, void  

int	main(void)
{
	t_vars		v;
	t_obj		obj;

	/*
	if (ac != 2)
		return (-1);
	obj = fdf_openfile(av[1]);
	*/
	obj.gamma = 1.0;
	obj.vec = (t_vector **) malloc(5 * sizeof(t_vector *));
	for (int i = 0; i < 5; i++)
	{
		obj.vec[i] = (t_vector *) malloc(5 * sizeof(t_vector));
		for (int j = 0; j < 5; j++)
			obj.vec[i][j] = orto_projection(vector(i, j, 0 * obj.gamma));
	}
	obj.width = 5;
	obj.heigth = 5;
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
	obj.center_offset = fdf_center_offset(&obj, &v);
	draw_mesh(&obj, &v);
	// No test anymore
	mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
	mlx_loop(v.mlx);
	// Destroy image and window
	//fdf_cleanfile(obj.vec);
	mlx_destroy_image(v.mlx, v.img);
	mlx_destroy_window(v.mlx, v.win);
	return (0);
}
