/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:51:23 by rthome-d          #+#    #+#             */
/*   Updated: 2023/03/16 20:14:06 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	nbsize_atof(double n)
{
	size_t	i;
	int		x;

	x = (int)n;
	i = 0;
	if (x <= 0)
		i++;
	while (x != 0)
	{
		i++;
		x = x / 10;
	}
	return (i);
}

double	check_signal(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

double	fracatoi(char *str)
{
	double	number;
	size_t	size;
	int		i;
	double	signal;
	double	p;

	i = 1;
	p = 1;
	signal = check_signal(str);
	number = (double)ft_atoi((const char *)str);
	if (signal < 0)
	{
		number = -number;
		i = 2;
	}
	size = nbsize_atof(number);
	while (str[size + i] >= '0' && str[size + i] <= '9')
	{
		number += (str[size + i] - 48) / pow(10, p);
		i++;
		p++;
	}
	return (number * signal);
}

int	ft_is_wrong_digit(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	if ((c >= 0 && c <= 44) || (c >= 58 && c <= 255))
		return (1);
	else
		return (0);
}

void	test_julia(char *argv1, char *argv2)
{
	int	i;

	i = -1;
	while (argv1[++i])
	{
		if (ft_is_wrong_digit(argv1[i]))
		{
			ft_putstr_fd("cr must be a real number.", 2);
			exit (0);
		}
	}
	i = -1;
	while (argv2[++i])
	{
		if (ft_is_wrong_digit(argv2[i]))
		{
			ft_putstr_fd("ci must be a real number.", 2);
			exit (0);
		}
	}
}
