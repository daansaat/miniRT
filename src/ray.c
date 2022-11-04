#include "../inc/miniRT.h"
#include "../inc/ray.h"
#include "../inc/intersect.h"

#include <stdio.h>

// P(t) = A + tb // Point = origin + t * direction //
t_vec3f	point_at(t_ray ray, float t)
{
	t_vec3f point;

	point[0] = ray.origin[0] + t * ray.direction[0];
	point[1] = ray.origin[1] + t * ray.direction[1];
	point[2] = ray.origin[2] + t * ray.direction[2];
	return (point);
}

bool	trace(t_ray camera, t_list *objects, t_object **hitobject, float *t)
{
	while (objects)
	{
		if (objects->content->intersect(camera, *objects->content, t))
			*hitobject = objects->content;
		objects = objects->next;
	}
	return (*hitobject != NULL);
}

t_vec3f	cast_ray(t_ray camera, t_scene *scene)
{
	t_object	*hitobject;
	t_vec3f		hitcolor;
	t_vec3f		hitpoint;
	t_vec3f		hitnormal;
	t_vec3f		lightdir;
	float		albedo = 0.18 / M_PI;
	float		t;

	hitobject = NULL;
	hitcolor = BACKGROUNDCOLOR;
	if (trace(camera, scene->objects, &hitobject, &t))
	{
		hitpoint = camera.origin + camera.direction * t;
		lightdir = hitpoint - scene->light.origin;
		hitnormal = normalize(hitpoint - hitobject->center);
		hitcolor = hitobject->color * albedo * scene->light.brightness * fmaxf(0.f, dot_product(hitnormal, lightdir));
	}
	return (hitcolor);
}
