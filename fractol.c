/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/28 22:06:26 by wjuneo-f         ###   ########.fr       */
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

int	exit_event(int keycode, t_variables *var)
{
	(void )var;
	if (keycode == 65307)
	{
		mlx_destroy_image(var->mlx->mlx_ptr, var->img.img_ptr);
		mlx_destroy_window(var->mlx->mlx_ptr, var->mlx->win);
		mlx_destroy_display(var->mlx->mlx_ptr);
		free(var->mlx->mlx_ptr);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->mlx = malloc(sizeof(t_mlx *) * 1);
	initialize_variables(var);
	window_init(var);
	img_init(var);
	draw_scren(var);
	mlx_mouse_hook(var->mlx->win, mouse_event, var);
	mlx_key_hook(var->mlx->win, exit_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	exit(1);
}
