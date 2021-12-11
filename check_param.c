#include "fractol.h"

static int	ft_point_valid(char *number)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (number[i])
	{
		i++;
		if (number[i] == '.')
		{
			c++;
		}
	}
	if (c <= 1)
		return (1);
	else
		return (0);
}

static int	ft_only_digit(char *number)
{
	int	i;
	int	c;
	int	v;

	i = 0;
	c = 0;
	v = 0;
	while (number[i])
	{
		if (number[0] == '-' || number[0] == '+')
		{
			v++;
			i++;
		}
		if (number[i] == '.')
			v ++;
		c += ft_isdigit(number[i]);
		i++;
	}
	if (c == (int)ft_strlen(number) - v)
		return (1);
	else
		return (0);
}

// static int	ft_valid_len(int number)
// {
// 	if (number == 2 || number == 4)
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_verify_param(char **argv, int argc)
{
	if ((argc == 4 && (argv[1][0] == 'j' || argv[1][0] == 'J')))
	{
		if (!ft_only_digit(argv[2]) || !ft_only_digit(argv[3]))
			return (0);
		if (!ft_point_valid(argv[2]) ||  !ft_point_valid(argv[3]))
			return (0);
		return (1);
	}
	else if ((argc == 2) && (argv[1][0] == 'b' || argv[1][0] == 'B'))
		return (1);
	else if ((argc == 2) && (argv[1][0] == 'm' || argv[1][0] == 'M'))
		return (1);
	else
		return (0);
}
