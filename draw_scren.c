/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scren.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/21 22:50:25 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		var->img.data[var->col * var->zoom_max + var->row] \
		= 0xfffff + var->iteration * 4.5;
	else
		var->img.data[var->col * var->zoom_max + var->row] = 0x00000;
	var->col++;
}

void	draw_scren(t_variables *var)
{
	while (var->row < var->zoom_max)
	{
		var->col = 0;
		while (var->col < var->zoom_max)
		{
			var->c_re = (var->row - var->zoom_max / 2.0) * 4.0 / var->zoom_max;
			var->c_im = (var->col - var->zoom_max / 2.0) * 4.0 / var->zoom_max;
			var->x = 0;
			var->y = 0;
			var->iteration = 0;
			draw_frac(var);
		}
		var->row++;
	}
}
