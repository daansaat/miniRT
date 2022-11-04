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
	t_vec3f	origin;
	t_vec3f	direction;
	t_vec3f	horizontal;
	t_vec3f	vertical;
	t_vec3f	lower_left_corner;
	float	fov;
	float	screen_distance;
}			t_camera;

typedef struct s_light
{
	t_vec3f	origin;
	t_vec3f	color;
	float	brightness;
}			t_light;

typedef struct s_object
{
	t_vec3f	center;
	t_vec3f	color;
	t_vec3f	direction;
	float	radius;
	float	height;
	bool	(*intersect)(t_ray camera, t_object object, float *t);
}			t_object;

typedef struct s_scene
{
	t_camera	camera;
	t_light		light;
	t_list		*objects;
}			t_scene;

void	parse_rt_file(char *file, t_scene *scene);
void	parse_ambient(char **input, t_scene *scene);
void	parse_camera(char **input, t_scene *scene);
void	parse_light(char **input, t_scene *scene);
void	parse_sphere(char **input, t_scene *scene);
void	parse_plane(char **input, t_scene *scene);
void	parse_cylinder(char **input, t_scene *scene);
void	get_t_vec3f(char *input, t_vec3f *vec3f);

#endif