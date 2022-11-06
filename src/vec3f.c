#include "../inc/vec3f.h"

float	magnitude(t_vec3f v)
{
	return (sqrtf(dot_product(v, v))); // sqrtf??
}

float	dot_product(t_vec3f u, t_vec3f v)
{
	return (u[0] * v[0] + u[1] * v[1] + u[2] * v[2]);
}

t_vec3f	cross_product(t_vec3f u, t_vec3f v)
{
	t_vec3f cross_product;

	cross_product[0] = u[1] * v[2] - u[2] * v[1];
	cross_product[1] = u[2] * v[0] - u[0] * v[2];
	cross_product[2] = u[0] * v[1] - u[1] * v[0];
	return (cross_product);
}

t_vec3f	normalize(t_vec3f v)
{
	float	len;
	float	inv_len;
	
	len = magnitude(v);
	if (len > 0)
	{
		inv_len = 1 / len;
		v[0] *= inv_len;
		v[1] *= inv_len;
		v[2] *= inv_len;
	}
	return (v);
}
