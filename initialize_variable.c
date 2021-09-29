/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:48 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/28 20:58:56 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_variables(t_variables *var)
{
	var->row = 0;
	var->c_re = 0;
	var->c_im = 0;
	var->iteration = 0;
	var->max_iter = 150;
	var->row = 0;
	var->mouse = 1;
	var->x = -1.5;
	var->y = -1.0;
	var->scale = 250;
	var->i = 0;
	var->r = 0;
	var->g = 0;
	var->b = 0;
	var->h = 0;
	generate_colors(var);
}
