#include "../inc/miniRT.h"
#include "../inc/parser.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

#include "../inc/vec3f.h"
#include "../inc/render.h"

#include <stdio.h>
#include <unistd.h>

# define ESC 53

static int	close_program(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
	//FREE MLX ENOUGH??
}

static int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char *argv[])
{	
	t_mlx	mlx;
	t_scene	scene;
		
	// t_vec3f color = {70, 70, 70};
	// t_vec3f normal = normalize(color);
	// printf("%f %f %f\n", normal[0], normal[1], normal[2]);
	// normal = normalize_color(color);
	// printf("%f %f %f\n", normal[0], normal[1], normal[2]);
	// exit(0);
	scene.objects = NULL; //WHY SEGVAULT IF NOT???
	mlx.ptr = mlx_init(); //MALLOC
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "miniRT"); //MALLOC
	mlx.img_ptr = mlx_new_image(mlx.ptr, WIDTH + 1, HEIGHT + 1); //MALLOC
	mlx.img.addr = mlx_get_data_addr(mlx.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	parse_rt_file(argv[1], &scene);
	render(&mlx.img, &scene, scene.camera);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win, 2, 0, keypress, &mlx);
	mlx_hook(mlx.win, 17, 0, close_program, &mlx);
	mlx_loop(mlx.ptr);
	//FREE SCENE
	//FREE MLX
	return (0);
}
