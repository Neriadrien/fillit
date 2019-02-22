/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:48:25 by hbode             #+#    #+#             */
/*   Updated: 2019/02/22 16:59:42 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "utils.h"
#include "print.h"

static void		fill_grid(t_points *grid, int i, char *tetri)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (tetri[j])
	{
		if (tetri[j] == '#')
		{
			grid[i][count].x = j % 5;
			grid[i][count].y = j / 5;
			count++;
		}
		j++;
	}
}

static int		check_connections(char *tetri)
{
	int		i;
	int		connections;

	i = 0;
	connections = 0;
	while (i < 20 && tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (check_left(tetri, i) == 1)
				connections++;
			if (check_right(tetri, i) == 1)
				connections++;
			if (check_top(tetri, i) == 1)
				connections++;
			if (check_bot(tetri, i) == 1)
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	return (0);
}

static int		check_tetri(char *tetri)
{
	int		i;
	int		points;
	int		diese;
	int		line;

	i = 0;
	points = 0;
	diese = 0;
	line = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.')
			points++;
		else if (tetri[i] == '#')
			diese++;
		else if (tetri[i] == '\n' && (i % 5 == 4 || i == 20))
			line++;
		else
			return (0);
		i++;
	}
	if ((i == 21 && points == 12 && diese == 4 && line == 5) ||
		(i == 20 && points == 12 && diese == 4 && line == 4))
		return (i);
	return (0);
}

static int		get_next_tetri(int fd, t_points *grid)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;
	int		nb_char;

	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		nb_char = check_tetri(buf);
		if (ret < 0 || nb_char == 0 || check_connections(buf) == 0
			|| ft_memchr(buf, '\0', ret) || i >= 26)
			error(fd);
		fill_grid(grid, i, buf);
		i++;
	}
	if (i == 0 || nb_char != 20)
		error(fd);
	return (i);
}

int				parse(char *file, t_points *grid)
{
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(fd);
	count = get_next_tetri(fd, grid);
	set_all_left(grid, count);
	close(fd);
	return (count);
}
