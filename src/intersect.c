#include "../inc/ray.h"
#include <math.h>

#include <stdio.h>

bool    quadratic(float a, float b, float c, float *t0, float *t1)
{
	double  discriminant;
	double  rootdiscriminant;
	double  q;

	discriminant = (double)b * (double)b - 4 * (double)a * (double)c;
	if (discriminant < 0)
		return (false);
	rootdiscriminant = sqrt(discriminant);
	if (b < 0)
		q = -.5 * (b - rootdiscriminant);
	else
		q = -.5 * (b + rootdiscriminant);
	*t0 = q / a;
	*t1 = c / q;
	// if (*t0 > *t1)
	//     swap(*t0, *t1);
	return (true);
}

bool	intersect_sphere(t_ray ray, t_object sp, float *t)
{
	float	a;
	float	b;
	float	c;
	float	t0;
	float	t1;

	t_vec3f oc = ray.origin - sp.center;
	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(ray.direction, oc);//ray.origin);
	c = dot_product(oc, oc) - sp.radius * sp.radius;
	if (!quadratic(a, b, c, &t0, &t1))
		return (false);
	if (t0 > 0.001 && t0 < t1)
        *t = t0;
    if (t1 > 0.001 && t1 < t0)
        *t = t1;
	return (true);
}

bool	intersect_plane(t_ray ray, t_object pl, float *t)
{
	float   denom;
	
	denom = dot_product(pl.direction, ray.direction);
	if (fabsf(denom) > 0.0001f)
	{
		t_vec3f oc = pl.center - ray.origin;
		*t = dot_product(oc, pl.direction) / denom;
		return (*t >= 0);
	}
	return (false);
}

bool	intersect_cylinder(t_ray ray, t_object cy, float *t)
{
	float   t0;
	float   t1;
	float   a;
	float   b;
	float   c;

	t_vec3f oc = ray.origin - cy.center;
	a = dot_product(ray.direction, ray.direction) - powf(dot_product(ray.direction, cy.direction), 2);
	b = 2 * (dot_product(ray.direction, oc) - dot_product(ray.direction, cy.direction) * dot_product(oc, cy.direction));
	c = dot_product(oc, oc) - powf(dot_product(oc, cy.direction), 2) - powf(cy.radius, 2);
	if (!quadratic(a, b, c, &t0, &t1))
		return (false);
	if (t0 > 0.001 && t0 < t1)
        *t = t0;
    if (t1 > 0.001 && t1 < t0)
        *t = t1;
	return (true);
}
