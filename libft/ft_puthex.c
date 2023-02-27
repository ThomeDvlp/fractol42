/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:36:00 by rthome-d          #+#    #+#             */
/*   Updated: 2022/08/17 13:10:32 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_mlen(unsigned long nbr)
{
	int	mlen;

	mlen = 0;
	while (nbr)
	{
		nbr /= 16;
		mlen++;
	}
	return (mlen);
}

int	ft_puthex(unsigned long nbr, char *hexref)
{
	int		mlen;
	char	*convertion;
	int		output;

	if (nbr == 0)
		return (ft_putchar('0'));
	mlen = ft_mlen(nbr);
	convertion = (char *)malloc(sizeof(char) * (mlen + 1));
	if (!convertion)
		return (0);
	convertion[mlen] = 0;
	while (mlen)
	{
		convertion[mlen -1] = hexref[nbr % 16];
		nbr /= 16;
		mlen--;
	}
	output = ft_putstr(convertion);
	free (convertion);
	return (output);
}
