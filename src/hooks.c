/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:03:50 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/01 12:16:22 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_registerhooks(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, (1L << 8), cwin_hook, vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		fdf_exit(vars->obj, vars);
	else if (keycode == 125 || keycode == 126)
	{
		fdf_updown(vars, keycode);
		fdf_drawblank(vars);
		fdf_drawmesh(vars->obj, vars);
	}
	else if (keycode == 123 || keycode == 124)
	{
		fdf_leftright(vars, keycode);
		fdf_drawblank(vars);
		fdf_drawmesh(vars->obj, vars);
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 5)
	{
		fdf_zoom(vars->obj, vars, 0.1);
		fdf_drawblank(vars);
		fdf_drawmesh(vars->obj, vars);
	}
	else if (mousecode == 4)
	{
		fdf_zoom(vars->obj, vars, -0.1);
		fdf_drawblank(vars);
		fdf_drawmesh(vars->obj, vars);
	}
	return (0);
}

int	cwin_hook(t_vars *vars)
{
	fdf_exit(vars->obj, vars);
	return (0);
}
