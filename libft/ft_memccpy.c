/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:47:06 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/09 17:25:39 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*c_src = src;
	unsigned char		*c_dst;
	size_t				i;

	i = 0;
	c_dst = dst;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if (c_src[i] == ((unsigned char)c))
			return (dst + i + 1);
		i++;
	}
	return (0);
}
