/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:49:08 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 12:59:15 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	const char		*o_s = s;
	size_t			len;
	char			**res;
	char			*last;

	if (!s || !*s)
		return (!s ? NULL : ft_memalloc(sizeof(char **)));
	len = !(*s == c);
	while (*++s)
		if (s[-1] == c && *s != c)
			len++;
	if (!(res = malloc(len * sizeof(char **) + 1)))
		return (NULL);
	s = (char *)o_s;
	last = (char *)s;
	while (*++s)
		if (s[-1] != c && *s == c)
			*res++ = ft_strsub(last, 0, s - last);
		else if (s[-1] == c)
			last = (char *)s;
	if (s[-1] != c)
		*res++ = ft_strsub(last, 0, s - last);
	*res = 0;
	return (res - len);
}
