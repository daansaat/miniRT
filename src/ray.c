#include "../inc/miniRT.h"
#include "../inc/ray.h"
#include "../inc/intersect.h"

#include <stdio.h>

void	set_hitpoint_values(t_ray cam_ray, t_hitpoint *hitpoint, t_light light, float tnear)
{
	hitpoint->point = cam_ray.origin + cam_ray.direction * tnear;
	hitpoint->normal = normalize(hitpoint->point - hitpoint->center);
	hitpoint->lightdir = normalize(light.origin - hitpoint->point);
	hitpoint->shadow_ray.origin = (hitpoint->point + hitpoint->normal) * 1e-4f;
	hitpoint->shadow_ray.direction = hitpoint->lightdir * -1;
	hitpoint->diffuse = 0.4f * light.brightness * fmaxf(0.f, dot_product(hitpoint->normal, hitpoint->lightdir));
	hitpoint->viewdir = normalize(cam_ray.origin - hitpoint->point);
	hitpoint->reflet = 2.0f * dot_product(hitpoint->lightdir, hitpoint->normal);
	hitpoint->phongdir = hitpoint->lightdir - hitpoint->reflet * hitpoint->normal;
	hitpoint->specular = fmaxf(0.f, dot_product(hitpoint->phongdir, hitpoint->viewdir));
	hitpoint->specular = 0.4f * powf(hitpoint->specular, 4);
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
	t_object	*shadowobject;
	t_vec3f		hitcolor;
	float		tnear;
	float		tshadow;
	bool		visibility;

	hitobject = NULL;
	shadowobject = NULL;
	hitcolor = BACKGROUNDCOLOR;
	tnear = INFINITY;
	tshadow = INFINITY;
	if (trace(cam_ray, scene->objects, &hitobject, &tnear))
	{
		set_hitpoint_values(cam_ray, &hitobject->hitpoint, scene->light, tnear);
		visibility = (!trace(hitobject->hitpoint.shadow_ray, scene->objects, &shadowobject, &tshadow));
		hitcolor = scene->light.ambient * hitobject->color \
			+ visibility * hitobject->hitpoint.diffuse * hitobject->color \
			+ visibility * hitobject->hitpoint.specular * hitobject->color;
	}
	return (hitcolor);
}
