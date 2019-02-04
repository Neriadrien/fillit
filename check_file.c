/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:48:25 by hbode             #+#    #+#             */
/*   Updated: 2019/02/04 18:43:19 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "utils.h"
#include <stdio.h>

int		check_left(char *tetri, int i)
{
	if (i % 5 == 0)
		return (0);
	return (tetri[i - 1] == '#');
}

int		check_right(char *tetri, int i)
{
	if ((i % 5) - 3 == 0)
		return (0);
	return (tetri[i + 1] == '#');
}

int		check_top(char *tetri, int i)
{
	if (i / 5 == 0)
		return (0);
	return (tetri[i - 5] == '#');
}

int		check_bot(char *tetri, int i)
{
	if (i / 5 == 3)
		return (0);
	return (tetri[i + 5] == '#');
}

void	fill_grid(t_points *grid, int i, char *tetri)
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

int		check_connections(char *tetri)
{
	int		i;
	int		connections;

	i = 0;
	connections = 0;
	while (tetri[i] && i < 20)
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

int		check_tetri(char *tetri)
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
		return (1);
	return (0);
}

int		get_next_tetri(int fd, t_points *grid)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;

	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (check_tetri(buf) == 0 || check_connections(buf) == 0)
		{
			ft_putstr("wrong file");
			return (0);
		}
		fill_grid(grid, i, buf);
		i++;
	}
	return (i);
}

int		parse(char *file, t_points *grid)
{
	int		fd;
	int		count;
	int		i = 0;
	int		j = 0;

	fd = open(file, O_RDONLY);
	count = get_next_tetri(fd, grid);
	while (i < count)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d,%d\n", grid[i][j].x, grid[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	close(fd);
	return (1);
}
