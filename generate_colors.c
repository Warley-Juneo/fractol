/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:56:35 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/28 21:35:38 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_colors(t_variables *fractol)
{
	int		iter;
	float	factor;
	float	diff;

	iter = 0;
	factor = 0;
	while (iter < fractol->max_iter)
	{
		factor = (float)iter / fractol->max_iter;
		if (iter < fractol->max_iter / 2)
			fractol->colors[iter] = 255 * iter / fractol->max_iter;
		else
		{
			diff = 1. - factor;
			fractol->r = 9 * diff * (factor * factor * factor) * 255;
			fractol->g = 15 * (diff * diff) * (factor * factor) * 255;
			fractol->b = 8.5 * (diff * diff * diff) * factor * 255;
			fractol->colors[iter] = (fractol->r & 0xff) \
			<< 16 |(fractol->g & 0xff) << 8 | (fractol->b & 0xff);
		}
		iter++;
	}
}
