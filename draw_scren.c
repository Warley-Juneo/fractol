/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scren.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:55 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/08 17:29:12 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int    ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

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

void	draw_julia(t_variables *var)
{
	double R = 4;
	double real = 0;
	double imag = 0;
	int i = 0;
	double x2 = 0, y2 = 0;

	real = var->row / var->scale + var->x;
	imag = var->col / var->scale + var->y;
	x2 = real * real;
	y2 = imag * imag;

	while (x2 + y2 <= R && i < var->max_iter)
	{
		imag =  (real + real) * imag + var->c_im;
		real = x2 - y2 + var->c_re;
		x2 = real * real;
		y2 = imag * imag;
		i++;
	}
	var->img.data[var->col * IMG_WIDTH + var->row] = var->colors[i];
}

void	draw_burnishp(t_variables *var)
{
	double	aux;
	double	real;
	double	imag;
	int		i;

	real = 0;
	imag = 0;
	i = 0;
	screen_to_world(var, &var->c_re, &var->c_im);
	while ((real * real) + (imag * imag) <= 4 && i < var->max_iter)
	{
		aux = (real * real) - (imag * imag) + var->c_re;
		imag = ft_abs((2.0 * real * imag)) + var->c_im;
		real = aux;
		i++;
	}
	var->img.data[var->col * IMG_WIDTH + var->row] = var->colors[i];
}

void	draw_scren(t_variables *var)
{
	var->row = 0;
	while (var->row < IMG_WIDTH)
	{
		var->col = 0;
		while (var->col < IMG_WIDTH)
		{
			if (var->indentify == 1)
				draw_julia(var);
			else if (var->indentify == 0)
				draw_frac(var);
			else if (var->indentify == 2)
				draw_burnishp(var);
			var->col++;
		}
		var->row++;
	}
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, 0);
}
