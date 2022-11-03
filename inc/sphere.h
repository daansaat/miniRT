#ifndef SPHERE_H
# define SPHERE_H

#include <stdbool.h>
#include "ray.h"
#include "../libft/libft.h"

typedef struct s_ray t_ray;
typedef struct s_object t_object;

// typedef struct s_sphere
// {
// 	vec3f	center;
// 	float	radius;
// 	bool	(*intersect)(t_ray camera, t_sphere obj);//, float t);
// }			t_sphere;

bool	intersect_sphere(t_ray r, t_object sp);


#endif