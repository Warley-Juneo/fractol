/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:39:32 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/14 02:13:59 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	key_event(int keycode, t_variables *var)
{
	apply_comands(keycode, var);
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

int	invalid_args(t_variables *var)
{
	free(var->mlx);
	free(var);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_variables	*var;

	if (((argc != 2 && argc != 4) || argv[1][1] || (argv[1][0] != 'J' && \
	argv[1][0] != 'M' && argv[1][0] != 'B')))
	{
		printf("digite 'M', 'J' ou 'B' para mandelbroth, Julia ou Burniship \
		respectivamente, Você pode digitar parametros para o Julia. Real/Imag");
		exit(1);
	}
	var = malloc(sizeof(t_variables) * 1);
	var->mlx = malloc(sizeof(t_mlx) * 1);
	initialize_variables(var);
	if (argv[1][0] == 'J' && argv[2] && argv[3])
	{
		if (ft_verify_param(argv) == 0)
			invalid_args(var);
	}
	check_argument(argc, argv, var);
	window_init(var);
	img_init(var);
	draw_scren(var);
	mlx_mouse_hook(var->mlx->win, mouse_event, var);
	mlx_key_hook(var->mlx->win, key_event, var);
	mlx_loop(var->mlx->mlx_ptr);
	exit(1);
}
