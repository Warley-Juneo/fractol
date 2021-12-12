/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:55:31 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/11 22:13:57 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_verify_true(char c)
{
	if (c == '.')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_verify_param(char **argv)
{
	char	*param;
	int		count;
	int		count2;
	int		i;

	count = 1;
	while (++count < 4)
	{
		i = 0;
		param = argv[count];
		count2 = 0;
		if (param[count2] == '-' || param[count2] == '+')
			count2++;
		while (param[count2])
		{
			if (param[count2] == '.')
				i++;
			if (i > 1)
				return (0);
			if (ft_verify_true(param[count2]) == 0)
				return (0);
		count2++;
		}
	}
	return (1);
}
