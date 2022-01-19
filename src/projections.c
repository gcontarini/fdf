#include "fdf.h"

t_vector	orto_projection(t_vector a, double zoom)
{
	t_vector	a_hat;
	t_vector	u_one;
	t_vector	u_two;
	double		i;
	double		j;

	u_one = vector(1, 1, (6 - zoom) / 3);
	u_two = vector(1, -1, -zoom / 3);
	i = dot_product(a, u_one) / dot_product(u_one, u_one);
	j = dot_product(a, u_two) / dot_product(u_two, u_two);
	a_hat = sum_vector(scalar_vector(i, u_one), scalar_vector(j, u_two));
	return (a_hat);
}
