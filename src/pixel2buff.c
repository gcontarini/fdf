#include "fdf.h"

void	pixel2buff(t_pixel a, int color, t_vars *buff)
{
	char	*dst;

	dst = buff->addr + buff_offset(a.x, a.y, buff);
	*(unsigned int*) dst = color;
}

int	buff_offset(int x, int y, t_vars *buff)
{
	int	row;
	int	column;

	row = y * buff->line_length;
	column = x * (buff->bits_per_pixel / 8);
	return (row + column);
}
