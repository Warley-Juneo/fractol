/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:41:48 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/22 16:45:07 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_variables(t_variables *var)
{
	var->row = 0;
	var->c_re = 0;
	var->c_im = 0;
	var->iteration = 0;
	var->max = 200;
	var->row = 0;
	var->max = 50;
	var->zoom_max = 700;
	var->zoom_min = 700;
}
