void	render(t_img *img)
{
	int	x;
	int	y;

	vec3f	cam_pos = {0, 0, 0};
	vec3f	view_dir = {0, 0, 1};
	float	fov = 150;
	float	screen_distance = (float)WIDTH / 2 / tan(fov / 2 * M_PI / 180);
	float	scale = tan(fov / 2 * M_PI / 180);//deg2rad(180 * 0.5));
	float	aspect_ratio = WIDTH / (float)HEIGHT;
	vec3f	screen_center = cam_pos + view_dir * screen_distance;
	vec3f	p0 = screen_center + (vec3f){-1 * aspect_ratio * scale, 1 * scale, 0};
	vec3f	p1 = screen_center + (vec3f){1 * aspect_ratio * scale, 1 * scale, 0};
	vec3f	p2 = screen_center + (vec3f){-1 * aspect_ratio * scale, -1 * scale, 0};

	y = 0;
	while (y++ < HEIGHT - 1)
	{
		x = 0;
		while (x++ < WIDTH - 1)
		{
			float	u = (float)x / WIDTH;
			float	v = (float)y / HEIGHT;

			vec3f	point_on_screen = p0 + (p1 - p0) * u + (p2 - p0) * v;
			vec3f	ray_direction = point_on_screen - cam_pos;


			t_ray	r;
			r.origin = cam_pos;
			r.direction = ray_direction;

			vec3f color;
			if (hit_sphere((vec3f){0, 0, -50}, 0.5, r))
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
			
		}
	}
}

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