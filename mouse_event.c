/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:57:30 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/13 19:43:47 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_aplication(t_variables *var, float factor)
{
	double	mouse_x_before_zoom;
	double	mouse_y_before_zoom;
	double	mouse_x_after_zoom;
	double	mouse_y_after_zoom;

	mlx_mouse_get_pos(var->mlx->mlx_ptr, var->mlx->win, &var->m_x2, &var->m_y2);
	mouse_x_before_zoom = ((float)var->m_x2) / var->scale + var->x;
	mouse_y_before_zoom = ((float)var->m_y2) / var->scale + var->y;
	var->scale *= factor;
	mouse_x_after_zoom = ((float)var->m_x2) / var->scale + var->x;
	mouse_y_after_zoom = ((float)var->m_y2) / var->scale + var->y;
	var->x += mouse_x_before_zoom - mouse_x_after_zoom;
	var->y += mouse_y_before_zoom - mouse_y_after_zoom;
	draw_scren(var);
}

int	mouse_event(int keycode, int x, int y, t_variables *var)
{
	(void)x;
	(void)y;
	var->i++;
	if (keycode == 5)
		zoom_aplication(var, .9);
	if (keycode == 4)
		zoom_aplication(var, 1.1);
	return (0);
}

int	apply_comands(int keycode, t_variables *var)
{
	if (keycode == 119 || keycode == 65362)
	{
		var->y += (fabs(var->y / var->scale) * -1);
		draw_scren(var);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		var->y -= (fabs(var->y / var->scale) * -1);
		draw_scren(var);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		var->x += (fabs(var->x / var->scale) * -1);
		draw_scren(var);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		var->x -= (fabs(var->x / var->scale) * -1);
		draw_scren(var);
	}
	return (0);
}
