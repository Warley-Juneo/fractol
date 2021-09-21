#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

void	initialize_variables(t_variables *var)
{
	var->row = 0;
	var->col = 0;
	var->c_re = 0;
	var->c_im = 0;
	var->iteration = 0;
	var->max = 200;
	var->x = 0;
	var->y = 0;
	var->row = 0;
}

void	draw_frac(t_variables *var)
{
	while (var->x * var->x + var->y * var->y <= 4 \
	&& var->iteration < var->max)
	{
		var->x_new = var->x * var->x - var->y * var->y + var->c_re;
		var->y = 2 * var->x * var->y + var->c_im;
		var->x = var->x_new;
		var->iteration++;
	}
	if (var->iteration < var->max)
		var->img.data[var->col * IMG_WIDTH + var->row] \
		= 0xfffff + var->iteration * 3.5;
	else
		var->img.data[var->col * IMG_WIDTH + var->row] = 0x00000;
	var->col++;
}

void	draw_scren(t_variables *var)
{
	while (var->row < IMG_HEIGHT)
	{
		var->col = 0;
		while (var->col < IMG_WIDTH)
		{
			var->c_re = (var->row - IMG_WIDTH / 2.0) * 4.0 / IMG_WIDTH;
			var->c_im = (var->col - IMG_HEIGHT / 2.0) * 4.0 / IMG_WIDTH;
			var->x = 0;
			var->y = 0;
			var->iteration = 0;
			draw_frac(var);
		}
		var->row++;
	}
}

int	main(void)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->max = 50;
	var->mlx = malloc(sizeof(void *) * 1);
	var->mlx->mlx_ptr = mlx_init();
	var->mlx->win = mlx_new_window(var->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, &var->img.bpp, \
	&var->img.size_l, &var->img.endian);
	initialize_variables(var);
	draw_scren(var);
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, -150);
	mlx_loop(var->mlx->mlx_ptr);
	return (0);
}
