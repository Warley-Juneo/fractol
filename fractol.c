/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/11/08 17:13:52 by wjuneo-f         ###   ########.fr       */
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
		free(var->mlx);
		free(var);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->mlx = malloc(sizeof(t_mlx) * 1);
	initialize_variables(var);

	if (argc < 2 || (argv[1][0] != 'J' && argv[1][0] != 'M' && argv[1][0] != 'B'))
	{
		printf("Define um parametro para vizualizar um tipo de fractol\n");
		printf("Digite 'M' para mandelbroth Ou 'J' para o Julia\n");
		printf("Caso você escolha o julia, você também pode passar parametros para o valor imaginario/real consecutivamente");
		exit(1);
	}
	if (argv[1][0] == 'J')
	{
		var->indentify = 1;
		if (argv[2] && argc > 2)
		{
			var->c_im = ft_atod(argv[2]);
		}
		if (argv[3] && argc > 2)
		{
			var->c_re = ft_atod(argv[3]);
		}
	}
	if (argv[1][0] == 'B')
	{
		var->indentify = 2;
		var->c_im = var->col / var->scale + var->m_y2;
		var->c_re = var->row / var->scale + var->m_x2;
	}
	window_init(var);
	img_init(var);
	draw_scren(var);
	mlx_mouse_hook(var->mlx->win, mouse_event, var);
	mlx_key_hook(var->mlx->win, exit_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	exit(1);
}
