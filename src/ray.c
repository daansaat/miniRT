#include "../inc/miniRT.h"
#include "../inc/ray.h"
#include "../inc/intersect.h"

#include <stdio.h>

static float	clamp(float min, float max, float value)
{
	return (fmaxf(min, fminf(max, value)));
}

static void	set_hitpoint_color(t_vec3f *pixelcolor, t_light light, t_object hitobject, bool visibility)
{
	t_vec3f hitpointcolor;

	hitpointcolor = light.ambient * light.color \
		+ visibility * hitobject.hitpoint.diffuse * hitobject.hitpoint.intensity \
		+ visibility * hitobject.hitpoint.specular * hitobject.hitpoint.intensity;
	hitpointcolor[0] = clamp(0, 255, hitpointcolor[0]);
	hitpointcolor[1] = clamp(0, 255, hitpointcolor[1]);
	hitpointcolor[2] = clamp(0, 255, hitpointcolor[2]);
	hitpointcolor = hitobject.color / 255 * hitpointcolor;
	*pixelcolor = hitpointcolor;
}

void	set_hitpoint_surface_data(t_ray cam_ray, t_hitpoint *hitpoint, t_light light, float tnear)
{
	hitpoint->point = cam_ray.origin + cam_ray.direction * tnear;
	hitpoint->normal = normalize(hitpoint->point - hitpoint->objcenter);
	if (hitpoint->type == 2) //TYPE PLANE
		hitpoint->normal = hitpoint->objdir;

	if (hitpoint->type == 3) //TYPE CYLINDER
	{
		// float perpen = dot_product(hitpoint->point - hitpoint->objcenter, hitpoint->objdir) / dot_product(hitpoint->objdir, hitpoint->objdir);
		// t_vec3f perpenat = hitpoint->objcenter + hitpoint->objdir * perpen;
		// hitpoint->normal = normalize(hitpoint->point - perpenat);

		t_vec3f oc = cam_ray.origin - hitpoint->objcenter;
		float m = dot_product(cam_ray.direction, hitpoint->objdir) * tnear + dot_product(oc, hitpoint->objdir);
		hitpoint->normal = normalize(hitpoint->point - hitpoint->objcenter - hitpoint->objdir * m);
	}

	hitpoint->lightdir = normalize(light.origin - hitpoint->point);
	hitpoint->lightdistance = magnitude(light.origin - hitpoint->point);// NON normalized lightdir
	hitpoint->shadow_ray.origin = hitpoint->point + hitpoint->normal * 1e-4f;
	hitpoint->shadow_ray.direction = hitpoint->lightdir; //* -1;

	hitpoint->intensity = light.brightness * light.color;
	// hitpoint->intensity = light.brightness * light.color / (sqrtf(hitpoint->lightdistance));//tnear);//(168 / (tnear * tnear)); //

	hitpoint->diffuse = fmaxf(0.f, dot_product(hitpoint->normal, hitpoint->lightdir));
	hitpoint->diffuse = 0.4f * hitpoint->diffuse;

	hitpoint->viewdir = normalize(cam_ray.origin - hitpoint->point);
	hitpoint->mirrordir = 2.0f * dot_product(hitpoint->lightdir, hitpoint->normal) * hitpoint->normal - hitpoint->lightdir;
	hitpoint->specular = fmaxf(0.f, dot_product(hitpoint->mirrordir, hitpoint->viewdir));
	hitpoint->specular = 0.8f * powf(hitpoint->specular, 8);
}

bool	trace(t_ray ray, t_list *objects, t_object **hitobject, float *tnear)
{
	float	t;

	t = INFINITY;
	while (objects)
	{
		if (objects->content->intersect(ray, *objects->content, &t) && t < *tnear)
		{
			*hitobject = objects->content;
			*tnear = t;
		}
		objects = objects->next;
	}
	return (*hitobject != NULL);
}

void	cast_ray(t_ray cam_ray, t_scene *scene, t_vec3f *pixelcolor)
{
	t_object	*hitobject;
	t_object	*shadowobject;
	float		tnear;
	float		tshadow;
	bool		visibility;

	hitobject = NULL;
	shadowobject = NULL;
	*pixelcolor = BACKGROUNDCOLOR;
	tnear = INFINITY;
	tshadow = INFINITY;
	if (trace(cam_ray, scene->objects, &hitobject, &tnear))
	{
		set_hitpoint_surface_data(cam_ray, &hitobject->hitpoint, scene->light, tnear);
		visibility = (!trace(hitobject->hitpoint.shadow_ray, scene->objects, &shadowobject, &tshadow) \
					|| tshadow > hitobject->hitpoint.lightdistance);
		set_hitpoint_color(pixelcolor, scene->light, *hitobject, visibility);
	}
}







	// hitcolor[0] = hitobject->color[0] / 255 * hitcolor[0];
	// hitcolor[1] = hitobject->color[1] / 255 * hitcolor[1];
	// hitcolor[2] = hitobject->color[2] / 255 * hitcolor[2];

	// hitpoint->reflet = 2.0f * dot_product(cam_ray.direction, hitpoint->normal);
	// hitpoint->phongdir = cam_ray.direction - hitpoint->normal * hitpoint->reflet;
	// hitpoint->specular = fmaxf(0.f, dot_product(hitpoint->phongdir, hitpoint->lightdir));
	// hitpoint->specular = 0.4f * powf(hitpoint->specular, 4);

	// void	convert_to_rgb(t_vec3f *color)
	// {
	// 	color[0] = 255 * clamp(0, 1, color[0]);
	// 	color[1] = 255 * clamp(0, 1, color[1]);
	// 	color[2] = 255 * clamp(0, 1, color[2]);
	// }

	// hitcolor = scene->light.ambient * hitobject->color \
	// 	+ visibility * hitobject->hitpoint.diffuse * hitobject->color \
	// 	+ visibility * hitobject->hitpoint.specular * hitobject->color;

	// convert_to_rgb(&hitcolor);
	// hitpoint->viewdir = normalize(cam_ray.origin - hitpoint->point);
	// hitpoint->reflet = 2.0f * dot_product(hitpoint->lightdir, hitpoint->normal);
	// hitpoint->phongdir = hitpoint->lightdir - hitpoint->reflet * hitpoint->normal;
	// hitpoint->specular = fmaxf(0.f, dot_product(hitpoint->phongdir, hitpoint->viewdir));
	// hitpoint->specular = 0.4f * powf(hitpoint->specular, 4);