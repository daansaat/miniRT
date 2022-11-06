#include "../inc/ray.h"

bool	intersect_sphere(t_ray ray, t_object sp, float *t)
{
	t_vec3f	oc;
    float 	p;
    float 	q;
    float 	discriminant;
    float   t0;
    float   t1;
    float   root;

	oc = ray.origin - sp.center;
    p = dot_product(ray.direction, oc);
    q = dot_product(oc, oc) - (sp.radius * sp.radius);
    discriminant = (p * p) - q;
    if (discriminant < 0.0f)
        return (false);
    root = sqrt(discriminant);
    t0 = -p + sqrt(discriminant);
    t1 = -p - sqrt(discriminant);
    if (t0 > 0.001 && t0 < t1)
        *t = t0;
    if (t1 > 0.001 && t1 < t0)
        *t = t1;
    return (discriminant > 0);
}

bool	intersect_plane(t_ray ray, t_object pl, float *t)
{
    float   denom;
    
    denom = dot_product(pl.direction, ray.direction);
    if (fabsf(denom) > 0.0001f)
    {
        t_vec3f p0l0 = pl.center - ray.origin;
        *t = dot_product(p0l0, pl.direction) / denom;
        return (*t >= 0);
    }
    return (false);
}

// bool	intersect_plane(t_ray ray, t_object pl, float *t)
// {
//     float   root;
    
//     if (dot_product(pl.direction, ray.direction) > 0)
//         pl.direction *= -1;
//     root = dot_product(pl.direction, pl.center - ray.origin) / dot_product(pl.direction, ray.direction);
//     if (root > 0.00001)
//     {
//         *t = root;
//         return (true);
//     }
//     return (false);
// }


// bool	intersect_plane(t_ray ray, t_object pl, float *t)
// {
//     float d = dot_product(pl.center, -pl.direction);
//     float root = -(d + dot_product(ray.origin, pl.direction)) / dot_product(ray.direction, pl.direction);
//     if (root >= 0)
//     {
//         *t = root;
//         return (true);
//     }
//     return (false);
// }

// bool	intersect_plane(t_ray ray, t_object pl, float *t)
// {
// 	float	root;
	
// 	if (dot_product(pl.direction, ray.direction) > 0)
// 		pl.direction = pl.direction * -1;
// 	root = dot_product(pl.direction, pl.center - ray.origin) / dot_product(pl.direction, ray.direction);
// 	if (root > 0.00001)
//     {
// 		*t = root;
//         return (true);
//     }
// 	return (false);
// }


// bool	intersect_sphere(t_ray ray, t_object sp, float *t)
// {
// 	t_vec3f	oc;
// 	float 	a;
//     float 	b;
//     float 	c;
//     float 	discriminant;
//     float   t0;
//     float   t1;

// 	oc = ray.origin - sp.center;
// 	a = dot_product(ray.direction, ray.direction);
//     b = 2.0 * dot_product(oc, ray.direction);
//     c = dot_product(oc, oc) - sp.radius * sp.radius;
//     discriminant = b * b - 4 * a * c;
//     if (discriminant < 0)
//         return (false);//*t = -1.0;
//     else
//     {
//         // *t = (-b - sqrt(discriminant) ) / (2.0 * a);
//         t0 = (-b + sqrt(discriminant)) / (2 * a);
//         t1 = (-b - sqrt(discriminant)) / (2 * a);
//     }
//     if (t0 > 0.001 && t0 < t1)
//         *t = t0;
//     if (t1 > 0.001 && t1 < t0)
//         *t = t1;
//     return (discriminant > 0);
// }
