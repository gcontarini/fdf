#include "fdf.h"

t_vector	orto_projection(t_vector a)
{
	t_vector	a_hat;

	a_hat.x = (a.x - a.y) * (sqrt(2) / 2.0);
	a_hat.y = (a.x + a.y + (2.0 * a.z)) * (sqrt(6) / 6);
	a_hat.z = (a.x - a.y + a.z) * (sqrt(3) / 3);
	return (a_hat);
}
