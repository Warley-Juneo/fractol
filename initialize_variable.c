/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:48 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/10/02 16:47:13 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_variables(t_variables *var)
{
	var->row = 0;
	var->c_re = -0.70176;
	var->c_im = 0.3842;
	var->iteration = 0;
	var->max_iter = 50;
	var->row = 0;
	var->mouse = 1;
	var->x = -1.7;
	var->y = -1.5;
	var->scale = 200;
	var->i = 0;
	var->r = 0;
	var->g = 0;
	var->b = 0;
	var->h = 0;
	var->indentify = 0;
	generate_colors(var);
}
