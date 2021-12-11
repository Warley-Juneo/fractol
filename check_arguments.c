/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:03:26 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/11 19:58:07 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_argument(int argc, char **argv, t_variables *var)
{
	if (argv[1][0] == 'J')
	{
		var->indentify = 1;
		if (argv[2] && argc > 2)
		{
			if (ft_atod(argv[2]) != -1)
				var->c_im = ft_atod(argv[2]);
			else
				exit(1);
		}
		if (argv[3] && argc > 2)
		{
			if (ft_atod(argv[3]) != -1)
				var->c_re = ft_atod(argv[3]);
			else
				exit(1);
		}
	}
	return (0);
}
