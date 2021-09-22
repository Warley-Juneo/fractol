/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/22 17:29:30 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

void	img_init(t_variables *var)
{
	var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, \
	var->zoom_max, var->zoom_max);
	var->img.data = (int *)mlx_get_data_addr(var->img.img_ptr, &var->img.bpp, \
	&var->img.size_l, &var->img.endian);
}

void	window_init(t_variables *var)
{
	var->mlx->mlx_ptr = mlx_init();
	var->mlx->win = mlx_new_window(var->mlx->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "fractol");
}

int	key_event(int keycode, int x, int y, t_variables *var)
{
	x += 0;
	y += 0;
	if (keycode == 4)
	{
		img_init(var);
		draw_scren(var, 50);
		mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
		var->img.img_ptr, 0, -95);
	}
	else if (keycode == 5)
	{
		img_init(var);
		draw_scren(var, -50);
		mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
		var->img.img_ptr, 0, -95);
	}
	return (0);
}

int	main(void)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->mlx = malloc(sizeof(void *) * 1);
	initialize_variables(var);
	window_init(var);
	img_init(var);
	draw_scren(var, 0);
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, -95);
	mlx_mouse_hook(var->mlx->win, key_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	return (0);
}
