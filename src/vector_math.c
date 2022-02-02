#include "fdf.h"

double	dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	sum_vector(t_vector a, t_vector b)
{
	t_vector	r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	r.og_z = a.og_z;
	return (r);
}

t_vector	scalar_vector(double scalar, t_vector a)
{
	t_vector	r;

	r.x = a.x * scalar;
	r.y = a.y * scalar;
	r.z = a.z * scalar;
	r.og_z = a.og_z;
	return (r);
}
