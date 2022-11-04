#include "../inc/ray.h"

bool	intersect_sphere(t_ray ray, t_object sp, float *t)
{
	t_vec3f	oc;
	float 	a;
    float 	b;
    float 	c;
    float 	discriminant;

	oc = ray.origin - sp.center;
	a = dot_product(ray.direction, ray.direction);
    b = 2.0 * dot_product(oc, ray.direction);
    c = dot_product(oc, oc) - sp.radius * sp.radius;
    discriminant = b * b - 4 * a * c;
    if (discriminant < 1)
        *t = -1.0;
    else
        *t = (-b - sqrt(discriminant) ) / (2.0 * a);
    return (discriminant > 0);
}

// color ray_color(const ray& r) {
//     auto t = hit_sphere(point3(0,0,-1), 0.5, r);
//     if (t > 0.0) {
//         vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
//         return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
//     }
//     vec3 unit_direction = unit_vector(r.direction());
//     t = 0.5*(unit_direction.y() + 1.0);
//     return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
// }