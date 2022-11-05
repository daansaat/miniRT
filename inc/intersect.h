#ifndef INTERSECT_H
# define INTERSECT_H

#include <stdbool.h>
#include "ray.h"
#include "../libft/libft.h"

typedef struct s_ray t_ray;
typedef struct s_object t_object;

bool	intersect_sphere(t_ray r, t_object sp, float *t);
bool	intersect_plane(t_ray ray, t_object sp, float *t);

#endif