#include "fdf.h"

typedef struct s_mlx_img_buffer
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_imgbuff;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_point
{
	int	x;	
	int	y;
}	t_point;

typedef struct s_object_buffer
{
	t_imgbuff	imgbuff[2];
	t_point		circle_center;
	int		f;
	t_vars		vars;
}	t_objbuff;

int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("You pressed: %i\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	ft_printf("X: %i | Y: %i\n", x, y);
	return (0);
}

int	fdf_offset(int x, int y, t_imgbuff *mlx_img)
{
	return (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
}

void	mlx_pixel_putbuff(t_imgbuff *buff, int x, int y, int color)
{
	char	*dst;

	dst = buff->addr + fdf_offset(x, y, buff);
	*(unsigned int*)dst = color;
}

void	clean_img(t_imgbuff *img, int length, int width)
{
	int	x_curr;
	int	y_curr;

	y_curr = 0;
	while (y_curr <= width)
	{
		x_curr = 0;
		while (x_curr <= length)
		{
			mlx_pixel_putbuff(img, x_curr, y_curr, 0x00000000);
			x_curr++;
		}
		y_curr++;
	}
}

void	draw_circle(t_imgbuff *buff, int x, int y, int radius)
{
	int	color;
	int	x_curr;
	int	y_curr;
	double	i;
	double	tmp;

	y_curr = y - radius;
	while (y_curr <= y + radius)
	{
		x_curr = x - radius;
		color = 0x00FFFFFF;
		i = 0;
		while (x_curr <= x + radius)
		{
			tmp = sqrt(pow(x - x_curr, 2) + pow(y - y_curr, 2));
			if (nearbyint(tmp) == (double) radius)
				mlx_pixel_putbuff(buff, x_curr, y_curr, 0x00FFFFFF);
			else if (nearbyint(tmp) < (double) radius)
				mlx_pixel_putbuff(buff, x_curr, y_curr, color);
			color = (((int) i) << 24) | 0x00FFFFFF;
			i += ((double) 256 / (double) (radius * 2));
			x_curr++;
		}
		y_curr++;
	}
}

void	create_img(t_vars *vars, t_objbuff *obuff)
{
	obuff->imgbuff[0].img = mlx_new_image(vars->mlx, 900, 800);
	obuff->imgbuff[0].addr = mlx_get_data_addr(
			obuff->imgbuff[0].img,
			&obuff->imgbuff[0].bits_per_pixel,
			&obuff->imgbuff[0].line_length,
			&obuff->imgbuff[0].endian);
	obuff->imgbuff[1].img = mlx_new_image(vars->mlx, 900, 800);
	obuff->imgbuff[1].addr = mlx_get_data_addr(
			obuff->imgbuff[1].img,
			&obuff->imgbuff[1].bits_per_pixel,
			&obuff->imgbuff[1].line_length,
			&obuff->imgbuff[1].endian);
	obuff->circle_center.x = 100;
	obuff->circle_center.y = 100;
	obuff->f = 0;
}

int	render_next_frame(t_objbuff *obuff)
{
	int	f;

	f = 0;
	draw_circle(&obuff->imgbuff[f], obuff->circle_center.x, obuff->circle_center.y, 50);
	mlx_put_image_to_window(obuff->vars.mlx, obuff->vars.win, obuff->imgbuff[f].img, 0, 0);
	obuff->circle_center.x++;
	obuff->circle_center.y++;
	/*
	if (f == 1)
		obuff->f = 0;
	else
		obuff->f = 1;
		*/
	clean_img(&obuff->imgbuff[f], 900, 800);
	return (0);
}

int	main(void)
{
	t_vars		vars;
	t_objbuff	obj;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 800, "fdf");
	create_img(&vars, &obj);
	obj.vars = vars;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &obj);
	mlx_loop(vars.mlx);
	return (0);
}

