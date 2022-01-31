#include "fdf.h"

void	draw_line(t_pixel a, t_pixel b, int color, t_vars *buff)
{
	int	delta_x;
	int	delta_y;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	if (delta_x < 0)
		delta_x = -delta_x;
	if (delta_y < 0)
		delta_y = -delta_y;
	if (delta_y < delta_x)
	{
		if (a.x > b.x)
			bresenhaml(b, a, color, buff);
		else
			bresenhaml(a, b, color, buff);
	}
	else
	{
		if (a.y > b.y)
			bresenhamh(b, a, color, buff);
		else
			bresenhamh(a, b, color, buff);
	}
}

void	bresenhaml(t_pixel a, t_pixel b, int color, t_vars *buff)
{
	int	delta_x;
	int	delta_y;
	int	y_i;
	int	pk;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	y_i = 1;
	if (delta_y < 0)
		y_i = -1;
	delta_y *= y_i;
	pk = (2 * delta_y) - delta_x;
	while (a.x <= b.x)
	{
		pixel2buff(a, color, buff);
		if (pk < 0)
			pk += 2 * delta_y;
		else
		{
			pk += (2 * delta_y) - (2 * delta_x);
			a.y += y_i;
		}
		a.x++;
	}
}

void	bresenhamh(t_pixel a, t_pixel b, int color, t_vars *buff)
{
	int	delta_x;
	int	delta_y;
	int	x_i;
	int	pk;

	delta_x = b.x - a.x;
	delta_y = b.y - a.y;
	x_i = 1;
	if (delta_x < 0)
		x_i = -1;
	delta_x *= x_i;
	pk = (2 * delta_x) - delta_y;
	while (a.y <= b.y)
	{
		pixel2buff(a, color, buff);
		if (pk < 0)
			pk += 2 * delta_x;
		else
		{
			pk += (2 * delta_x) - (2 * delta_y);
			a.x += x_i;
		}
		a.y++;
	}
}
