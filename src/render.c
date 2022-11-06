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
	t_ray		cam_ray;
	t_vec3f		color;

	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			cam_ray.origin = camera.origin;
			cam_ray.direction = normalize(camera.lower_left_corner \
				+ camera.horizontal * (float)x \
				+ camera.vertical * (float)y - camera.origin);
			color = cast_ray(cam_ray, scene);
			my_pixel_put(img, x, HEIGHT - y, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);			
		}
	}
}
