/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:31:33 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 15:34:10 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putf(char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	ft_putf_va(STDOUT_FILENO, fmt, args);
	va_end(args);
}
