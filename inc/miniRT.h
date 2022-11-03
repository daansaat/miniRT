#ifndef MINIRT_H
# define MINIRT_H

# define ASPECT_RATIO 16.0 / 9.0 // WIDTH / HEIGHT
# define HEIGHT 400
# define WIDTH (int)(HEIGHT * ASPECT_RATIO)

typedef struct s_img
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

void	my_pixel_put(t_img *img, int x, int y, unsigned int colour);

#endif