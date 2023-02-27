/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:42:12 by rthome-d          #+#    #+#             */
/*   Updated: 2022/08/17 13:19:24 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_switcher(va_list arg, const char type)
{
	int		value;

	value = 0;
	if (type == '%')
		value += ft_putchar('%');
	else if (type == 'c')
		value += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		value += ft_putstr(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		value += ft_putnbr(va_arg(arg, int));
	else if (type == 'u')
		value += ft_putunbr(va_arg(arg, unsigned int));
	else if (type == 'x')
		value += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		value += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (type == 'p')
	{
		value += ft_putstr("0x");
		value += ft_puthex(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	return (value);
}

int	ft_printf(const char *inputntype, ...)
{
	int		index;
	va_list	arg;
	int		output;

	va_start(arg, inputntype);
	index = 0;
	output = 0;
	while (inputntype[index])
	{
		if (inputntype[index] == '%'
			&& ft_strchr("cspiduxX%", inputntype[index + 1]))
		{
			output += ft_switcher(arg, inputntype[index +1]);
			index++;
		}
		else
			output += ft_putchar(inputntype[index]);
	index++;
	}
	va_end(arg);
	return (output);
}
