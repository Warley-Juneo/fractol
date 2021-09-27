/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scren.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/27 12:15:23 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static inline void	screen_to_world(t_variables *var, double *world_x, double *world_y)
	{
		*world_x = ((float)var->row) / var->scale + var->x;
		*world_y = ((float)var->col) / var->scale + var->y;
	}

void	draw_frac(t_variables *var)
{
	double x2 = 0, y2 = 0;
	double real = 0;
	double imag = 0;
	int i = 0;
	double c_imag, c_real;

	screen_to_world(var, &c_real, &c_imag);
	while (x2 + y2 <= 4 && i < var->max_iter)
	{
		imag = (real + real) * imag + c_imag;
		real = x2 - y2 + c_real;
		x2 = real * real;
		y2 = imag * imag;
		i++;
	}
	if (i < 15)
		var->img.data[var->col * IMG_WIDTH + var->row] \
		= 0x00008B;
	else if (i > 15 && i <= 25)
		var->img.data[var->col * IMG_WIDTH + var->row] \
		= 0xFF00FF;
	else if (i > 25 && i < var->max_iter)
		var->img.data[var->col * IMG_WIDTH + var->row] \
		= 0xFFFF00;
	else
		var->img.data[var->col * IMG_WIDTH + var->row] = 0x000000;
}

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
}
