#include "../inc/ray.h"
#include <math.h>

#include <stdio.h>

// bool    quadratic(float a, float b, float c, float *t0, float *t1)
// {

// }

// bool	intersect_sphere(t_ray ray, t_object sp, float *t)
// {
// 	t_vec3f	oc;
// 	float 	p;
// 	float 	q;
// 	float 	discriminant;
// 	float   t0;
// 	float   t1;
// 	float   root;

// 	oc = ray.origin - sp.center;
// 	p = dot_product(ray.direction, oc);
// 	q = dot_product(oc, oc) - (sp.radius * sp.radius);
// 	discriminant = (p * p) - q;
// 	if (discriminant < 0.0f)
// 		return (false);
// 	root = sqrt(discriminant);
// 	t0 = -p + sqrt(discriminant);
// 	t1 = -p - sqrt(discriminant);
// 	if (t0 > 0.001 && t0 < t1)
// 		*t = t0;
// 	if (t1 > 0.001 && t1 < t0)
// 		*t = t1;
// 	return (discriminant > 0);
// }

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

//  Sphere

// Definition:
// C is the center of the sphere
// r is the radius of the sphere

// To hit a sphere we notice that:

//     len(P-C) = r

// This means that the distance between the sphere center and the hit point equals r, which is true when P lies on the surface of the sphere.

// Solution:

//    len(D*t+X) = r
//    dot(D*t+X) = r^2
//    D|D*(t^2) + 2*D|X*t + X|X - r^2 = 0

// Hence we have a quadratic equation that we have to solve. To simplify, we have the following trinomial coefficients:

//    a   = D|D
//    b/2 = D|X
//    c   = X|X - r*r

// Surface normal is N=nrm(P-C). 

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

// Plane

// Definition:
// C is a point that lies on the plane
// V is the plane normal (unit length)

// To hit a plane we notice that:

//     (P-C)|V = 0

// This means that the P-C vector is perpendicular to the normal, which is true when the point P lies on the plane.

// Solution:

//    (D*t+X)|V = 0
//    D|V*t = -X|V
//    t = -X|V / D|V

// Before the division we should check whether D|V is nonzero. We can also check if the signs of D|V and X|V are different (if not, resulting t will be negative).

// Surface normal vector at point P equals to the plane normal, unless D|V is negative, in which case N=-V. 

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
	// t_vec3f oc = ray.origin - cy.center;
	// a = ray.direction[0] * ray.direction[0] + ray.direction[1] * ray.direction[1];
	// b = 2 * (ray.direction[0] * ray.origin[0] + ray.direction[1] * ray.origin[1]);
	// c = ray.origin[0] * ray.origin[0] + ray.origin[1] * ray.origin[1] - cy.radius * cy.radius;
	if (!quadratic(a, b, c, &t0, &t1))
		return (false);
	if (t0 > 0.001 && t0 < t1)
        *t = t0;
    if (t1 > 0.001 && t1 < t0)
        *t = t1;
	return (true);
}

//  Cylinder

// Definition:
// C is the start cap point of the cylinder
// V is a unit length vector that determines cylinder's axis
// r is the cylinder's radius
// maxm determines cylinder's end cap point

// To hit a cylinder we notice that:

//    A = C + V*m
//    ( P-A )|V = 0
//    len( P-A ) = r

// where m is a scalar that determines the closest point on the axis to the hit point. The P-A vector is perpendicular to V, what guarantees the closest distance to the axis. P-A is the cylinder's radius.

// Solution:

//    (P-C-V*m)|V = 0
//    (P-C)|V = m*(V|V) = m   (len(V)=1)
//    m = (D*t+X)|V
//    m = D|V*t + X|V

//    len(P-C-V*m) = r
//    dot( D*t+X - V*(D|V*t + X|V) ) = r^2
//    dot( (D-V*(D|V))*t + (X-V*(X|V)) ) = r^2
//       dot( A-V*(A|V) ) = A|A - 2*(A|V)^2 + V|V * (A|V)^2 =
//        = A|A - (A|V)^2
//    a*t^2 + b*t + c = 0
//    a = D|D - (D|V)^2
//    c = X|X - (X|V)^2 - r^2
//    b = 2 * (D-V*(D|V))|(X-V*(X|V)) =
//      = 2 * (D|X - D|V*(X|V) - X|V*(D|V) + (D|V)*(X|V)) =
//      = 2 * (D|X - (D|V)*(X|V))

// Finally:

//    a   = D|D - (D|V)^2
//    b/2 = D|X - (D|V)*(X|V)
//    c   = X|X - (X|V)^2 - r*r

// Surface normal is:

//    m = D|V*t + X|V
//    N = nrm( P-C-V*m )

// There are two points on the cylinder that we hit (it can be the same point twice). 
// We have to calculate two m values and test whether they fall in the range of [0,maxm]. 
// If any falls out, we can either throw the point that corresponds to it away (the cylinder will have a hole) or we can cap the cylinder with planes. 
// One of the planes is defined by a pair (C,-V) and the other by (C+V*maxm,V). 
// We hit the planes like a typical plane; the dot products we have already calculated, we only need to do the division(s). 

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
