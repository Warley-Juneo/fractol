/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:58:30 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/08 13:58:43 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str) - 1;
	i = 0;
	while (str[i] && i < length)
	{
		tmp = str[i];
		str[i] = str[length];
		str[length] = tmp;
		i++;
		length--;
	}
}
