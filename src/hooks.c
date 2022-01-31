#include "fdf.h"

void	fdf_registerhooks(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 8), cwin_hook, vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		fdf_cleanobj(vars->obj);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 126 || keycode == 13)
		vars->obj->gamma += 0.1;
	else if (keycode == 125 || keycode == 1)
		vars->obj->gamma -= 0.1;
	return (0);
}


int	cwin_hook(t_vars *vars)
{
	fdf_cleanobj(vars->obj);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
