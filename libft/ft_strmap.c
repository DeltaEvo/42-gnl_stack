/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:31:18 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 09:25:01 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new;
	char		*tmp;

	if (!s || !(new = malloc(ft_strlen(s) + 1)))
		return (NULL);
	tmp = new;
	while (*s)
		*tmp++ = f(*s++);
	*tmp = 0;
	return (new);
}
