/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:42:13 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 14:53:49 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	const t_list	*start = lst ? f(lst) : 0;
	t_list			*new;

	if (!start)
		return (0);
	new = (t_list *)start;
	lst = lst->next;
	while (lst)
	{
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	return ((t_list *)start);
}
