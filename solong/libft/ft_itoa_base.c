/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:08:58 by wjuneo-f          #+#    #+#             */
/*   Updated: 2021/09/08 14:09:04 by wjuneo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long int n, char *hex)
{
	char	*str;
	size_t	count;
	size_t	count_digit;
	int		base;

	base = ft_strlen(hex);
	count_digit = ft_count_digit(n);
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(count_digit, sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (n != 0)
	{
		str[count++] = hex[n % base];
		n = (n / base);
	}
	ft_rev(str);
	return (str);
}
