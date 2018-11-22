/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:26:47 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/09 17:27:12 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *c_s1 = s1;
	const unsigned char *c_s2 = s2;

	if (n != 0)
		while (n--)
			if (*c_s1++ != *c_s2++)
				return (*--c_s1 - *--c_s2);
	return (0);
}
