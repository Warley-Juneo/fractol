/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:57:10 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/11 18:48:19 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen_to_world(t_variables *var, double *world_x, double *world_y)
{
	*world_x = ((float)var->row) / var->scale + var->x;
	*world_y = ((float)var->col) / var->scale + var->y;
}
