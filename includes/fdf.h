/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:04:19 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/01 18:15:45 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_queue.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define C_SW 0x00FFFFFF
# define C_SB 0x00000000
# define UPHEX_BASE "0123456789ABCDEF"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_object
{
	int			width;
	int			heigth;
	double		gamma;
	t_vector	center_offset;
	t_vector	**vec;
}	t_obj;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
	t_obj	*obj;
}	t_vars;

typedef struct s_pixel_img
{
	int	x;
	int	y;
}	t_pixel;

// main
void		fdf_winsize(t_vars *vars, t_obj *obj, int width, int heigth);

// vector2img
t_pixel		vector2img(t_vector a, t_obj *obj, t_vars *buff);
t_vector	img2vector(t_pixel a, t_obj *obj, t_vars *buff);

// pixel2buff
int			buff_offset(int x, int y, t_vars *buff);
void		pixel2buff(t_pixel a, int color, t_vars *buff);

// vector_math
double		dot_product(t_vector a, t_vector b);
t_vector	sum_vector(t_vector a, t_vector b);
t_vector	scalar_vector(double scalar, t_vector a);

// draw_line
void		draw_line(t_pixel a, t_pixel b, int color, t_vars *buff);
void		bresenhaml(t_pixel a, t_pixel b, int color, t_vars *buff);
void		bresenhamh(t_pixel a, t_pixel b, int color, t_vars *buff);

// vector_basic
t_vector	vector(double x, double y, double z);

// draw_mesh
void		fdf_drawmesh(t_obj *obj, t_vars *buff);
void		draw_conlines(t_vector a, t_vector b, t_obj *obj, t_vars *buff);
void		draw_outline(t_obj *obj, t_vars *buff);

// projections
t_vector	orto_projection(t_vector a);

// fdf_center_offset
t_vector	fdf_center_offset(t_obj *obj, t_vars *buff);
t_vector	obj_center(t_obj *obj);
t_vector	vec_offset(t_vector a, t_vector offset);

// fdf_itof
double		fdf_itof(int integer, int frac);

// fdf_file
int			fdf_open_objfile(char *file, t_obj *obj, t_vars *buff);
int			line_to_mvector(t_queue2 *que, t_obj *obj);
t_vector	*line_to_avector(char *line, t_obj *obj);
t_queue2	*openfile(char *file);
int			measure_width(t_queue2	*que);

// fdf_atoiuhex
int			fdf_atoiuhex(const char *str);

// fdf_clean
void		fdf_cleanobj(t_obj *obj);
t_vector	*fdf_cleanstrvec(t_vector *vec, char **mtx);

// fdf_exit
int			fdf_xerror(t_obj *obj, t_vars *buff);
int			fdf_exit(t_obj *obj, t_vars *buff);

// fdf_zoom
void		fdf_zoom(t_vars *vars, int x, int y, double dz);
void		fdf_gammazoom(t_vars *vars, int keycode);

// fdf_drawblank
void		fdf_drawblank(t_vars *vars);

// fdf_move
void		fdf_updown(t_vars *vars, int keycode);
void		fdf_leftright(t_vars *vars, int keycode);

// hooks
void		fdf_registerhooks(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int mousecode, int x, int y, t_vars *vars);
int			cwin_hook(t_vars *vars);

#endif
