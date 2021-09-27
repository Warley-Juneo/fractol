/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/27 12:12:51 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

void	img_init(t_variables *var)
{
	var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
	var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, &var->img.bpp, \
	&var->img.size_l, &var->img.endian);
}

void	window_init(t_variables *var)
{
	var->mlx->mlx_ptr = mlx_init();
	var->mlx->win = mlx_new_window(var->mlx->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "fractol");
}

// void	zoom_aplication(t_variables *var, float factor)
// {
// 	int x;
// 	int y;
// 	double mouse_x_before_zoom;
// 	double mouse_y_before_zoom;
// 	double mouse_x_after_zoom;
// 	double mouse_y_after_zoom;

// 	mlx_mouse_get_pos(var->mlx->mlx_ptr, var->mlx->win, &x, &y);
// 	mouse_x_before_zoom = ((float)x) / var->scale + var->x;
// 	mouse_y_before_zoom = ((float)y) / var->scale + var->y;
// 	var->scale *= factor;
// 	mouse_x_after_zoom = ((float)x) / var->scale + var->x;
// 	mouse_y_after_zoom = ((float)y) / var->scale + var->y;
// 	var->x += mouse_x_before_zoom - mouse_x_after_zoom;
// 	var->y += mouse_y_before_zoom - mouse_y_after_zoom;
// }

// int	mouse_event(int keycode, int x, int y, t_variables *var)
// {
// 	(void)x;
// 	(void)y;

// 	if (keycode == 4)
// 		zoom_aplication(var, .9);
// 	else
// 		zoom_aplication(var, 1.1);
// 	return (0);
// }

int	main(void)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->mlx = malloc(sizeof(void *) * 1);
	initialize_variables(var);
	window_init(var);
	img_init(var);
	draw_scren(var);
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, +0);
	// mlx_mouse_hook(var->mlx->win, mouse_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	return (0);
}
