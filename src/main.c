#include "fdf.h"

//int	key_hook(int keycode, void  

int	main(void)
{
	t_vars		v;
	t_obj		obj;

	obj.z = (double **) malloc(5 * sizeof(double *));
	for (int i = 0; i < 5; i++)
	{
		obj.z[i] = (double *) malloc(5 * sizeof(double));
		for (int j = 0; j < 5; j++)
			obj.z[i][j] = 0;
	}
	obj.z[0][0] = 1;
	obj.z[0][3] = -1;
	obj.z[0][4] = -1;
	obj.z[1][0] = -1;
	obj.z[1][4] = 1;
	obj.z[2][0] = -1;
	obj.z[2][1] = 1;
	obj.z[2][4] = -1;
	obj.z[3][0] = 1;
	obj.z[3][1] = -1;
	obj.z[3][4] = 1;
	obj.z[3][0] = 1;
	obj.width = 5;
	obj.heigth = 5;
	obj.max_z = 1;
	obj.min_z = -1;
	v.width = 900;
	v.heigth = 800;
	v.mlx = mlx_init();
	if (!v.mlx)
		return (-1);
	v.win = mlx_new_window(v.mlx, v.width, v.heigth, "fdf");
	if (!v.win)
		return (-1);
	// Returns error?
	v.img = mlx_new_image(v.mlx, v.width, v.heigth);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length, &v.endian);
	//mlx_key_hook(v.win, key_hook, &v);
	draw_mesh(&obj, &v);
	// No test anymore
	mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
	mlx_loop(v.mlx);
	// Destroy image and window
	mlx_destroy_image(v.mlx, v.img);
	mlx_destroy_window(v.mlx, v.win);
	return (0);
}
