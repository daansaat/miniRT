#ifndef MINIRT_H
# define MINIRT_H

# define ASPECT_RATIO 16.0 / 9.0 // WIDTH / HEIGHT
# define HEIGHT 400
# define WIDTH (int)(HEIGHT * ASPECT_RATIO)
# define BACKGROUNDCOLOR (t_vec3f){255, 255, 255}

typedef struct s_img
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img_ptr;
	t_img	img;
}			t_mlx;

#endif