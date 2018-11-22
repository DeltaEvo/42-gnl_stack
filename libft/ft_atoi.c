/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:40:16 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/09 17:32:55 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LONG_MAX 9223372036854775807

int	ft_atoi(const char *str)
{
	long	result;
	char	mod;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	result = 0;
	mod = *str == '-' || *str == '+' ? *str++ == '-' : 0;
	while (*str >= '0' && *str <= '9')
		if (result > LONG_MAX / 10)
			return (mod ? 0 : -1);
		else
			result = result * 10 + *str++ - '0';
	return ((int)(mod ? -result : result));
}
