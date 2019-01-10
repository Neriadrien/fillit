/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <hbode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:00:31 by hbode             #+#    #+#             */
/*   Updated: 2019/01/10 16:51:20 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strjoin_f(char **s1, char *s2)
{
	char			*tmp;

	if (!*s1 && !s2)
		return (-1);
	if (!(tmp = ft_strjoin(*s1, s2)))
		return (-1);
	ft_strdel(s1);
	*s1 = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		buf[OPEN_MAX][BUFF_SIZE];
	int				index;
	int				result;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, buf[fd], 0) < 0)
		return (-1);
	*line = ft_strnew(0);
	while (1)
	{
		if ((index = ft_strchri(buf[fd], '\n')) != -1)
		{
			buf[fd][index] = '\0';
			if (ft_strjoin_f(line, buf[fd]) == -1)
				return (-1);
			ft_strncpy(buf[fd], &buf[fd][index + 1], BUFF_SIZE);
			return (1);
		}
		if (ft_strjoin_f(line, buf[fd]) == -1)
			return (-1);
		if ((result = read(fd, buf[fd], BUFF_SIZE)) == -1)
			return (-1);
		buf[fd][result] = '\0';
		if (result == 0)
			return ((**line == 0) ? 0 : 1);
	}
}
