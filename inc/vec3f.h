#ifndef VEC3F_h
# define VEC3F_h

# include <math.h>

// typedef struct s_vec3
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }			t_vec3;

// float	magnitude(t_vec3 v);
// float	dot_product(t_vec3 u, t_vec3 v);
// t_vec3	cross_product(t_vec3 u, t_vec3 v);
// t_vec3	normalize(t_vec3 v);
// void	set_values(t_vec3 *vec3, float x, float y, float z);

typedef float vec3f __attribute__ ((vector_size (12)));

float	magnitude(vec3f v);
float	dot_product(vec3f u, vec3f v);
vec3f	cross_product(vec3f u, vec3f v);
vec3f	normalize(vec3f v);
// void	set_values(vec3 *vec3, float x, float y, float z);




#endif