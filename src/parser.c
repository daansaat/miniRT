#include "../inc/miniRT.h"
#include "../inc/parser.h"
#include "../inc/sphere.h"

#include <stdio.h>

void	create_scene(t_scene *scene)
{
	t_object	*sphere;
	t_list		*new;

	sphere = malloc(sizeof(t_object));
	sphere->center = (vec3f){0, 0, -5};
	sphere->radius = 0.5;
	sphere->intersect = &intersect_sphere;
	new = ft_lstnew(sphere);
	ft_lstadd_back(&(scene->objects), new);

	scene->camera.origin = (vec3f){0, 0, 0};
	scene->camera.direction = (vec3f){0, 0, 1};
	scene->camera.fov = 90;
	scene->camera.screen_distance = (float)WIDTH / 2 / tan(scene->camera.fov / 2 * M_PI / 180);
	scene->camera.horizontal = normalize(cross_product(scene->camera.direction, (vec3f){0, 1, 0}));
	scene->camera.vertical = normalize(cross_product(scene->camera.horizontal, scene->camera.direction));
	scene->camera.lower_left_corner = scene->camera.origin + scene->camera.direction * scene->camera.screen_distance \
			+ scene->camera.horizontal * (-((float)WIDTH - 1.0) / 2) + scene->camera.vertical * (-((float)HEIGHT - 1.0) / 2);
}