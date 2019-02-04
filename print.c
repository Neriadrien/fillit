/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:00:41 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/04 15:59:01 by hthiessa         ###   ########.fr       */
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

void	print_and_exit(t_tetri *tetriminos, int nb_tetri, int actual_width)
{
	char	**printable_grid;
	int		i;
	int		j;

	if (!(printable_grid = malloc(actual_width * sizeof(*printable_grid))))
		exit(1); // TODO free
	i = 0;
	while (i < actual_width)
	{
		if (!(printable_grid[i] = ft_strnew(actual_width + 1)))
			exit (1); // TODO free
		ft_memset(printable_grid[i], '.', actual_width);
		printable_grid[i][actual_width] = '\n';
		i++;
	}
	i = 0;
	while (i < nb_tetri)
	{
		j = 0;
		while (j < 4)
		{
			printable_grid[tetriminos[i].type->points[j].y + tetriminos[i].position.y
				][tetriminos[i].type->points[j].x + tetriminos[i].position.x
					] = 'A' + i;
			j++;
		}
		i++;
	}
	print_grid(printable_grid, actual_width);
	//free
	exit(0);
}

void	print_tab_short_int(int id, short int*tab)
{
	for (int index = 0; index < 16; index++)
	{
		printf("[%d] %3d|"SHORT_TO_BINARY_PATTERN"\n",
			   id, index, SHORT_TO_BINARY(tab[index]));
	}
}
