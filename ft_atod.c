/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.brr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 07:32:43 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/12/11 20:04:14 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static double	ft_pow(double x, double n)
{
	int		c;
	double	r;

	r = 1;
	c = 0;
	while (c < n)
	{
		r = r * x;
		c++;
	}
	return (r);
}

static int	reverse_point_position(const char *str)
{
	int	i;
	int	c;
	int	r;

	c = '.';
	r = 0;
	i = ft_strlen(str);
	while (str[--i])
	{
		if (str[i] == (unsigned char)c)
			return (r);
		r++;
	}
	return (0);
}

double	ft_atod(const char *nptr)
{
	size_t	i;
	int		number;
	int		signal;

	number = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	signal = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
while (ft_isdigit(nptr[i]) || nptr[i] == '.')
	{
		if (nptr[i] == '.')
			i++;
		number = (nptr[i] - 48) + (number * 10);
		i++;
	}
	return (signal * (number / ft_pow(10, reverse_point_position(nptr))));
}
