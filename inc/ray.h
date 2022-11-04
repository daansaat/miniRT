#ifndef RAY_H
# define RAY_H

# include "vec3f.h"
# include "intersect.h"
# include "parser.h"
# include <stdbool.h>

typedef struct s_scene t_scene;
typedef struct s_list t_list;
typedef struct s_object t_object;

typedef struct s_ray
{
	t_vec3f	origin;
	t_vec3f	direction;
}			t_ray;

t_vec3f	cast_ray(t_ray camera, t_scene *scene);
t_vec3f	point_at(t_ray ray, float t);
bool	trace(t_ray camera, t_list *objects, t_object **hitobject, float *t);

#endif