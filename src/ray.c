#include "../inc/ray.h"

// P(t) = A + tb // Point = origin + t * direction //
vec3f	point_at(t_ray ray, float t)
{
	vec3f point;

	point[0] = ray.origin[0] + t * ray.direction[0];
	point[1] = ray.origin[1] + t * ray.direction[1];
	point[2] = ray.origin[2] + t * ray.direction[2];
	return (point);
}