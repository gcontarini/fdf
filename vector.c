/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:12 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:19:54 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	vector(double x, double y, double z)
{
	t_vector	r;

	r.x = x;
	r.y = y;
	r.z = z;
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

t_vector	orto_projection(t_vector a)
{
	t_vector	a_hat;

	a_hat.x = (a.x - a.y) * (sqrt(2.0) / 2.0);
	a_hat.y = (a.x + a.y + (2.0 * a.z)) * (sqrt(6.0) / 6.0);
	a_hat.z = (a.x + a.y + a.z) * (sqrt(3.0) / 3.0);
	return (a_hat);
}

t_vector	rotate(t_vector vec, double rad)
{
	vec.x = (vec.x * cos(rad)) - (vec.y * sin(rad));
	vec.y = (vec.x * sin(rad)) + (vec.y * cos(rad));
	vec.y = (vec.y * cos(rad)) - (vec.z * sin(rad));
	vec.z = (vec.y * sin(rad)) + (vec.z * cos(rad));
	return (vec);
}
