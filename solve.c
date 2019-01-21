/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthiessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:45 by hthiessa          #+#    #+#             */
/*   Updated: 2019/01/21 17:59:10 by hthiessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "solve.h"
#include "libft/libft.h"

int		sqrt_aprox(int nb)
{
	int	i;

	i = 0;
	while (i < 47000)
	{
		if ((i * i) >= nb)
			return (i);
		i++;
	}
	return (i);
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

void	print_and_exit(t_tetri *tetriminos, int nb_tetri,
					   int actual_width)
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

void	solve_and_print(t_tetri *tetriminos, int nb_tetri)
{
	t_grid	grid;
	int		actual_width;

	ft_memset(&grid, 0, sizeof(grid));
	actual_width = sqrt_aprox(nb_tetri * 4);
	while (actual_width <= MAX_WIDTH)
	{
		solve_and_print_rec(0, tetriminos, grid, nb_tetri, actual_width);
		actual_width++;
	}
	ft_putstr_fd("Error, max width of grid reached\n", 2);
	exit(1);
	//TODO Error
}

void	solve_and_print_rec(int index, t_tetri *tetriminos, t_grid grid,
							int nb_tetri, int actual_width)
{
	t_tetri		*tetri;
	long int	*grid_for_cmp;

	if (index == nb_tetri)
		print_and_exit(tetriminos, nb_tetri, actual_width);
	tetri = &tetriminos[index];
	tetri->position.y = 0;
	while (tetri->position.y <= actual_width - tetri->type->height)
	{
		grid_for_cmp = (long*)(grid + tetri->position.y);
		tetri->position.x = 0;
		while (tetri->position.x <= actual_width - tetri->type->width)
		{
			if (tetri->type->cache[tetri->position.x] == 0)
				tetri->type->cache[tetri->position.x] =
					tetri->type->cache[0] >> tetri->position.x;
			if ((*grid_for_cmp & tetri->type->cache[tetri->position.x]) == 0)
			{
				*grid_for_cmp ^= tetri->type->cache[tetri->position.x];
				solve_and_print_rec(index + 1, tetriminos, grid, nb_tetri, actual_width);
				*grid_for_cmp ^= tetri->type->cache[tetri->position.x];
			}
			tetri->position.x++;
		}
		tetri->position.y++;
	}
}
