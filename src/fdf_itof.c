#include "fdf.h"

double	fdf_itof(int integer, int frac)
{
	double	n;
	double	f;
	
	n = (double) integer;
	f = (double) frac;
	while (f >= 1.0)
		f /= 10.0;
	if (n >= 0.0)
		n += f;
	else
		n -= f;
	return (n);
}
