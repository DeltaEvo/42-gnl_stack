/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:10:53 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 15:11:08 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr_fd(int n, int fd)
{
	char		buf[11];
	int			i;
	const char	neg = n < 0;

	if (!neg)
		n = -n;
	i = sizeof(buf);
	if (!n)
		buf[--i] = '0';
	else
		while (n)
		{
			buf[--i] = -(n % 10) + '0';
			n /= 10;
		}
	if (neg)
		buf[--i] = '-';
	write(fd, buf + i, sizeof(buf) - i);
}
