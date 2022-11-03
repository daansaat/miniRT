#include "../inc/miniRT.h"
#include "../inc/vec3f.h"
#include "../inc/ray.h"
#include "../inc/sphere.h"
#include "../inc/parser.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

void	render(t_img *img, t_scene *scene)
{	
	int			x;
	int			y;
	t_camera	cam;
	t_ray		camera_ray;
	vec3f		hitcolor;

	cam = scene->camera;
	camera_ray.origin = cam.origin;
	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			camera_ray.direction = cam.lower_left_corner + cam.horizontal * (float)x + cam.vertical * (float)y - cam.origin;
			hitcolor = cast_ray(camera_ray, scene);
			my_pixel_put(img, x, y, (int)hitcolor[0] << 16 | (int)hitcolor[1] << 8 | (int)hitcolor[2]);			
		}
	}
}

// 	camera.direction = normalize(camera.direction);