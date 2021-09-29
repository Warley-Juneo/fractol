/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:57:10 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/28 21:54:16 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen_to_world(t_variables *var, double *world_x, double *world_y)
{
	*world_x = ((float)var->row) / var->scale + var->x;
	*world_y = ((float)var->col) / var->scale + var->y;
}

void	scree_to_julia(t_variables *var, double *world_x, double *world_y)
{
	*world_x = 1.5 * (var->row - IMG_WIDTH / 2) / \
	(0.5 * 1 * IMG_WIDTH) + 0;
	*world_y = 1.0*(var->col - IMG_WIDTH/2)/(0.5* 1*IMG_HEIGHT) +  0;
}
