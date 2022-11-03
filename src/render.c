#include "../inc/miniRT.h"
#include "../inc/vec3f.h"
#include "../inc/ray.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

// void	render(t_img *img)
// {
// 	int	x;
// 	int	y;

// 	vec3f	cam_pos = {0, 0, 0};
// 	vec3f	view_dir = {0, 0, -1};
// 	float	fov = 90;
// 	float	screen_distance = (float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);

// 	vec3f	screen_center = cam_pos + view_dir * screen_distance;
// 	vec3f	p0 = screen_center + (vec3f){-1, 1, 0};
// 	vec3f	p1 = screen_center + (vec3f){1, 1, 0};
// 	vec3f	p2 = screen_center + (vec3f){-1, -1, 0};

// 	y = 0;
// 	while (y++ < HEIGHT - 1)
// 	{
// 		x = 0;
// 		while (x++ < WIDTH - 1)
// 		{
// 			float	u = (float)x / WIDTH;
// 			float	v = (float)y / HEIGHT;

// 			vec3f	point_on_screen = p0 + (p1 - p0) * u + (p2 - p0) * v;
// 			vec3f	ray_direction = point_on_screen - cam_pos;


// 			t_ray	r;
// 			r.origin = cam_pos;
// 			r.direction = ray_direction;

// 			vec3f color;
// 			if (hit_sphere((vec3f){0, 0, -5}, 0.5, r))
// 			{
// 				color = (vec3f){255, 0, 0};
// 			}
// 			else 
// 			{
// 				ray_direction = normalize(ray_direction);
// 				float 	t = 0.5*(ray_direction[1] + 1.0);
// 				color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;

// 			}
// 			// vec3f	hitcolor = cast_camera_ray(cam_pos, ray_direction);
// 			my_pixel_put(img, x, y, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);
			
// 		}
// 	}
// }


void	render(t_img *img)
{
	int	x;
	int	y;

	vec3f	cam_pos = {0, 0, 0};
	vec3f	direction = {0, 0, 1};
	float	fov = 90;
	float	screen_distance = (float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);

	vec3f	horizontal = normalize(cross_product(direction, (vec3f){0, 1, 0}));
	vec3f	vertical = normalize(cross_product(horizontal, direction));
	vec3f	lower_left_corner = cam_pos + direction * screen_distance \
			+ horizontal * (-((float)WIDTH - 1.0) / 2) + vertical * (-((float)HEIGHT - 1.0) / 2);

	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			vec3f	point_on_screen = lower_left_corner + horizontal * (float)x + vertical * (float)y;
			vec3f	ray_direction = point_on_screen - cam_pos;

			t_ray	r;
			r.origin = cam_pos;
			r.direction = ray_direction;

			vec3f color;
			if (hit_sphere((vec3f){0, 0, -5}, 0.5, r))
			{
				color = (vec3f){255, 0, 0};
			}
			else 
			{
				ray_direction = normalize(ray_direction);
				float 	t = 0.5*(ray_direction[1] + 1.0);
				color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;

			}
			// vec3f	hitcolor = cast_camera_ray(cam_pos, ray_direction);
			my_pixel_put(img, x, y, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);


			// ray_direction = normalize(ray_direction);

			// float 	t = 0.5*(ray_direction[1] + 1.0);
			// vec3f	color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;

			// my_pixel_put(img, x, y, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);
			
		}
	}
}
