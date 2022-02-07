/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:49:34 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/07 10:50:58 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	fdf_pxerror(t_vars *vars, const char *errormsg)
{
	ft_printf("%s", errormsg);
	if (!vars)
		return (-1);
	if (!vars->mlx)
		fdf_xerror(vars->obj, NULL);
	fdf_xerror(vars->obj, vars);
	return (-1);
}
