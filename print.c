/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:00:41 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 16:50:17 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "print.h"
#include "libft.h"

#include <stdio.h>

void	print_grid(char *grid[], int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putstr(grid[i]);
		i++;
	}
}

void	fill_grid(char **printable_grid, t_tetri *tetriminos, int nb_tetri)
{
	int i;
	int j;

	i = 0;
	while (i < nb_tetri)
	{
		j = 0;
		while (j < 4)
		{
			printable_grid[tetriminos[i].type->points[j].y + tetriminos[i].pos.y
				][tetriminos[i].type->points[j].x + tetriminos[i].pos.x
					] = 'A' + i;
			j++;
		}
		i++;
	}
}

void	print_and_exit(t_tetri *tetriminos, int nb_tetri, int actual_width)
{
	char	**printable_grid;
	int		i;

	if (!(printable_grid = malloc(actual_width * sizeof(*printable_grid))))
		exit(1);
	i = 0;
	while (i < actual_width)
	{
		if (!(printable_grid[i] = ft_strnew(actual_width + 1)))
			exit(1);
		ft_memset(printable_grid[i], '.', actual_width);
		printable_grid[i][actual_width] = '\n';
		i++;
	}
	fill_grid(printable_grid, tetriminos, nb_tetri);
	print_grid(printable_grid, actual_width);
	exit(0);
}

/*
** TODO Free avant chaque exit
*/
