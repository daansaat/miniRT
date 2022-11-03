#ifndef RAY_H
# define RAY_H

# include "vec3f.h"

typedef struct s_ray
{
	vec3f	origin;
	vec3f	direction;
}			t_ray;

vec3f	point_at(t_ray ray, float t);

#endif