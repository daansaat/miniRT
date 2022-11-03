#include "../inc/miniRT.h"
#include "../inc/parser.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

#include "../inc/vec3f.h"
#include "../inc/render.h"

#include <stdio.h>
#include <unistd.h>

int	main(void)
{	
	t_img	img;
	t_scene	scene;
	void	*ptr;
	void	*win;
	void	*img_ptr;
		
	scene.objects = NULL;
	ptr = mlx_init();
	win = mlx_new_window(ptr, WIDTH, HEIGHT, "miniRT");
	img_ptr = mlx_new_image(ptr, WIDTH + 1, HEIGHT + 1);
	img.addr = mlx_get_data_addr(img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	create_scene(&scene);
	render(&img, &scene);
	mlx_put_image_to_window(ptr, win, img_ptr, 0, 0);
	mlx_loop(ptr);
	return (0);
}
