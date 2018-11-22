/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:53:00 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/09 17:33:35 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	char_to_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (-1);
}

int			ft_atoi_base(const char *str, char base)
{
	int		res;
	char	mod;
	char	current;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	res = 0;
	mod = (*str == '-' || *str == '+') && *str++ == '-';
	while ((current = char_to_num(*str++)) != -1 && current <= base)
		res = res * base + current;
	return (mod ? -res : res);
}
