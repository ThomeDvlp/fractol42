/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:18:17 by rthome-d          #+#    #+#             */
/*   Updated: 2022/08/17 13:14:38 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_unlen(unsigned int nbr)
{
	int	index;

	index = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		index++;
	}
	return (index + 1);
}

static	int	wrt_str(unsigned int nbr, int index, char *str)
{
	while (index > 0)
	{
		str[index] = (nbr % 10) + '0';
		nbr /= 10;
		index--;
	}
	return (nbr);
}

static	char	*ft_utoa(unsigned int n)
{
	int				index;
	char			*str;

	index = ft_unlen(n);
	str = (char *)malloc((index + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[index--] = 0;
	*str = (wrt_str(n, index, str) % 10) + '0';
	return (str);
}

int	ft_putunbr(unsigned int unbr)
{
	char			*str;
	unsigned int	output;

	str = ft_utoa(unbr);
	output = ft_putstr(str);
	free (str);
	return (output);
}
