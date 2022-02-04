/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:40:10 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:00:18 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars		v;
	t_obj		obj;

	if (ac != 2)
		return (fdf_pxerror(NULL, "Exactly one map must given as params.\n"));
	fdf_winsize(&v, &obj, 900, 800);
	if (!fdf_open_objfile(av[1], &obj, &v))
		return (fdf_pxerror(NULL, "Error while loading map file.\n"));
	v.mlx = mlx_init();
	if (!v.mlx)
		return (fdf_pxerror(&v, "Error opening window server connection.\n"));
	v.win = mlx_new_window(v.mlx, v.width, v.heigth, "fdf");
	v.img = mlx_new_image(v.mlx, v.width, v.heigth);
	if (!v.win || !v.img)
		return (fdf_pxerror(&v, "Error setting window/buffer image.\n"));
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
	obj->color = C_SW;
}
