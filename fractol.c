/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/21 23:07:51 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

int key_event(int keycode, int x, int y, t_variables *var)
{
	x += 0;
	y += 0;
	if (keycode == 4)
	{
		var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, var->zoom_max + 50, var->zoom_min + 50);
		var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, \
		&var->img.bpp, &var->img.size_l, &var->img.endian);
	}
	else if(keycode == 5)
	{
		var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, var->zoom_max - 50, var->zoom_min - 50);
		var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, \
		&var->img.bpp, &var->img.size_l, &var->img.endian);
	}
	return (0);
}

void	img_init(t_variables *var)
{
	var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, var->zoom_max, var->zoom_max);
	var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, &var->img.bpp, \
	&var->img.size_l, &var->img.endian);
}

void	window_init(t_variables *var)
{
	var->mlx->mlx_ptr = mlx_init();
	var->mlx->win = mlx_new_window(var->mlx->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "fractol");
}

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
	var->img.img_ptr, 0, -95);
	mlx_mouse_hook(var->mlx->win, key_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	return (0);
}
