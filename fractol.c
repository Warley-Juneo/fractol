#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

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
