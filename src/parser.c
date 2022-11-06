#include "../inc/miniRT.h"
#include "../inc/vec3f.h"
#include "../inc/parser.h"
#include "../inc/intersect.h"
#include "../libft/libft.h"
#include <fcntl.h>

#include <stdio.h>

t_vec3f	get_vec3f(char *input)
{
	char	**xyz;
	float	x;
	float	y;
	float	z;

	xyz = ft_split(input, ',');
	x = ft_atof(xyz[0]);
	y = ft_atof(xyz[1]);
	z = ft_atof(xyz[2]);
	return ((t_vec3f){x, y, z});
	//ERROR RANGE ETC
}

void	parse_ambient(char **input, t_scene *scene)
{
	static int	i = 0;

	if (++i > 1)
		exit(1);//ERROR
	scene->light.ambient = ft_atof(input[1]);
	scene->light.ambient_color = get_vec3f(input[2]);
}

void	parse_camera(char **input, t_scene *scene)
{
	static int	i = 0;

	if (++i > 1)
		exit(1);//ERROR
	scene->camera.origin = get_vec3f(input[1]);
	scene->camera.direction = get_vec3f(input[2]);
	scene->camera.fov = ft_atof(input[3]);
	scene->camera.screen_distance = (float)WIDTH / 2 / tan(scene->camera.fov / 2 * M_PI / 180);
	scene->camera.horizontal = normalize(cross_product(scene->camera.direction, (t_vec3f){0, 1, 0}));
	scene->camera.vertical = normalize(cross_product(scene->camera.horizontal, scene->camera.direction));
	scene->camera.lower_left_corner = scene->camera.origin \
		+ scene->camera.direction * scene->camera.screen_distance \
		- scene->camera.horizontal * (((float)WIDTH - 1.0) / 2) \
		- scene->camera.vertical * (((float)HEIGHT - 1.0) / 2);
	//FREE INPUT
}

void	parse_light(char **input, t_scene *scene)
{
	static int	i = 0;

	if (++i > 1)
		exit(1);//ERROR
	scene->light.origin = get_vec3f(input[1]);
	scene->light.brightness = ft_atof(input[2]);
}

void	parse_sphere(char **input, t_scene *scene)
{
	t_object	*sphere;
	t_list		*new;

	sphere = malloc(sizeof(t_object));
	if (!sphere)
		exit(1); //ERROR
	sphere->center = get_vec3f(input[1]);
	sphere->hitpoint.center = get_vec3f(input[1]);
	sphere->color = get_vec3f(input[3]);
	sphere->radius = ft_atof(input[2]);
	sphere->intersect = &intersect_sphere;
	new = ft_lstnew(sphere);
	ft_lstadd_back(&(scene->objects), new);
}

void	parse_plane(char **input, t_scene *scene)
{
	t_object	*plane;
	t_list		*new;

	plane = malloc(sizeof(t_object));
	if (!plane)
		exit(1); //ERROR
	plane->center = get_vec3f(input[1]);
	plane->hitpoint.center = get_vec3f(input[1]);
	plane->direction = get_vec3f(input[2]);
	plane->color = get_vec3f(input[3]);
	plane->intersect = &intersect_plane;
	new = ft_lstnew(plane);
	ft_lstadd_back(&(scene->objects), new);
	return;
}

void	parse_cylinder(char **input, t_scene *scene)
{
	return;
}

void	parse_rt_file(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**input;

	fd = open(file, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		input = ft_split(line, ' ');
		if (!ft_strncmp(input[0], "A", 1))
			parse_ambient(input, scene);
		else if (!ft_strncmp(input[0], "C", 1))
			parse_camera(input, scene);
		else if (!ft_strncmp(input[0], "L", 1))
			parse_light(input, scene);
		else if (!ft_strncmp(input[0], "sp", 2))
			parse_sphere(input, scene);
		else if (!ft_strncmp(input[0], "pl", 2))
			parse_plane(input, scene);
		else if (!ft_strncmp(input[0], "cy", 2))
			parse_cylinder(input, scene);
		else if (ft_strcmp(input[0], "\n")) //HOW TO GET # WORKING?? || ft_strcmp(input[0], "#"))
			exit(1); //ERROR
		line = ft_get_next_line(fd);
	}
	//CLOSE file
	//FREE line
}
