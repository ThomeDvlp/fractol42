/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:36:10 by rthome-d          #+#    #+#             */
/*   Updated: 2022/08/17 13:13:00 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	index;

	if (!str)
		return (write (1, "(null)", 6));
	index = 0;
	while (str[index])
		index++;
	write (1, str, index);
	return (index);
}