/*
typedef struct s_mlx_var
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_mlxvar;

typedef struct s_point
{
	int	x;	
	int	y;
}	t_point;

int	fdf_offset(int x, int y, t_mlxvar *mlx_img)
{
	return (y * mlx_img->line_length + x * (mlx_img->bits_per_pixel / 8));
}

void	mlx_pixel_putbuff(t_mlxvar *buff, int x, int y, int color)
{
	char	*dst;

	dst = buff->addr + fdf_offset(x, y, buff);
	*(unsigned int*)dst = color;
}

void	draw_horizontal_line(t_mlxvar *buff, int x, int y, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_pixel_putbuff(buff, x + i, y, 0x00FFFFFF);
		i++;
	}
}

void	draw_vertical_line(t_mlxvar *buff, int x, int y, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_pixel_putbuff(buff, x, y + i, 0x00FFFFFF);
		i++;
	}
}

void	draw_square(t_mlxvar *buff, int x, int y, int size)
{
	draw_horizontal_line(buff, x, y, size);
	draw_horizontal_line(buff, x, y + size, size);
	draw_vertical_line(buff, x, y, size);
	draw_vertical_line(buff, x + size, y, size);
}

void	draw_circle(t_mlxvar *buff, int x, int y, int radius)
{
	int	color;
	int	x_curr;
	int	y_curr;
	double	i;
	double	tmp;

	y_curr = y - radius;
	while (y_curr <= y + radius)
	{
		x_curr = x - radius;
		color = 0x00FFFFFF;
		i = 0;
		while (x_curr <= x + radius)
		{
			tmp = sqrt(pow(x - x_curr, 2) + pow(y - y_curr, 2));
			if (nearbyint(tmp) == (double) radius)
				mlx_pixel_putbuff(buff, x_curr, y_curr, 0x00FFFFFF);
			else if (nearbyint(tmp) < (double) radius)
				mlx_pixel_putbuff(buff, x_curr, y_curr, color);
			color = (((int) i) << 24) | 0x00FFFFFF;
			i += ((double) 256 / (double) (radius * 2));
			x_curr++;
		}
		y_curr++;
	}
}

double	find_slope(t_point a, t_point b)
{
	return ((double) (a.x - b.x) / (double) (a.y - b.y));
}

double	find_const(t_point a, double slope)
{
	return ((double) (a.y - (slope * a.x)));
}

void	draw_line(t_mlxvar *buff, t_point a, t_point b)
{
	int	x_curr;
	int	y_curr;
	int	y_lim;
	int	x_lim;
	double	slope;
	double	c;

	slope = find_slope(a, b);
	c = find_const(a, slope);
	y_curr = a.y;
	y_lim = b.y;
	if (b.y < a.y)
	{
		y_curr = b.y;
		y_lim = a.y;
	}
	while (y_curr < y_lim)
	{
		x_curr = a.x;
		x_lim = b.x;
		if (b.x < a.x)
		{
			x_curr = b.x;
			x_lim = a.x;
		}
		while (x_curr < x_lim)
		{
			if (y_curr == nearbyint(slope * x_curr + c))
				mlx_pixel_putbuff(buff, x_curr, y_curr, 0x00FFFFFF);
			x_curr++;
		}
		y_curr++;
	}
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_mlxvar	buff;
	t_point		a;
	t_point		b;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 800, "fdf");
	buff.img = mlx_new_image(mlx, 900, 800);
	buff.addr = mlx_get_data_addr(buff.img, &buff.bits_per_pixel, &buff.line_length, &buff.endian);
	a.x= 10;
	a.y = 20;
	b.x = 100;
	b.y = 200;
	draw_line (&buff, a, b);
	mlx_put_image_to_window(mlx, mlx_win, buff.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int	main(int ac, char *av[])
{
	int	i;
	t_ffile	*file;

	i = 1;
	while (i < ac)
	{
		file = fdf_loadfile(av[i++]);
		// Return an error value?
		if (!file)
			continue ;
		// Draw it
		fdf_cleanfile(file);
	}
	return (0);
}

t_fdf_file	*fdf_loadfile(char *fname)
{
	t_list	*start;
	t_list	*curr;
	int	fd;
	char	*line;

	file = (t_ffile *) malloc(sizeof(t_ffile));
	if (!file)
		return (NULL);
	fd = open(fname);
	if (!fd)
		return (fdf_xerror(file));
	line = get_next_line(fd);
	while (line)
	{
		curr = ft_lstnew(line);
		if (curr)
			ft_lstadd_back(&start, curr);
		else
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (transform_to_matrix(&start));
}

// fdf_cleanfile
// fdf_xerror
// transform_to_matrix
// Values can be in float (decimal part in hex)
*/
