/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:04:44 by exam              #+#    #+#             */
/*   Updated: 2018/11/07 16:09:14 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nb)
{
	int		tmp;
	int		pow;
	char	*str;
	int		mod;

	tmp = nb;
	mod = nb < 0;
	pow = 1;
	while (tmp /= 10)
		pow++;
	if (!(str = (char *)malloc(pow + mod + 1)))
		return (NULL);
	str[pow + mod] = 0;
	if (mod)
		*str++ = '-';
	else
		nb = -nb;
	while (pow--)
	{
		str[pow] = -(nb % 10) + '0';
		nb /= 10;
	}
	return (str - mod);
}
