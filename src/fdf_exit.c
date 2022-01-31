#include "fdf.h"

int	fdf_xerror(t_obj *obj, t_vars *buff)
{
	fdf_cleanobj(obj);
	if (!buff)
		exit(-1);
	if (buff->img)
		mlx_destroy_image(buff->mlx, buff->img);
	if (buff->win)
		mlx_destroy_window(buff->mlx, buff->win);
	exit(-1);
	return (-1);
}

int	fdf_exit(t_obj *obj, t_vars *buff)
{
	fdf_cleanobj(obj);
	if (!buff)
		exit(0);
	if (buff->img)
		mlx_destroy_image(buff->mlx, buff->img);
	if (buff->win)
		mlx_destroy_window(buff->mlx, buff->win);
	exit(0);
	return (0);
}
