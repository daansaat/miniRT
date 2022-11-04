#include "../inc/miniRT.h"
#include "../inc/vec3f.h"
#include "../inc/ray.h"
#include "../inc/intersect.h"
#include "../inc/parser.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>

static void	my_pixel_put(t_img *img, int x, int y, unsigned int colour)
{
	char	*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int *)dst = colour;
}

void	render(t_img *img, t_scene *scene, t_camera camera)
{	
	int			x;
	int			y;
	t_ray		camera_ray;
	t_vec3f		hitcolor;

	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			camera_ray.origin = camera.origin;
			camera_ray.direction = normalize(camera.lower_left_corner + camera.horizontal * (float)x + camera.vertical * (float)y - camera.origin);
			// camera.direction = normalize(camera.direction);
			hitcolor = cast_ray(camera_ray, scene);
			my_pixel_put(img, x, y, (int)hitcolor[0] << 16 | (int)hitcolor[1] << 8 | (int)hitcolor[2]);			
		}
	}
}
