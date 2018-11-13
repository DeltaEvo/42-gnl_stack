/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:09:53 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/14 09:42:10 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5

int				get_next_line(const int fd, char **line);

typedef struct	s_buff {
	char	data[BUFF_SIZE];
	int		len;
}				t_buff;

t_buff			*get_next_line_buff(const int fd);

#endif
