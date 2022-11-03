#ifndef RAY_H
# define RAY_H

# include "vec3f.h"
# include "sphere.h"
# include "parser.h"
# include <stdbool.h>

typedef struct s_scene t_scene;
typedef struct s_list t_list;
typedef struct s_object t_object;

typedef struct s_ray
{
	vec3f	origin;
	vec3f	direction;
}			t_ray;

vec3f	cast_ray(t_ray camera, t_scene *scene);
bool	trace(t_ray camera, t_list *objects, t_object **hitobject);

// typedef struct s_sphere
// {
// 	vec3f	sphere_position;
// 	float	sphere_radius;
// }			t_sphere;

// vec3f	point_at(t_ray ray, float t);
// vec3f	cast_camera_ray(vec3f cam_pos, vec3f ray_direction);


// bool	hit_sphere(vec3f center, float radius, t_ray r);

#endif