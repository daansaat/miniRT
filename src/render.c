#include "../inc/miniRT.h"
#include "../inc/vec3f.h"
#include <math.h>

#include <stdio.h>

void	render(t_img *img)
{
	int	x;
	int	y;

	float	fov = 180.0f;
	vec3f	origin = {0, 0, 0};
	vec3f	direction = {0, 0, 1};
	float	screen_distance = (float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);

	vec3f	horizontal = normalize(cross_product(direction, (vec3f){0, 1, 0}));
	vec3f	vertical = normalize(cross_product(horizontal, direction));
	vec3f	lower_left_corner = origin + direction * screen_distance \
			+ horizontal * (-((float)WIDTH - 1.0) / 2) + vertical * (-((float)HEIGHT - 1.0) / 2);

	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			// float	u = ((float) x) / (WIDTH - 1);
			// float	v = ((float) y) / (HEIGHT - 1);

			vec3f	color = lower_left_corner + horizontal * (float)x + vertical * (float)y;

	
	
			// float 	t = 0.5*(dir[1] + 1.0);
			// vec3f	color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;
			// dir[0] %= (float)255;
			// dir[1] %= (float)255;
			// dir[2] %= (float)255;
			my_pixel_put(img, x, y, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);
			
			// // printf("%f %f %f \n", color[0], color[1], color[2]);
			// printf("%f %f %f \n", dir[0], dir[1], dir[2]);
		}
	}
}

	// vec3f	up = (vec3f){0, 1, 0};
	// vec3f	right = normalize(cross_product(up, (vec3f){0, 0, 1}));
	// float	vp_w = tan(180 * M_PI / 180 / 2);
	// float	vp_h = (vp_w / ASPECT_RATIO);
	// vec3f	orig = {0, 0, 0};
	// vec3f	horiz = right * vp_w;
	// vec3f	vert = vp_h * up;
	// vec3f	btm_left_cnr = orig - horiz / 2 - vert / 2 + (vec3f){0, 0, 1};
// void	render(t_img *img)
// {
// 	int	i;
// 	int	j;

// 	// vec3f	camera_direction = {0, 0, 1};
// 	// vec3f	origin = {0, 0, 0};
// 	// vec3f	up = {0, 1, 0};
// 	// vec3f	lower_left = origin + camera_direction * screendistance +

// 	float	screendistance = WIDTH / 2 * tan(90 / 2 * M_PI / 180);
// 	float	scale = tan(90 / 2 * M_PI / 180);//deg2rad(180 * 0.5));
// 	float	aspect_ratio = WIDTH / (float)HEIGHT;
// 	float	x;
// 	float	y;
// 	vec3f	dir;
// 	vec3f	color;

// 	j = 0;
// 	while (j++ < HEIGHT - 1)
// 	{
// 		i = 0;
// 		while (i++ < WIDTH - 1)
// 		{
// 			x = (2 * (i + 0.5) / (float)WIDTH - 1) * aspect_ratio * scale;
// 			y = (1 - 2 * (j + 0.5) / (float)HEIGHT) * scale;
// 			dir = (vec3f){x, y, screendistance};

// 			float t = 0.5*(dir[1] + 1.0);
// 			color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;
// 			// color *= 255.999f;
// 			my_pixel_put(img, i, j, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);
			
// 			// printf("%f %f %f \n", color[0], color[1], color[2]);
// 			// printf("%f %f %f \n", dir[0], dir[1], dir[2]);
// 		}
// 	}
// }