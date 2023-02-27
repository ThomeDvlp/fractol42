/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthome-d <rthome-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:48:22 by rthome-d          #+#    #+#             */
/*   Updated: 2022/12/08 19:48:22 by rthome-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	count;

	count = 0;
	if (!s1)
		return (-1);
	else if (!s2)
		return (1);
	while (s1[count] == s2[count] && (s1[count] != '\0' && s2[count] != '\0'))
	{
		count ++;
	}
	if (s1[count] > s2[count])
		return (1);
	else if (s1[count] < s2[count])
		return (-1);
	else
		return (0);
}
