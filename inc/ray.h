#ifndef RAY_H
# define RAY_H

# include "vec3f.h"
# include "intersect.h"
# include "parser.h"
# include <stdbool.h>

typedef struct s_scene t_scene;
typedef struct s_list t_list;
typedef struct s_object t_object;
typedef struct s_light t_light;
typedef struct s_hitpoint t_hitpoint;

t_vec3f	cast_ray(t_ray camera, t_scene *scene);
bool	trace(t_ray camera, t_list *objects, t_object **hitobject, float *t);
void	set_hitpoint_surface_data(t_ray cam_ray, t_hitpoint *hitpoint, t_light light, float tnear);

#endif