/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:09:12 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/22 15:26:12 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_buff		*get_next_line_buff(const int fd)
{
	static t_buff	buff[2147483648];

	return (buff + fd);
}

static	int	read_next_buff(const int fd, char **line, int len)
{
	t_buff *const	rbuff = get_next_line_buff(fd);
	char			buff[BUFF_SIZE];
	int				r;
	int				ret;
	char			*res;

	res = buff;
	if ((r = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	else if (r == 0 && len == 0)
		return (0);
	else if (r == 0 || (res = ft_memchr(buff, '\n', r)))
	{
		rbuff->len = r ? r - (res - buff) - 1 : 0;
		ft_memcpy(rbuff->data, res + (ret = 1), rbuff->len);
		if (!(*line = malloc(len + (res - buff) + 1)))
			return (-1);
		(*line)[len + res - buff] = 0;
		r -= r ? rbuff->len + 1 : 0;
	}
	else
		ret = read_next_buff(fd, line, len + r);
	if (*line && ret == 1)
		ft_memcpy(*line + len, buff, r);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	t_buff	*buff;
	t_buff	copy;
	char	*res;
	int		len;
	int		ret;

	if (!line || fd < 0)
		return (-1);
	buff = get_next_line_buff(fd);
	if ((res = ft_memchr(buff->data, '\n', buff->len)))
	{
		len = res - buff->data;
		if (!(*line = malloc(len + 1)))
			return (-1);
		(*line)[len] = 0;
		ft_memcpy(*line, buff->data, len);
		ft_memcpy(buff->data, res + 1, buff->len - len);
		buff->len -= len + 1;
		return (1);
	}
	copy = *buff;
	ret = read_next_buff(fd, line, copy.len);
	if (*line)
		ft_memcpy(*line, copy.data, copy.len);
	return (ret ? ret : copy.len != 0);
}
