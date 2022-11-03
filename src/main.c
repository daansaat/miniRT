#include "../inc/miniRT.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

#include "../inc/vec3f.h"
#include "../inc/render.h"

#include <stdio.h>
#include <unistd.h>

// void	color_img(t_img *img)
// {
// 	int x = 0;
// 	int y = 0;

// 	double r;
// 	double g;
// 	double b;
	
// 	int ir;
// 	int ig;
// 	int ib;

// 	while (y++ < HEIGHT - 1)
// 	{
// 		x = 0;
// 		while (x++ < WIDTH - 1) 
// 		{
// 			r = (double)x / (WIDTH - 1);
// 			g = (double)y / (HEIGHT - 1);
// 			b = 0.25;
// 			ir = 255 * r;
// 			ig = 255 * g;
// 			ib = 255 * b;
// 			my_pixel_put(img, x, y, ir << 16 | ig << 8 | ib);
// 		}
// 	}
// 	return;
// }

int	main(void)
{
	// vec3f	point1 = {4,2,3};
	// vec3f	point2 = {1,6,3};
	// vec3f	point3 = cross_product(point1, point2);

	// printf("%f %f %f\n", point3[0], point3[1], point3[2]);

	// point = {1,2,3};
	// point = (t_vec4){0, 1, 0};
	
	t_img	img;
	void	*ptr;
	void	*win;
	void	*img_ptr;
		
	ptr = mlx_init();
	win = mlx_new_window(ptr, WIDTH, HEIGHT, "miniRT");
	img_ptr = mlx_new_image(ptr, WIDTH + 1, HEIGHT + 1);
	img.addr = mlx_get_data_addr(img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	render(&img);
	// color_img(&img);
	mlx_put_image_to_window(ptr, win, img_ptr, 0, 0);
	mlx_loop(ptr);
	return (0);
}
