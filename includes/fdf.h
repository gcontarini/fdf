#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define C_SW 0x00FFFFFF
# define MARGIN_PERC 0.1

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	width;
	int	heigth;
}	t_vars;

typedef struct s_pixel_img
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_object
{
	int	width;
	int	heigth;
	int	max_z;
	int	min_z;
	double	**z;
}	t_obj;

// vector2img
double		width_transform(int img_width, t_vars *buff);
double		heigth_transform(int img_heigth, t_vars *buff);
t_pixel		vector2img(t_vector a, t_obj *obj, t_vars *buff);

// pixel2buff
int		buff_offset(int x, int y, t_vars *buff);
void		pixel2buff(t_pixel a, int color, t_vars *buff);

// vector_math
double		dot_product(t_vector a, t_vector b);
t_vector	sum_vector(t_vector a, t_vector b);
t_vector	scalar_vector(double scalar, t_vector a);

// draw_line
void		draw_line(t_pixel a, t_pixel b, int color, t_vars *buff);
void		draw_vline(t_pixel a, t_pixel b, int color, t_vars *buff);
double		find_slope(t_pixel a, t_pixel b);
double		find_const(t_pixel a, double m);

// vector_basic
t_vector	vector(double x, double y, double z);

// draw_mesh
void		draw_mesh(t_obj *obj, t_vars *buff);
void		draw_conlines(t_vector a, t_vector b, double zoom, t_obj *obj, t_vars *buff);

// projections
t_vector	orto_projection(t_vector a, double zoom);

#endif
