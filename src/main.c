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
	obj.x_min = 0;
	obj.y_min = 0;
	obj.x_max = 0;
	obj.y_max = 0;
	obj.nrows = 5;
	obj.ncols = 5;
	obj.vec = (t_vector **) malloc(5 * sizeof(t_vector *));
	for (int i = 0; i < 5; i++)
	{
		obj.vec[i] = (t_vector *) malloc(5 * sizeof(t_vector));
		for (int j = 0; j < 5; j++)
		{
			obj.vec[i][j] = orto_projection(vector(i, j, 5.9));
			if (obj.vec[i][j].x > obj.x_max)
				obj.x_max = obj.vec[i][j].x;
			if (obj.vec[i][j].x < obj.x_min)
				obj.x_min = obj.vec[i][j].x;
			if (obj.vec[i][j].y > obj.y_max)
				obj.y_max = obj.vec[i][j].y;
			if (obj.vec[i][j].y < obj.y_min)
				obj.y_min = obj.vec[i][j].y;
		}
	}
	obj.vec[0][0] = orto_projection(vector(0, 0, 2));
	obj.width = (int) nearbyint(fabs(obj.x_max - obj.x_min));
	obj.heigth = (int) nearbyint(fabs(obj.y_max - obj.y_min));
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
	//fdf_cleanfile(obj.z);
	mlx_destroy_image(v.mlx, v.img);
	mlx_destroy_window(v.mlx, v.win);
	return (0);
}
