void	render(t_img *img)
{
	int	i;
	int	j;

	// vec3f	camera_direction = {0, 0, 1};
	// vec3f	origin = {0, 0, 0};
	// vec3f	up = {0, 1, 0};
	// vec3f	lower_left = origin + camera_direction * screendistance +

	float	screendistance = WIDTH / 2 * tan(150 / 2 * M_PI / 180);
	float	scale = tan(150 / 2 * M_PI / 180);//deg2rad(180 * 0.5));
	float	aspect_ratio = WIDTH / (float)HEIGHT;
	float	x;
	float	y;
	vec3f	dir;
	vec3f	color;

	j = 0;
	while (j++ < HEIGHT)
	{
		i = 0;
		while (i++ < WIDTH)
		{
			x = (2 * (i + 0.5) / (float)WIDTH - 1) * aspect_ratio * scale;
			y = (1 - 2 * (j + 0.5) / (float)HEIGHT) * scale;
			dir = (vec3f){x, y, screendistance};

			float t = 0.5*(dir[1] + 1.0);
			color = (1.0f-t)*(vec3f){1.0, 1.0, 1.0} + t*(vec3f){0.5, 0.7, 1.0} * 255.999f;
			// color *= 255.999f;
			my_pixel_put(img, i, j, (int)color[0] << 16 | (int)color[1] << 8 | (int)color[2]);
			
			// printf("%f %f %f \n", color[0], color[1], color[2]);
			// printf("%f %f %f \n", dir[0], dir[1], dir[2]);
		}
	}
}