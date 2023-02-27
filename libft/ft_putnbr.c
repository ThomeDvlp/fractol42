/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:46:25 by rthome-d          #+#    #+#             */
/*   Updated: 2022/08/17 13:11:49 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	char	*strnb;
	int		value;

	strnb = ft_itoa(nbr);
	value = ft_putstr(strnb);
	free (strnb);
	return (value);
}
