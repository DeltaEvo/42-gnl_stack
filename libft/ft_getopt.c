/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:02:16 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/12 10:33:37 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*g_ft_optarg;
char	g_ft_optopt = 1;
int		g_ft_optind = 1;
int		g_ft_opterr = 1;

int	ft_getopt(int argc, char *const argv[], const char *optstring)
{
	const char	*str = argv[g_ft_optind];

	if (g_ft_optind >= argc)
		return (-1);
	g_ft_optind++;
	if (*str++ != '-')
		return (-1);
	if (*str == '-')
		return (-1);
	optstring = ft_strchr(optstring, *str++);
	g_ft_optopt = optstring ? *optstring : '?';
	if (g_ft_opterr && g_ft_optopt == '?')
		ft_putf_fd(2, "%s: illegal option -- %c\n", argv[0], str[-1]);
	if (!optstring || optstring[1] != ':')
		return (g_ft_optopt);
	if (g_ft_optind >= argc)
		return (':');
	g_ft_optarg = argv[g_ft_optind++];
	return (g_ft_optopt);
}
