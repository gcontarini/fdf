#include "fdf.h"

t_vector	orto_projection(t_vector a)
{
	t_vector	a_hat;

	a_hat.x = (a.x - a.y) * (sqrt(2.0) / 2.0);
	a_hat.y = (a.x + a.y + (2.0 * a.z)) * (sqrt(6.0) / 6.0);
	a_hat.z = a.z;
	return (a_hat);
}
