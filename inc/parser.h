#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include "../inc/ray.h"
# include "../inc/vec3f.h"

typedef struct s_object t_object;
typedef struct s_ray t_ray;
typedef struct s_list t_list;

typedef struct s_camera
{
	vec3f	origin;
	vec3f	direction;
	vec3f	horizontal;
	vec3f	vertical;
	vec3f	lower_left_corner;
	float	fov;
	float	screen_distance;
}			t_camera;

typedef struct s_object
{
	vec3f	center;
	vec3f	color;
	vec3f	direction;
	float	radius;
	float	height;
	bool	(*intersect)(t_ray camera, t_object object);
}			t_object;

typedef struct s_scene
{
	t_camera	camera;
	t_list		*objects;
}			t_scene;

void	create_scene(t_scene *scene);


#endif