/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:09:12 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/14 10:17:20 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

t_buff		*get_next_line_buff(const int fd)
{
	static t_buff	buff;

	return (&buff);
}

static	int	read_next_buff(const int fd, char **line, int len)
{
	t_buff	*rbuff;
	char	buff[BUFF_SIZE];
	int		r;
	char	*res;
	int		ret;

	rbuff = get_next_line_buff(fd);
	res = buff;
	r = read(fd, buff, BUFF_SIZE);
	if (r < 0)
		ret = -1;
	else if (r == 0 || (res = memchr(buff, '\n', r)))
	{
		ret = r != 0;
		rbuff->len = r ? r - (res - buff) - 1 : 0;
		memcpy(rbuff->data, res + 1, rbuff->len);
		*line = malloc(len + (res - buff) + 1);
		(*line)[len + res - buff] = 0;
		r -= r ? rbuff->len + 1 : 0;
	}
	else
		ret = read_next_buff(fd, line, len + r);
	memcpy(*line + len, buff, r > 0 ? r : 0);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	t_buff	*buff;
	t_buff	copy;
	char	*res;
	int		len;
	int		r;

	buff = get_next_line_buff(fd);
	if ((res = memchr(buff->data, '\n', buff->len)))
	{
		len = res - buff->data;
		*line = malloc(len + 1);
		(*line)[len] = 0;
		memcpy(*line, buff->data, len);
		buff->len -= len;
		memcpy(buff->data, res + 1, buff->len);
		return (1);
	}
	else
	{
		copy = *buff;
		r = read_next_buff(fd, line, copy.len);
		memcpy(*line, copy.data, copy.len);
		return (r);
	}
}
