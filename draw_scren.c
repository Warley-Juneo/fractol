#include "fractol.h"

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
