/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/21 21:26:07 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

// int key_event(t_variables *var)
// {
// 	int h;

// 	h = 20;
// 	if (var->iteration < var->max)
// 		var->img.data[var->col * IMG_WIDTH + var->row] \
// 		= 0xfffff + var->iteration * h;
// 	else
// 		var->img.data[var->col * IMG_WIDTH + var->row] = 0x00000 + h;
// 	var->col++;
// 	h += h;
// 	return (0);
// }

void	img_init(t_variables *var)
{
	var->img.img_ptr = mlx_new_image(var->mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
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
	window_init(var);
	img_init(var);
	initialize_variables(var);
	draw_scren(var);
	mlx_put_image_to_window(var->mlx->mlx_ptr, var->mlx->win, \
	var->img.img_ptr, 0, -150);
	mlx_loop(var->mlx->mlx_ptr);
	// mlx_key_hook(var->mlx->win, &key_event, var);
	return (0);
}
