/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:48 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/27 11:41:58 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_variables(t_variables *var)
{
	var->row = 0;
	var->c_re = 0;
	var->c_im = 0;
	var->iteration = 0;
	var->max_iter = 50;
	var->row = 0;
	var->mouse = 1;
	var->x = -1.5;
	var->y = 1.0;
	var->scale = 300;
}
