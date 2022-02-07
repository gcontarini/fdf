/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:22:39 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 12:22:44 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_cleanobj(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->heigth)
		free(obj->vec[i++]);
	free(obj->vec);
}

t_vector	*fdf_cleanstrvec(t_vector *vec, char **mtx)
{
	int	i;

	if (mtx)
	{
		i = 0;
		while (mtx[i])
			free(mtx[i++]);
		free(mtx);
	}
	if (vec)
		free(vec);
	return (NULL);
}
