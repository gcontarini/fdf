#include "fdf.h"

void	draw_line(t_pixel a, t_pixel b, int color, t_vars *buff)
{
	double	m;
	double	c;
	
	if ((a.x - b.x) == 0)
	{
		draw_vline(a, b, color, buff);
		return ;
	}
	m = find_slope(a, b);
	c = find_const(a, m);
	while (a.x < b.x)
	{
		pixel2buff(a, color, buff);
		a.x++;
		a.y = (int) nearbyint(m * a.x + c);
	}
	while (a.x > b.x)
	{
		pixel2buff(b, color, buff);
		b.x++;
		b.y = (int) nearbyint(m * b.x + c);
	}
}

void	draw_vline(t_pixel a, t_pixel b, int color, t_vars *buff)
{
	while (a.y < b.y)
	{
		pixel2buff(a, color, buff);
		a.y++;
	}
	while (a.y > b.y)
	{
		pixel2buff(a, color, buff);
		a.y--;
	}
}

double	find_slope(t_pixel a, t_pixel b)
{
	double	m;

	m = (double) (a.y - b.y) / (double) (a.x - b.x);
	return (m);
}

double	find_const(t_pixel a, double m)
{
	double	c;

	c = (double) a.y - (m * (double) a.x);
	return (c);
}
