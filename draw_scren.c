/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scren.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/22 17:21:00 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_pow(double number, double pow)
{
	return (number * pow);
}

static double	ft_complex(t_variables *var)
{
	return (ft_pow(var->x, 2) + ft_pow(var->y, 2));
}

void	draw_frac(t_variables *var)
{
	while (ft_complex(var) <= 4 && var->iteration < var->max)
	{
		var->x_new = ft_pow(var->x, var->x) - ft_pow(var->y, var->y);
		var->y = 2 * var->x * var->y + var->c_im;
		var->x = var->x_new + var->c_re;
		var->iteration++;
	}
	if (var->iteration < 15)
		var->img.data[var->col * var->zoom_max + var->row] \
		= 0x00008B;
	else if (var->iteration > 15 && var->iteration <= 25)
		var->img.data[var->col * var->zoom_max + var->row] \
		= 0xFF00FF;
	else if (var->iteration > 25 && var->iteration < var->max)
		var->img.data[var->col * var->zoom_max + var->row] \
		= 0xFFFF00;
	else
		var->img.data[var->col * var->zoom_max + var->row] = 0x000000;
	var->col++;
}

void	draw_scren(t_variables *var, double zoom)
{
	while (var->row < var->zoom_max)
	{
		var->col = 0;
		while (var->col < var->zoom_max)
		{
			var->c_re = (var->row - var->zoom_max / 2.0) * 4.0 / (700 + zoom);
			var->c_im = (var->col - var->zoom_max / 2.0) * 4.0 / (700 + zoom);
			var->x = 0;
			var->y = 0;
			var->iteration = 0;
			draw_frac(var);
		}
		var->row++;
	}
}
