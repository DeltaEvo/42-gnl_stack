/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:19:37 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/07 14:07:23 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*str;

	len = ft_strlen(src);
	if (!(str = malloc(len + 1)))
		return (NULL);
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (str - len);
}
