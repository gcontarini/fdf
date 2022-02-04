/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:36:54 by gcontari          #+#    #+#             */
/*   Updated: 2022/02/04 15:23:52 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_open_objfile(char *file, t_obj *obj, t_vars *buff)
{
	t_queue2	*que;

	que = openfile(file);
	if (!que)
		return (0);
	obj->heigth = (int) ft_quelen(que) - 1;
	obj->width = measure_width(que);
	if (!line_to_mvector(que, obj))
		return (0);
	obj->center_offset = fdf_center_offset(obj, buff);
	ft_queclean(que, free);
	return (1);
}

int	line_to_mvector(t_queue2 *que, t_obj *obj)
{
	t_queue_unit	unit;
	int				i;

	obj->vec = (t_vector **) malloc(obj->heigth * sizeof(t_vector *));
	if (!obj->vec)
		return (0);
	obj->heigth = 0;
	unit = ft_deque(que);
	i = 0;
	while (unit.content)
	{
		obj->vec[i] = line_to_avector((char *) unit.content, obj);
		if (!obj->vec[i++])
			return (0);
		free(unit.content);
		unit = ft_deque(que);
	}
	return (i);
}

t_vector	*line_to_avector(char *line, t_obj *obj)
{
	t_vector	*vec;
	char		**val;
	char		*frac;
	double		z;
	int			i;

	val = ft_split(line, ' ');
	vec = (t_vector *) malloc(obj->width * sizeof(t_vector));
	if (!vec || !val)
		return (fdf_cleanstrvec(vec, val));
	i = 0;
	while (val[i])
	{
		frac = ft_strchr(val[i], 'x');
		if (frac)
			z = fdf_itof(ft_atoi(val[i]), fdf_atoiuhex(++frac));
		else
			z = fdf_itof(ft_atoi(val[i]), 0);
		vec[i] = orto_projection(vector(i, obj->heigth, -z));
		vec[i++].og_z = -z;
	}
	obj->heigth++;
	fdf_cleanstrvec(NULL, val);
	return (vec);
}

t_queue2	*openfile(char *file)
{
	int			fd;
	t_queue2	*que;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	que = ft_questart();
	if (!que)
	{
		close(fd);
		return (NULL);
	}
	que = ft_enque(que, get_next_line(fd));
	while (que && que->rear && que->rear->content)
		que = ft_enque(que, get_next_line(fd));
	close(fd);
	return (que);
}

int	measure_width(t_queue2	*que)
{
	char		*p;
	int			width;

	p = (char *) ft_queget(que, 0)->content;
	width = 0;
	while (p && *p)
	{
		while (*p == ' ' && *p)
			p++;
		if (*p != 0)
			width++;
		while (*p != ' ' && *p)
			p++;
	}
	return (width);
}
