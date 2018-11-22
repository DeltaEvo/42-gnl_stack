/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:05:44 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 14:58:18 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *c, size_t c_size)
{
	t_list	*el;

	if (!(el = malloc(sizeof(t_list))))
		return (NULL);
	*el = (t_list) {
		.content = c_size && c ? ft_memcpy(malloc(c_size), c, c_size) : NULL,
		.content_size = c ? c_size : 0
	};
	return (el);
}
