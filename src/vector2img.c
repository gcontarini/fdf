/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:29:06 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 14:20:21 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	vector2img(t_vector a)
{
	t_pixel	pixel;

	pixel.x = (int) nearbyint(a.x);
	pixel.y = (int) nearbyint(a.y);
	return (pixel);
}

t_vector	img2vector(t_pixel a)
{
	t_vector	vec;

	vec.x = (double) a.x;
	vec.y = (double) a.y;
	return (vec);
}
