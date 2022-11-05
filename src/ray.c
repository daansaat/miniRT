#include "../inc/miniRT.h"
#include "../inc/ray.h"
#include "../inc/intersect.h"

#include <stdio.h>

t_vec3f	point_at(t_ray ray, float t)
{
	t_vec3f point;

	point[0] = ray.origin[0] + t * ray.direction[0];
	point[1] = ray.origin[1] + t * ray.direction[1];
	point[2] = ray.origin[2] + t * ray.direction[2];
	return (point);
}

bool	trace(t_ray camera, t_list *objects, t_object **hitobject, float *tnear)
{
	float	t;

	t = INFINITY;
	while (objects)
	{
		if (objects->content->intersect(camera, *objects->content, &t) && t < *tnear)
		{
			*hitobject = objects->content;
			*tnear = t;
		}
		objects = objects->next;
	}
	return (*hitobject != NULL);
}

t_vec3f	cast_ray(t_ray cam_ray, t_scene *scene)
{
	t_object	*hitobject;
	t_vec3f		hitcolor;
	t_ray		shadow_ray;
	bool		visibility;
	float		diffuse;
	// float		specular;
	// float		ambient;
	float		tnear;

	hitobject = NULL;
	hitcolor = BACKGROUNDCOLOR;
	tnear = INFINITY;
	if (trace(cam_ray, scene->objects, &hitobject, &tnear))
	{
		hitobject->point = cam_ray.origin + cam_ray.direction * tnear;
		hitobject->normal = normalize(hitobject->point - hitobject->center);
		hitobject->lightdir = (hitobject->point - scene->light.origin); //NORMALIZE??
		diffuse = 0.18f / (float)M_PI * scene->light.brightness * fmaxf(0.f, dot_product(hitobject->normal, hitobject->lightdir));
		shadow_ray.origin = hitobject->point + hitobject->normal;
		shadow_ray.direction = hitobject->lightdir * -1;
		visibility = (!trace(shadow_ray, scene->objects, &hitobject, &tnear));
		hitcolor = visibility * hitobject->color;// * diffuse;
		// if (!trace(shadow_ray, scene->objects, &hitobject, &tnear))
			// hitcolor = hitobject->color;// * diffuse;
	}
	return (hitcolor);
}
