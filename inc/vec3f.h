#ifndef VEC3F_h
# define VEC3F_h

# include <math.h>

typedef float t_vec3f __attribute__ ((vector_size (12)));

float	magnitude(t_vec3f v);
float	dot_product(t_vec3f u, t_vec3f v);
t_vec3f	cross_product(t_vec3f u, t_vec3f v);
t_vec3f	normalize(t_vec3f v);

#endif