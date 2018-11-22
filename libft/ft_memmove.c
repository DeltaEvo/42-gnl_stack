/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:25:45 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/09 17:27:39 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*c_src = src;
	char		*c_dst;

	c_dst = dst;
	if (dst > src)
		while (len--)
			c_dst[len] = c_src[len];
	else
		while (len--)
			*c_dst++ = *c_src++;
	return (dst);
}
