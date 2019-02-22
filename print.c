/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:00:41 by hthiessa          #+#    #+#             */
/*   Updated: 2019/02/22 18:43:49 by hbode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "print.h"
#include "libft/libft.h"

void	error(int fd)
{
	ft_putendl_fd("error", 1);
	if (fd >= 0)
		close(fd);
	exit(1);
}

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

void	free_printable_grid(char **printable_grid, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		free(printable_grid[index]);
		index++;
	}
	free(printable_grid);
}

void	print_and_exit(t_solve_data *data)
{
	char	**printable_grid;
	int		index;

	if (!(printable_grid = malloc(data->size * sizeof(*printable_grid))))
		exit(1);
	index = 0;
	while (index < data->size)
	{
		if (!(printable_grid[index] = ft_strnew(data->size + 1)))
		{
			free_printable_grid(printable_grid, index + 1);
			exit(1);
		}
		ft_memset(printable_grid[index], '.', data->size);
		printable_grid[index][data->size] = '\n';
		index++;
	}
	fill_grid(printable_grid, data->ltetri, data->nb_tetri);
	print_grid(printable_grid, data->size);
	free_printable_grid(printable_grid, data->size);
	exit(0);
}
