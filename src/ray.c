#include "../inc/ray.h"

// P(t) = A + tb // Point = origin + t * direction //
// vec3f	point_at(t_ray ray, float t)
// {
// 	vec3f point;

// 	point[0] = ray.origin[0] + t * ray.direction[0];
// 	point[1] = ray.origin[1] + t * ray.direction[1];
// 	point[2] = ray.origin[2] + t * ray.direction[2];
// 	return (point);
// }

// bool	trace(t_sphere sphere)

// vec3f	cast_camera_ray(vec3f cam_pos, vec3f ray_direction)
// {

// }

bool	hit_sphere(vec3f center, float radius, t_ray r)
{
	vec3f	oc = r.origin - center;
	float 	a = dot_product(r.direction, r.direction);
    float 	b = 2.0 * dot_product(oc, r.direction);
    float 	c = dot_product(oc, oc) - radius * radius;
    float 	discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}