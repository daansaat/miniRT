#include "../inc/vec3f.h"

float	magnitude(t_vec3f v)
{
	return (sqrt(dot_product(v, v))); // sqrtf??
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

t_vec3f	normalize(t_vec3f v) // multiplication more efficient then division
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

// void	set_values(t_vec3 *vec3, float x, float y, float z)
// {
// 	vec3->x = x;
// 	vec3->y = y;
// 	vec3->z = z;
// }

// float	magnitude(t_vec3 v)
// {
// 	return (sqrt(dot_product(v, v))); // sqrtf??
// }

// float	dot_product(t_vec3 u, t_vec3 v)
// {
// 	return (u.x * v.x + u.y * v.y + u.z * v.z);
// }

// t_vec3	cross_product(t_vec3 u, t_vec3 v)
// {
// 	t_vec3 vec3;

// 	vec3.x = u.y * v.z - u.z * v.y;
// 	vec3.y = u.z * v.x - u.x * v.z;
// 	vec3.z = u.x * v.y - u.y * v.x;
// 	return (vec3);
// }

// t_vec3	normalize(t_vec3 v) // multiplication more efficient then division
// {
// 	float	len;
// 	float	inv_len;
	
// 	len = magnitude(v);
// 	if (len > 0)
// 	{
// 		inv_len = 1 / len;
// 		v.x *= inv_len;
// 		v.y *= inv_len;
// 		v.z *= inv_len;
// 	}
// 	return (v);
// }

// void	set_values(t_vec3 *vec3, float x, float y, float z)
// {
// 	vec3->x = x;
// 	vec3->y = y;
// 	vec3->z = z;
// }

