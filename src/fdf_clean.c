#include "fdf.h"

void	fdf_cleanobj(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->heigth)
		free(obj->vec[i++]);
	free(obj->vec);
}
