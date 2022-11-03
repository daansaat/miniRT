#include "../inc/ray.h"
#include "../inc/sphere.h"

#include <stdio.h>

bool	trace(t_ray camera, t_list *objects, t_object **hitobject)
{
	while (objects)
	{
		if (objects->content->intersect(camera, *objects->content))
			*hitobject = objects->content;
		objects = objects->next;
	}
	return (*hitobject != NULL);
}

vec3f	cast_ray(t_ray camera, t_scene *scene)
{
	t_object	*hitobject;
	vec3f		hitcolor;
	// float	t;

	hitobject = NULL;
	hitcolor = (vec3f){255, 255, 255};
	if (trace(camera, scene->objects, &hitobject))
	{
		hitcolor = (vec3f){255, 0, 0}; // cast_shadow_ray
	}
	return (hitcolor);
}

bool	intersect_sphere(t_ray ray, t_object sp)
{
	vec3f	oc;
	float 	a;
    float 	b;
    float 	c;
    float 	discriminant;

	oc = ray.origin - sp.center;
	a = dot_product(ray.direction, ray.direction);
    b = 2.0 * dot_product(oc, ray.direction);
    c = dot_product(oc, oc) - sp.radius * sp.radius;
    discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

// P(t) = A + tb // Point = origin + t * direction //
// vec3f	point_at(t_ray ray, float t)
// {
// 	vec3f point;

// 	point[0] = ray.origin[0] + t * ray.direction[0];
// 	point[1] = ray.origin[1] + t * ray.direction[1];
// 	point[2] = ray.origin[2] + t * ray.direction[2];
// 	return (point);
// }