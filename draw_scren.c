/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scren.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/28 21:55:38 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_frac(t_variables *var)
{
	double	x2;
	double	y2;
	double	real;
	double	imag;
	int		i;

	x2 = 0;
	y2 = 0;
	real = 0;
	imag = 0;
	i = 0;
	screen_to_world(var, &var->c_re, &var->c_im);
	while (x2 + y2 <= 4 && i < var->max_iter)
	{
		imag = (real + real) * imag + var->c_im;
		real = x2 - y2 + var->c_re;
		x2 = real * real;
		y2 = imag * imag;
		i++;
	}
	var->img.data[var->col * IMG_WIDTH + var->row] = var->colors[i];
}

// void	draw_julia(t_variables *var)
// {
// 	float temp;
// 	float cX;
// 	float cY;
// 	int i;

// 	cX = -0.7;
// 	cY = 0.27015;
// 	i = 255;

// 	scree_to_julia(var, &var->c_re, &var->c_im);
// 	while ((var->c_re * var->c_re) + (var->c_im * var->c_im) < 4 && i > 1)
// 	{
// 		temp = var->c_re * var->c_re - var->c_im * var->c_im + cX;
// 		var->c_re = 2.0 * var->c_re * var->c_im + cY;
// 		var->c_im = temp;
// 		i -= 1;
// 	}
// 	var->img.data[var->col * IMG_WIDTH + var->row] = var->colors[i];
// }

void	draw_scren(t_variables *var)
{
	var->row = 0;
	while (var->row < IMG_WIDTH)
	{
		var->col = 0;
		while (var->col < IMG_WIDTH)
		{
			draw_frac(var);
			var->col++;
		}
		var->row++;
	}
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, 0);
}
